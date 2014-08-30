// -*- C++ -*-
#ifndef MENUMODE_HEADER
#define MENUMODE_HEADER

#include "common.h"

class Application;
class Lcd;

class MenuMode {
private:
	enum {
		MENU_TIME_SET = 0,
		MENU_EXIT     = 1,
		MENU_SIZE     = 2,
	};

	Application* app;
	Lcd* lcd;
	int menuIndex;
	bool dirty;

public:
	void init( Application* app_, Lcd* lcd_ );
	void reset();
	void draw();
	void onButtonPressed(ButtonType button);
};


#endif
