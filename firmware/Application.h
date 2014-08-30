// -*- C++ -*-
#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

#include "common.h"
#include "Lcd.h"
#include "NormalMode.h"
#include "MenuMode.h"
#include "TimeSetMode.h"
#include "Beep.h"

class Application {
private:
	Lcd* lcd;
	ModeType mode;
	NormalMode normalMode;
	MenuMode menuMode;
	TimeSetMode timeSetMode;
	int tick;
	int time;
	Beep beep;
	
public:
	Application();
	void init(LcdSetting setting);
	void process();
	void timerUpdated();
	void onButtonPressed(ButtonType button);
	void changeMode(ModeType mode_);
	void setTime(int time_);
};


#endif
