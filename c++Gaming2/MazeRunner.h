#pragma once

#ifndef __MAZERUNNER_H__
#define __MAZERUNNER_H__

#include "Utils.h"
#include "Player.h"
#include "Enemy.h"

class MazeRunner {
	private :
		char **map;
		const int mapHeight;
		const int mapWidth;
		bool isPlaying;

		int numOfEnemys;

		void CreateMaze(const int &x, const int &y);
		void SpawnEnemys();
		void DrawMap(int *x, int *y);
		void GameClear();
		void GameFail();
		
		void Move(int &x, int &y, int _x, int _y);
		void EnemyMove(Enemy *enemy);
	
		Utils util;
		Player player;
		Enemy *enemys;

	public :
		MazeRunner(const int &mapWidth, const int &mapHeight);
		void GameLoop(int mapCode);
};

#endif