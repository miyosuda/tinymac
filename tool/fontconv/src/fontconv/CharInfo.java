package fontconv;

public class CharInfo {
	public int index;
	public int[] data;
	
	public CharInfo(int index, int span) {
		this.index = index;
		data = new int[span];
	}
	
	public void setVerticalData(int vertIndex, int d) {
		data[vertIndex] = d;
	}
	
	public int getSpan() {
		return data.length;
	}
	
	public int getDataWidth() {
		int ret = 0;
		for(int i=0; i<data.length; ++i) {
			if( data[i] != 0 ) {
				ret = i+1;
			}
		}
		return ret;
	}
	
	public String getCharString() {
		char ch = (char)(index+32);
		if( ch == ' ' ) {
			return "space";
		} else if( ch == '\\' ) {
			return "back slash";
		}
		return "" + ch;
	}
}
