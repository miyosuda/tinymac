// -*- C++ -*-
#ifndef COMMON_HEADER
#define COMMON_HEADER

typedef enum {
	BUTTON_UP    = 1 << 0,
	BUTTON_DOWN  = 1 << 1,
	BUTTON_LEFT  = 1 << 2,
	BUTTON_RIGHT = 1 << 3,
	BUTTON_OK    = 1 << 4,
} ButtonType;

typedef enum {
	MODE_NORMAL   = 0,
	MODE_MENU     = 1,
	MODE_TIME_SET = 2,
} ModeType;

#endif
