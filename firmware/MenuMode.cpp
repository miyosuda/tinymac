#include "MenuMode.h"
#include "Application.h"
#include "Lcd.h"
#include "data.h"

static const char* menuNames[] = {"Time set", "Exit"};

/**
 * <!--  init():  -->
 */
void MenuMode::init( Application* app_, Lcd* lcd_ ) {
	app = app_;
	lcd = lcd_;

	menuIndex = 0;
	dirty = true;
}

/**
 * <!--  reset():  -->
 */
void MenuMode::reset() {
	dirty = true;
	menuIndex = 0;
}

/**
 * <!--  draw():  -->
 */
void MenuMode::draw() {
	if( !dirty ) {
		return;
	}
	
	lcd->clear();
	lcd->drawImage( smileImageInfo, smileImageData );
	
	for(int i=0; i<2; ++i) {
		if( i == menuIndex ) {
			lcd->drawString( ">", 29, 16+8*i, false );
		}
		lcd->drawString( menuNames[i], 35, 16+8*i, false );
	}
	
	dirty = false;
}

/**
 * <!--  onButtonPressed():  -->
 */
void MenuMode::onButtonPressed(ButtonType button) {
	if( button == BUTTON_UP ) {
		menuIndex--;
		if( menuIndex < 0 ) {
			menuIndex += MENU_SIZE;
		}
	} else if( button == BUTTON_DOWN ) {
		menuIndex++;
		menuIndex = menuIndex % MENU_SIZE;
	} else if( button == BUTTON_OK ) {
		if( menuIndex == MENU_TIME_SET ) {
			app->changeMode( MODE_TIME_SET );
		} else if( menuIndex == MENU_EXIT) {
			app->changeMode( MODE_NORMAL );
		}
	}

	dirty = true;
}
