#pragma once

#ifndef __MINESWEEPER_H__
#define __MINESWEEPER_H__

#include "Utils.h"

class Minesweeper {
	private :
		char **map;
		bool **mapCover;
		int mapWidth;
		int mapHeight;

		unsigned int Cells;
		unsigned int numOfMines;
		bool isPlaying;

		struct Mine {
			int posX;
			int posY;
		};

		Utils util;

		void Move(int &x, int &y, int _x, int _y);
		void Pang(int x, int y);
		bool DrawCell(int &x, int &y);
		void DrawMap(int *x, int *y);
		void SelectLandfill();
		void CheckNearby(const int &cellX, const int &cellY);
		
		void GameFail(char gameObject);
		inline void GameClear() {
			util.Gotoxy(mapWidth, mapHeight);
			util.SetColor(cyan, black);
			cout << "Game Clear!";
		}
	
	public:
		Minesweeper(const int &mapWidth, const int &mapHeight);
		void GameLoop();
};

#endif