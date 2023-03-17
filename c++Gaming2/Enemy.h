#pragma once

#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Utils.h"

class Enemy {
	private :
		Pos position;

	public :
		Enemy() {};
		~Enemy();

		void Initializer(int x, int y);
		void Move(const int &x, const int &y);

		inline int PosX() const {
			return position.x;
		}

		inline int PosY() const {
			return position.y;
		}

		bool CollisionCheck(const Pos &playerPos);
};

#endif