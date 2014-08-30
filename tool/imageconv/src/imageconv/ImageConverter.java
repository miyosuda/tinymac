package imageconv;

import java.awt.image.BufferedImage;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

import javax.imageio.ImageIO;

public class ImageConverter {
	// whether LCD is vertically inverted or not
	private static boolean VERT_INVERTING = true;
	
	private int getVerticalBit(boolean buf[], int x, int y, int w) {
		int ret = 0;
		for (int j = 0; j < 8; ++j) {
			int py = y + j;
			if (buf[w * py + x]) {
				ret |= (1 << j);
			}
		}
		return ret;
	}

	private boolean[] flipData(boolean[] buf) {
		int size = buf.length;
		boolean newBuf[] = new boolean[size];
		for(int i=0; i<size; ++i) {
			newBuf[i] = buf[size-1-i];
		}
		return newBuf;
	}

	private boolean[] getImageBuffer(BufferedImage image) {
		int width = image.getWidth();
		int height = image.getHeight();

		boolean[] buf = new boolean[width * height];

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int c = image.getRGB(x, y);
				int a = (c & 0xff000000) >> 24;
				if (a == 0) {
					// set no pixel if transparent
					buf[y * width + x] = false;
				} else {
					// normal
					int rgb = c & 0xffffff;
					buf[y * width + x] = (rgb == 0);
				}
			}
		}
		return buf;
	}

	public void process(String inputFileName, String outputFileName, boolean vertIverting) throws IOException {
		File inputFile = new File(inputFileName);
		String baseName = Util.getBaesName(inputFile.getName());
		BufferedImage image = ImageIO.read(inputFile);

		int width = image.getWidth();
		int height = image.getHeight();

		boolean[] buf = getImageBuffer(image);
		if( vertIverting ) {
			buf = flipData(buf);
		}

		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				new FileOutputStream(outputFileName), "UTF-8")));

		int left = width; // left edge
		int right = 0; // right edge

		int top = height; // top edge
		int bottom = 0; // bottom edge

		for (int j = 0; j < height; ++j) {
			for (int i = 0; i < width; ++i) {
				boolean b = buf[j * width + i];
				if (!b) {
					continue;
				}
				if (i < left) {
					left = i;
				} else if (i > right) {
					right = i;
				}
				if (j < top) {
					top = j;
				} else if (j > bottom) {
					bottom = j;
				}
			}
		}

		int frameWidth = right - left + 1;
		int frameLeft = left;
		int frameTop = (top / 8) * 8;
		int frameBottom = ((bottom / 8) + 1) * 8;

		int frameBlockTop = frameTop / 8;
		int frameBlockHeight = (frameBottom - frameTop) / 8;

		// out.println("// left, width, block-top, block-height");
		out.println("static ImageInfo " + baseName + "ImageInfo = {" + frameLeft + ", " + frameWidth + ", "
				+ frameBlockTop + ", " + frameBlockHeight + "};");

		out.println("const char " + baseName + "ImageData[] = {");

		writeData(out, buf, width, frameWidth, frameLeft, frameBlockTop, frameBlockHeight);

		out.println("};");
		out.close();
	}

	private void writeData(PrintWriter out, boolean[] buf, int imageWidth, int frameWidth, int frameLeft,
			int frameBlockTop, int frameBlockHeight) {

		int count = 0;
		for (int j = 0; j < frameBlockHeight; ++j) {
			for (int i = 0; i < frameWidth; ++i) {
				if (count % 8 == 0) {
					out.print("\t");
				}
				int fx = i + frameLeft;
				int fy = (frameBlockTop + j) * 8;
				int value = getVerticalBit(buf, fx, fy, imageWidth);
				String str = String.format("0x%02x", value);
				out.print(str);
				out.print(",");
				if ((count % 8) == 7) {
					out.print("\n");
				}
				count++;
			}
		}
		if (count % 8 != 0) {
			out.print("\n");
		}
	}	
	
	public static String changeSuffixTo(String fileName, String newSuffix) {
		int point = fileName.lastIndexOf(".");
		if (point != -1) {
			return fileName.substring(0, point) + newSuffix;
		} else {
			return null;
		}
	}

	public static void main(String[] args) {
		ImageConverter app = new ImageConverter();

		File dir = new File("data");
	    File[] files = dir.listFiles();
	    for(File file : files ) {
			String inputFileName = file.getPath();
			if( !inputFileName.endsWith(".png") ) {
				continue;
			}
			System.out.println("file name=" + inputFileName);
			
			String outputFileName = changeSuffixTo(inputFileName, ".txt");
			try {
				app.process(inputFileName, outputFileName, VERT_INVERTING);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
