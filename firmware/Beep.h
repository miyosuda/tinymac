// -*- C++ -*-
#ifndef BEEP_HEADER
#define BEEP_HEADER

#include "mbed.h"

class Beep {
private:
	PwmOut pwmOut;
	Ticker soundTicker;
	volatile int count;
	volatile int totalCount;

	void check();

public:
	Beep(PinName outPin);
	void play();
};

#endif
