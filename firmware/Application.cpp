#include "Application.h"
#include "data.h"

/**
 * <!--  Application():  -->
 */
Application::Application() 
	:
	beep(dp1)
{
	mode = MODE_NORMAL;
}

/**
 * <!--  init():  -->
 */
void Application::init( LcdSetting setting ) {
	lcd = new Lcd(setting);
	
	lcd->init();
	lcd->clear();

	tick = 0;
	time = 0;
	
	normalMode.init(this, lcd);
	menuMode.init(this, lcd);
	timeSetMode.init(this, lcd);
}

/**
 * <!--  process():  -->
 */
void Application::process() {
	if( mode == MODE_NORMAL ) {
		normalMode.draw(time);
	} else if( mode == MODE_MENU ) {
		menuMode.draw();
	} else {
		timeSetMode.draw();
	}
}

/**
 * <!--  timerUpdated():  -->
 */
void Application::timerUpdated() {
	tick++;
	if( tick >= 10 ) {
		tick = 0;
		time++;
		if(time >= (24 * 60 * 60)) {
			time = 0;
		}
	}
}

/**
 * <!--  onButtonPressed():  -->
 */
void Application::onButtonPressed(ButtonType button) {
	beep.play();

	if( mode == MODE_NORMAL ) {
		normalMode.onButtonPressed( button );
	} else if( mode == MODE_MENU ) {
		menuMode.onButtonPressed( button );
	} else if( mode == MODE_TIME_SET ) {
		timeSetMode.onButtonPressed( button );
	}
}

/**
 * <!--  changeMode():  -->
 */
void Application::changeMode(ModeType newMode) {
	if( newMode == MODE_NORMAL ) {
		normalMode.reset();
	} else if( newMode == MODE_MENU ) {
		menuMode.reset();
	} else if( newMode == MODE_TIME_SET ) {
		timeSetMode.reset(time);
	}
	
	mode = newMode;
}

/**
 * <!--  setTime():  -->
 */
void Application::setTime(int time_) {
	time = time_;
}
