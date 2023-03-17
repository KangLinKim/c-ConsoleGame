#pragma once

#include "Headers.h"

#ifndef __UTILS__
#define __UTILS__

struct Pos {
	int x;
	int y;
};

enum Colors {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightGray,
	darkGray,
	lightBlue,
	lightGreen,
	lightCyan,
	lightRed,
	lightPurple,
	yellow,
	white
};

class Utils {
	public :
		void Init();
		void Gotoxy(const int &x, const int &y);
		void SetColor(const int &foreground, const int &background);
		int RandomNumber(const int &number);
		int KeyControl();
};

#endif