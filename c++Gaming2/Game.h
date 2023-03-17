#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#include "Utils.h"
#include "Minesweeper.h"
#include "MazeRunner.h"

class Game {
	private :
		Utils util;

		/*
		Minesweeper minesweeper;
		MazeRunner mazerunner;
		*/

	public :
		/*
		Game(Utils *util, Minesweeper *minesweeper, MazeRunner *mazerunner) :
			util(*util), minesweeper(*minesweeper), mazerunner(*mazerunner) {};
		*/
		Game(Utils *util) : util(*util) {};
		~Game() {};

		/*
		template<typename T>
		inline void InitGame(T gamename) {
			T.GameLoop();
		};
		*/

		void TitleDraw();
		int MenuDraw();
		int MaplistDraw();
		void InfoDraw();
};

#endif