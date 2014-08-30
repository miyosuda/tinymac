// -*- C++ -*-
#ifndef LCD_HEADER
#define LCD_HEADER

// Command Function Set
#define CMD_FS_BASIC_MODE      0x00 // H=0
#define CMD_FS_EXTENDED_MODE   0x01 // H=1
#define CMD_FS_HORIZONTAL_MODE 0x00 // V=0
#define CMD_FS_VERTICAL_MODE   0x02 // V=1
#define CMD_FS_ACTIVE_MODE     0x00 // PD=0
#define CMD_FS_POWER_DOWN_MODE 0x04 // PD=1

// Command Basic (H = 0)
#define CMD_DC_CLEAR_DISPLAY   0x08 // display blank
#define CMD_DC_NORMAL_MODE     0x0C // normal mode
#define CMD_DC_FILL_DISPLAY    0x09 // all display segment on
#define CMD_DC_INVERT_VIDEO    0x0D // inverse video mode

// Command Extended (H = 1)
#define CMD_TC_TEMP_0          0x04 // temperature coefficient0
#define CMD_TC_TEMP_1          0x05 // temperature coefficient1
#define CMD_TC_TEMP_2          0x06 // temperature coefficient2
#define CMD_TC_TEMP_3          0x07 // temperature coefficient3
#define CMD_BI_MUX_24          0x15 // bias system
#define CMD_BI_MUX_48          0x13 // bias system
#define CMD_BI_MUX_100         0x10 // bias system
#define CMD_VOP_6V06           0xB2 // vop
#define CMD_VOP_7V38           0xC8 // vop

// LCD Characteristics
#define LCD_FREQ 2000000
#define LCD_SPI_MODE 0x01
#define LCD_SPI_BITS 0x08
#define LCD_X_MAX 84
#define LCD_Y_MAX 48

#include "mbed.h"
#include "font.h"

struct ImageInfo {
	char left;
	char width;
	char blockTop;
	char blockHeight;
};

struct LcdSetting {
	PinName mosi;
	PinName sclk;
	PinName dc;
	PinName sce;
	PinName rst;
};

struct LcdFunctionSet {
	char PD;
	char V;
	char H;
};

class Lcd {
private:
	LcdFunctionSet functionSet;
	DigitalOut* pinRST;
	DigitalOut* pinSCE;
	DigitalOut* pinDC;
	SPI* spi;
	
	char createFunctionChar();
	void reset();
	void drawStringSub(const char* s, int length, int shiftY, bool invert);
	
	// change to data mode
	inline void setDataMode() {
		pinDC->write(1);
	}
	// change to command mode
	inline void setCommandMode() {
		pinDC->write(0);
	}
	
	inline void sendDrawData(char data) {
		spi->write(data);
	}
	
	inline void sendFunction(char cmd) {
		// should be currently set as command mode
		spi->write(cmd);
	}

	inline void sendNop() {
		setCommandMode();
		sendFunction(0);
		setDataMode();
	}

public:
	Lcd(LcdSetting setting);
	~Lcd();
	
	void init();
	void clear();
	void shutdown();
	void setXY(char x, char y);
	void drawString(const char* s, char x, char y, bool invert=false);
	void drawImage(ImageInfo& info, const char* data);
	
	int calcStringWidth(const char* s, bool includeTailSpace=false);
};

#endif
