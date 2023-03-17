//https://geundung.dev/16?category=699626

#include "main.h"

int main() {
	Utils util;
	Game game(new Utils);
	Minesweeper minesweeper(60, 20);
	MazeRunner mazeRunner(77, 21);
	util.Init();

	while (true) {
		game.TitleDraw();
		int menuCode = game.MenuDraw();
		if (menuCode == 0) {
			minesweeper.GameLoop();
			
		} else if (menuCode == 1) {
			int pressedKey = game.MaplistDraw();

			if (pressedKey == 0) {
				mazeRunner.GameLoop(0);
			} else if (pressedKey == 1) {
				mazeRunner.GameLoop(1);
			}
		} else if (menuCode == 2) {
			game.InfoDraw();
		} else if (menuCode == 3) {
			return 0;
		}
		system("cls");
		util.SetColor(white, black);
	}

	return 0;
}