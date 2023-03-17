#pragma once

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Headers.h"
#include "Utils.h"

class Player {
	private :
		Utils util;

	public :
		void Move(int &x, int &y, int _x, int _y);
};


#endif __PLAYER_H__