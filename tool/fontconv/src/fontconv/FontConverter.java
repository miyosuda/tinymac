package fontconv;

import java.awt.image.BufferedImage;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

import javax.imageio.ImageIO;

public class FontConverter {
	// whether LCD is vertically inverted or not
	private static boolean VERT_INVERTING = true;

	private static final int ASCII_CHAR_SIZE = 95;
	private static final int STRIDE_Y = 14;

	private int calcSpan(BufferedImage image, int charIndex) {
		int posX = 0;
		int posY = (charIndex % 16) * STRIDE_Y;
		for (int i = 0; i < 16; ++i) {
			int x = posX + i;
			int c = image.getRGB(x, posY) & 0xffffff;
			if (c == 0xff0000) {
				return i;
			}
		}
		return -1;
	}

	private int getCharVerticalData(BufferedImage image, int charIndex, int index) {
		int ret = 0;
		int posX = index;
		int posY = (charIndex % 16) * STRIDE_Y;
		for (int j = 0; j < 8; ++j) {
			int y = posY + j;
			int c = image.getRGB(posX, y) & 0xffffff;
			if (c == 0x000000) {
				ret |= (1 << j);
			}
		}
		return ret;
	}

	private int flipByte(int a) {
		return Integer.reverse(a) >>> 24;
	}

	private void process(String outputFileName, boolean vertInverting) throws IOException {
		CharInfo[] infos = new CharInfo[ASCII_CHAR_SIZE];

		for (int i = 0; i < 6; ++i) {
			String inputFileName = "data/line" + i + ".png";
			BufferedImage image = ImageIO.read(new File(inputFileName));

			int blockCharSize = 16;
			if (i == 5) {
				blockCharSize = 15;
			}

			for (int j = 0; j < blockCharSize; ++j) {
				int span = calcSpan(image, j);
				int charIndex = 16 * i + j;

				CharInfo info = new CharInfo(charIndex, span);
				for (int k = 0; k < span; ++k) {
					int verticalCharData = getCharVerticalData(image, charIndex, k);
					info.setVerticalData(k, verticalCharData);
				}
				infos[charIndex] = info;
			}
		}

		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				new FileOutputStream(outputFileName), "UTF-8")));

		// span
		writeSpan(out, infos);

		// data width
		writeWidth(out, infos);

		// data
		int count = writeData(out, infos, vertInverting);

		System.out.println("data size=" + count + "byte");

		out.close();
	}

	private void writeSpan(PrintWriter out, CharInfo[] infos) {
		out.println("const char FONT_DATA_SPAN[95] = {");
		for (int i = 0; i < infos.length; ++i) {
			int span = infos[i].getSpan();
			String str = String.format("0x%x", span);
			out.println("\t" + str + ", // " + infos[i].getCharString());
		}
		out.println("};");
	}

	private void writeWidth(PrintWriter out, CharInfo[] infos) {
		out.println("");
		out.println("const char FONT_DATA_WIDTH[95] = {");
		for (int i = 0; i < infos.length; ++i) {
			int width = infos[i].getDataWidth();
			String str = String.format("0x%x", width);
			out.println("\t" + str + ", // " + infos[i].getCharString());
		}
		out.println("};");
	}

	private int writeData(PrintWriter out, CharInfo[] infos, boolean vertInverting) {
		out.println("");
		out.println("const char FONT_DATA[] = {");
		int count = 0;
		for (int i = 0; i < infos.length; ++i) {
			CharInfo info = infos[i];
			int realWidth = info.getDataWidth();
			for (int j = 0; j < realWidth; ++j) {
				int data;
				if (vertInverting) {
					data = info.data[realWidth - 1 - j];
					data = flipByte(data);
				} else {
					data = info.data[j];
				}
				if (count % 8 == 0) {
					out.print("\t");
				}
				String str = String.format("0x%02x", data);
				out.print(str + ", ");
				if (count % 8 == 7) {
					out.print("\n");
				}
				count++;
			}
		}
		if (count % 8 != 0) {
			out.print("\n");
		}
		out.println("};");
		return count;
	}

	public static void main(String[] args) {
		FontConverter app = new FontConverter();
		String outputFileName = "data/font.txt";
		try {
			app.process(outputFileName, VERT_INVERTING);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
