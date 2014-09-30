#include "NormalMode.h"
#include "Application.h"
#include "Lcd.h"
#include "data.h"

/**
 * <!--  init():  -->
 */
void NormalMode::init( Application* app_, Lcd* lcd_ ) {
	app = app_;
	lcd = lcd_;
	
	lastDrawnTime = -1;
}

/**
 * <!--  reset():  -->
 */
void NormalMode::reset() {
	lastDrawnTime = -1;
}

//static int unsigned count = 0;

/**
 * <!--  draw():  -->
 */
void NormalMode::draw(int time) {
	if( time == lastDrawnTime ) {
		return;
	}

	lcd->clear();
	/*
	if( (count / 50) % 20 == 0 ) {
		// blinking eye
		lcd->drawImage( face1ImageInfo, face1ImageData );
	} else {
		lcd->drawImage( face0ImageInfo, face0ImageData );
	}
	count++;
	*/
	
	lcd->drawImage( smileImageInfo, smileImageData );
	lcd->drawImage( balloonImageInfo, balloonImageData );
	//lcd->drawString("Hello!", 42, 20);
	
	int hour = time / 3600;
	int min = (time % 3600) / 60;
	bool isPM = false;
	if( hour >= 12 ) {
		hour = hour - 12;
		isPM = true;
	}
	char buf[32];
	if( isPM ) {
		sprintf(buf, "%02d:%02d PM", hour, min);
	} else {
		sprintf(buf, "%02d:%02d AM", hour, min);
	}
	lcd->drawString(buf, 37, 20);
	
	lastDrawnTime = time;
}

/**
 * <!--  onButtonPressed():  -->
 */
void NormalMode::onButtonPressed(ButtonType button) {
	app->changeMode( MODE_MENU );
}
