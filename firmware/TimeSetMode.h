// -*- C++ -*-
#ifndef TIMESETMODE_HEADER
#define TIMESETMODE_HEADER

#include "common.h"

class Application;
class Lcd;

class TimeSetMode {
private:
	typedef enum {
		STATE_HOUR   = 0,
		STATE_MIN    = 1,
		STATE_DECIDE = 2,
	} StateType;

	enum {
		DECIDE_OK   = 0,
		DECIDE_EDIT = 1,
		DECIDE_EXIT = 2,

		DECIDE_SIZE = 3,
	};
	
	// time in seconds
	Application* app;
	StateType state;
	int time;
	Lcd* lcd;
	int decideIndex;
	bool dirty;

	void drawArrow();
	void drawTime();
	void drawDecideMenu();
	
public:
	void init( Application* app_, Lcd* lcd_ );
	void reset( int time_ );
	void draw();
	void onButtonPressed(ButtonType button);
};


#endif
