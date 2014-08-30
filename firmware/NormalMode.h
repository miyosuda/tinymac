// -*- C++ -*-
#ifndef NORMALMODE_HEADER
#define NORMALMODE_HEADER

#include "common.h"

class Application;
class Lcd;

class NormalMode {
private:
	Application* app;
	Lcd* lcd;
	int lastDrawnTime;

public:
	void init( Application* app_, Lcd* lcd_ );
	void reset();
	void draw(int time);
	void onButtonPressed(ButtonType button);
};

#endif
