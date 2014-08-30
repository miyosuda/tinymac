package imageconv;

public class Util {
	public static String getBaesName(String fileName) {
		int point = fileName.lastIndexOf(".");
		if (point != -1) {
			return fileName.substring(0, point);
		} else {
			return null;
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
}
