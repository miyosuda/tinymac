#include "TimeSetMode.h"
#include "Application.h"
#include "Lcd.h"
#include "data.h"

static const char* decideNames[] = {"OK", "Edit", "Exit"};

/**
 * <!--  init():  -->
 */
void TimeSetMode::init( Application* app_, Lcd* lcd_ ) {
	app = app_;
	lcd = lcd_;
	state = STATE_HOUR;
}

/**
 * <!--  setTime():  -->
 */
void TimeSetMode::reset( int time_ ) {
	time = time_;
	state = STATE_HOUR;
	decideIndex = DECIDE_OK;
	
	dirty = true;
}

/**
 * <!--  drawArrow():  -->
 */
void TimeSetMode::drawArrow() {
	int left;
	if( state == STATE_HOUR ) {
		left = 40-12;
	} else if( state == STATE_MIN ) {
		left = 26-12;
	} else {
		return;
	}

	ImageInfo upImageInfo;
	upImageInfo.left = left;
	upImageInfo.width = 5;
	upImageInfo.blockTop = 4;
	upImageInfo.blockHeight = 1;
	lcd->drawImage( upImageInfo, upImageData );
	
	ImageInfo downImageInfo;
	downImageInfo.left = left;
	downImageInfo.width = 5;
	downImageInfo.blockTop = 2;
	downImageInfo.blockHeight = 1;
	lcd->drawImage( downImageInfo, downImageData );
}

/**
 * <!--  drawTime():  -->
 */
void TimeSetMode::drawTime() {
	char buf[32];
	
	int hour = time / 3600;
	int min = (time % 3600) / 60;
	
	bool isPM = false;
	
	if( hour >= 12 ) {
		hour = hour - 12;
		isPM = true;
	}
	
	int x;
	if( state == STATE_DECIDE ) {
		x = 6;
	} else {
		x = 20+12;
	}
	int y = 16;
	
	const char* ampm;
	if( isPM ) {
		ampm = "PM  ";
	} else {
		ampm = "AM  ";
	}
	lcd->drawString(ampm, x, y, false);
	int length;
	length = lcd->calcStringWidth(ampm, true);
	x += length;
	
	sprintf(buf, "%02d", hour);
	lcd->drawString(buf, x, y);
	
	length = lcd->calcStringWidth(buf, true);
	x += length;
	
	lcd->drawString(":", x, y, false);
	length = lcd->calcStringWidth(":", true);
	x += length;
	
	sprintf(buf, "%02d", min);
	lcd->drawString(buf, x, y);
}

/**
 * <!--  drawDecideMenu():  -->
 */
void TimeSetMode::drawDecideMenu() {
	if( state == STATE_DECIDE ) {
		for(int i=0; i<DECIDE_SIZE; ++i) {
			int posX = 54;
			int posY = 16 + 8*i;
			if( i == decideIndex ) {
				lcd->drawString( ">", posX, posY );
			}
			lcd->drawString( decideNames[i], posX+5, posY );
		}
	}
}

/**
 * <!--  draw():  -->
 */
void TimeSetMode::draw() {
	if( !dirty ) {
		return;
	}

	lcd->clear();
	if( state != STATE_DECIDE ) {
		lcd->drawImage( timeImageInfo, timeImageData );
	}

	drawArrow();
	drawTime();
	drawDecideMenu();

	dirty = false;
}

/**
 * <!--  onButtonPressed():  -->
 */
void TimeSetMode::onButtonPressed(ButtonType button) {
	if( button == BUTTON_DOWN ) {
		if( state == STATE_HOUR ) {
			time += 3600;
			if( time >= 3600 * 24 ) {
				time -= 3600 * 24;
			}
		} else if( state == STATE_MIN ) {
			int hour0 = time / 3600;
			time += 60;
			int hour1 = time / 3600;
			if( hour0 != hour1 ) {
				time -= 3600;
			}
		} else if( state == STATE_DECIDE ) {
			decideIndex++;
			decideIndex = decideIndex % DECIDE_SIZE;
		}
	} else if( button == BUTTON_UP ) {
		if( state == STATE_HOUR ) {
			time -= 3600;
			if( time < 0  ) {
				time += 3600 * 24;
			}
		} else if( state == STATE_MIN ) {
			int hour0 = time / 3600;
			time -= 60;
			if( time < 0 ) {
				time += 3600;
			}
			int hour1 = time / 3600;
			if( hour0 != hour1 ) {
				time += 3600;
			}
		} else if( state == STATE_DECIDE ) {
			decideIndex--;
			if( decideIndex < 0 ) {
				decideIndex += DECIDE_SIZE;
			}
		}
	} else if( button == BUTTON_LEFT ) {
		if( state == STATE_MIN ) {
			state = STATE_HOUR;
		} else if( state == STATE_DECIDE ) {
			state = STATE_MIN;
		}		
	} else if( button == BUTTON_RIGHT ) {
		if( state == STATE_HOUR ) {
			state = STATE_MIN;
		} else if( state == STATE_MIN ) {
			state = STATE_DECIDE;
		}
	} else if( button == BUTTON_OK ) {
		if( state == STATE_HOUR ) {
			state = STATE_MIN;
		} else if( state == STATE_MIN ) {
			state = STATE_DECIDE;
		} else if( state == STATE_DECIDE ) {
			if( decideIndex == DECIDE_OK ) {
				app->setTime(time);
				app->changeMode( MODE_NORMAL );
			} else if( decideIndex == DECIDE_EDIT ) {
				decideIndex = DECIDE_OK;
				state = STATE_HOUR;
			} else if( decideIndex == DECIDE_EXIT ) {
				app->changeMode( MODE_NORMAL );
			}
		}
	}

	dirty = true;
}
