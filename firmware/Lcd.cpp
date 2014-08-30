#include "Lcd.h"
#include "mbed.h"

/**
 * <!--  Lcd():  -->
 */
Lcd::Lcd(LcdSetting setting) {
	// SPI
	spi = new SPI(setting.mosi, NC, setting.sclk);
	// 8bit, Clock active high, Clock in phase with data
	spi->format(LCD_SPI_BITS, LCD_SPI_MODE);
	// 2MHz
	spi->frequency(LCD_FREQ);
	
	// control pins
	pinRST = new DigitalOut(setting.rst);
	pinSCE = new DigitalOut(setting.sce);
	pinDC  = new DigitalOut(setting.dc);
	
	functionSet.V  = CMD_FS_HORIZONTAL_MODE; // Horizontal addressing mode (V=0)
	functionSet.H  = CMD_FS_EXTENDED_MODE;
	functionSet.PD = CMD_FS_ACTIVE_MODE;
}

/**
 * <!--  ~Lcd():  -->
 */
Lcd::~Lcd() {
	shutdown();
	
	delete spi;
	delete pinRST;
	delete pinSCE;
	delete pinDC;
}

/**
 * <!--  init():  -->
 */
void Lcd::init() {
	reset();
	pinSCE->write(0);	 // Chip Select to low
	
	setCommandMode();
	
	functionSet.V  = CMD_FS_HORIZONTAL_MODE;
	functionSet.H  = CMD_FS_EXTENDED_MODE;
	functionSet.PD = CMD_FS_ACTIVE_MODE;
	
	// change to EXTENDED CMD mode(H=1)
	sendFunction( createFunctionChar() );   // Extended CMD set
	sendFunction( CMD_VOP_7V38 );		// Vop
	sendFunction( CMD_TC_TEMP_2 );		// Temp
	sendFunction( CMD_BI_MUX_48 );		// Bias
	
	// change to BASIC CMD mode (H=0)
	functionSet.H = CMD_FS_BASIC_MODE;
	sendFunction( createFunctionChar() );   // Basic CMD set
	sendFunction( CMD_DC_NORMAL_MODE );		// Display Mode
	
	// to Data Mode
	setDataMode();
	
	clear();
}

/**
 * <!--  createFunctionChar():  -->
 */
char Lcd::createFunctionChar() {
	return ( 0x20 | functionSet.PD | functionSet.V | functionSet.H );
}

/**
 * <!--  reset():  -->
 */
void Lcd::reset() {
	pinRST->write(0);	// Reset to low
	pinRST->write(1);	// Reset to high
}

/**
 * <!--  clear():  -->
 */
void Lcd::clear() {
	for(int i=0; i<504; i++) {
		spi->write(0x00);
	}
}

/**
 * <!--  shutdown():  -->
 */
void Lcd::shutdown() {
	clear();

	setCommandMode();
	sendFunction( CMD_DC_CLEAR_DISPLAY );
	
	functionSet.PD = CMD_FS_POWER_DOWN_MODE;
	sendFunction( createFunctionChar() );
}

/**
 * <!--  setXY():  -->
 */
void Lcd::setXY(char x, char y) {
	// x=0~83, y=0~5
	if( (x > 83) || (y > 5) ) {
		return;
	}

	setCommandMode();
	sendFunction( x | 0x80 );
	sendFunction( y | 0x40 );
	setDataMode();
}

/**
 * <!--  getFontDataPos():  -->
 */
static int getFontDataPos(char ch) {
	int index = ch-32;
	int pos = 0;
	for(int i=0; i<index; ++i) {
		int width = FONT_DATA_WIDTH[i];
		pos += width;
	}
	return pos;
}

/**
 * <!--  getFontWidth():  -->
 */
static inline int getFontWidth(char ch) {
	return FONT_DATA_WIDTH[ch-32];
}

/**
 * <!--  getFontSpan():  -->
 */
static inline int getFontSpan(char ch) {
	return FONT_DATA_SPAN[ch-32];
}

/**
 * <!--  drawStringSub():  -->
 */
void Lcd::drawStringSub(const char* s, int length, int shiftY, bool invert) {
	for(int i=0; i<length; ++i) {
		char ch = s[length-1-i];
		int span = getFontSpan(ch);
		int width = getFontWidth(ch);
		int dataPos = getFontDataPos(ch);

		if( i != 0 ) {
			int gapWidth = span - width;
			unsigned char gapChar;
			if( invert ) {
				gapChar = 0xff;
				if( shiftY > 0 ) {
					gapChar = gapChar << shiftY;
				} else if( shiftY < 0 ) {
					gapChar = gapChar >> (8+shiftY);
				}
			} else {
				gapChar = 0x00;
			}
			
			for(int j=0; j<gapWidth; ++j) {
				sendDrawData(gapChar);
			}
		}
		
		for(int j=0; j<width; ++j) {
			if( j < width ) {
				unsigned char d = FONT_DATA[dataPos+j];
				if( invert ) {
					d = ~d;
				}
				if( shiftY > 0 ) {
					d = d << shiftY;
				} else if( shiftY < 0 ) {
					d = d >> (8+shiftY);
				}
				sendDrawData(d);
			}
		}
	}
}

/**
 * <!--  drawString():  -->
 */
void Lcd::drawString(const char* s, char x, char y, bool invert) {
	y = 40 - y;
	int stringWidth = calcStringWidth(s);
	x = LCD_X_MAX - (x + stringWidth);
	
	char blockY = y / 8;
	int shiftY = ((int)y) % 8;

	if( shiftY == 0 ) {
		setXY(x, blockY);
		
		// normal
		int length = strlen(s);
		drawStringSub(s, length, 0, invert);

	} else {
		// with shifting
		int length = strlen(s);

		setXY(x, blockY);
		drawStringSub(s, length, shiftY, invert);
		
		setXY(x, blockY+1);
		drawStringSub(s, length, -shiftY, invert);
	}

	// ADHOC. without this nop, last sendDrawData call is not drawn somehow.
	sendNop();
}

/**
 * <!--  drawImage():  -->
 */
void Lcd::drawImage( ImageInfo& info, const char* data ) {
	int count = 0;
	for(int j=0; j<info.blockHeight; ++j) {
		setXY( info.left, info.blockTop+j );
		for(int i=0; i<info.width; ++i) {
			sendDrawData( data[count] );
			count++;
		}
	}
	
	// ADHOC. without this nop, last sendDrawData call is not drawn somehow.
	sendNop();
}

/**
 * <!--  calcStringWidth():  -->
 */
int Lcd::calcStringWidth( const char* s, bool includeTailSpace ) {
	int length = strlen(s);
	int stringWidth = 0;
	for(int i=0; i<length; ++i) {
		char ch = s[i];
		if( i == length-1 && !includeTailSpace ) {
			stringWidth += getFontWidth(ch);
		} else {
			stringWidth += getFontSpan(ch);
		}
	}
	return stringWidth;
}
