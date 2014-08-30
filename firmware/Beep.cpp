#include "Beep.h"

const int CHECK_PERIOD = 40; // micro sec
const int TONE_PERIOD  = 1800; // micro sec
//const int TONE_PERIOD  = 8000; // micro sec
const int PLAY_PERIOD  = 1000 * 50; // micro sec

/**
 * <!--  Beep():  -->
 */
Beep::Beep(PinName outPin) 
	:
	pwmOut(outPin) {
	count = 0;
	totalCount = 0;
}

/**
 * <!--  check():  -->
 */
void Beep::check() {
	count += CHECK_PERIOD;
	totalCount += CHECK_PERIOD;

	if( count < TONE_PERIOD / 2 ) {
		pwmOut.write(0.0f);
	} else {
		pwmOut.write(1.0f);
	}
	
	if( count > TONE_PERIOD ) {
		count = 0;
	}
	
	if( totalCount > PLAY_PERIOD ) {
		soundTicker.detach();
		totalCount = 0;
		count = 0;
	} 
}

/**
 * <!--  play():  -->
 */
void Beep::play() {
	if( count > 0 ) {
		return;
	}
	
	count = 0;
	totalCount = 0;
	soundTicker.attach_us(this, &Beep::check, CHECK_PERIOD);
}
