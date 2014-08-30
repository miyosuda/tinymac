#include "mbed.h"
#include "Lcd.h"

#include "common.h"
#include "data.h"
#include "Application.h"

static Ticker clockTimer;
static Ticker switchTimer;

static Application application;

class SwitchManager {
private:
	const static int SWITCH_SIZE = 5;
	const static int CHECK_COUNT = 3;

	typedef enum {
		NO_INPUT = 0,
		TRIGGERED = 1,
	} Phase;
	
	AnalogIn pin;
	int count;
	int lastValue;
	volatile int triggeredValue;
	volatile Phase phase;
	
public:
	SwitchManager(PinName pinName) 
		:
		pin(pinName),
		count(0),
		lastValue(0),
		triggeredValue(-1),
		phase(NO_INPUT) {
	}

	
	/**
	 * called priodically from interrupt.
	 */
	void check() {
		int value = (int)roundf(pin * (float)SWITCH_SIZE);
		
		if( phase == NO_INPUT ) {
			if( value == lastValue && value < SWITCH_SIZE ) {
				count++;
				if( count >= CHECK_COUNT ) {
					phase = TRIGGERED;
					triggeredValue = value;
					count = 0;
				}
			} else {
				count = 0;
			}
		} else if( phase == TRIGGERED ) {
			if( value == lastValue && value == SWITCH_SIZE ) {
				count++;
				if( count >= CHECK_COUNT ) {
					phase = NO_INPUT;
					count = 0;
				}
			} else {
				count = 0;
			}
		}
		
		lastValue = value;
	}
	
	int process() {
		int ret = -1;
		
		__disable_irq();
		
		if( triggeredValue >= 0 ) {
			ret = triggeredValue;
			triggeredValue = -1;
		}
		
		__enable_irq();
		return ret;
	}
};

static SwitchManager switchManager(dp13);

/**
 * <!--  clockHandler():  -->
 */
static void clockHandler() {
	application.timerUpdated();
}

/**
 * <!--  processSwitch():  -->
 */
static void processSwitch(int switchValue) {
	switch(switchValue) {
	case 0:
		application.onButtonPressed(BUTTON_OK);
		break;
	case 1:
		application.onButtonPressed(BUTTON_RIGHT);
		break;
	case 2:
		application.onButtonPressed(BUTTON_UP);
		break;
	case 3:
		application.onButtonPressed(BUTTON_DOWN);
		break;
	case 4:
		application.onButtonPressed(BUTTON_LEFT);
		break;
	default:
		break;
	}
}

/**
 * <!--  main():  -->
 */
int main() {
	LcdSetting setting;
	setting.sce  = dp17;
	setting.rst  = dp16;
	setting.dc   = dp15;
	setting.mosi = dp2;
	setting.sclk = dp6;
	
	application.init(setting);

	//clockTimer.attach( &clockHandler, 1.0 ); // 1sec
	clockTimer.attach( &clockHandler, 0.1 ); // 1sec
	switchTimer.attach( &switchManager, &SwitchManager::check, 0.01 ); // 10msec
	
	while( 1 ) {
		int switchValue = switchManager.process();
		if( switchValue >= 0 ) {
			processSwitch(switchValue);
		}
		application.process();
	}
}
