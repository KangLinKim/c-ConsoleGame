#include "Minesweeper.h"

Minesweeper::Minesweeper(const int &mapWidth, const int &mapHeight) : mapHeight(mapHeight), mapWidth(mapWidth) {
	map = new char *[mapHeight];
	for (int i = 0; i < mapHeight; i++) {
		map[i] = new char[mapWidth];
		for (int j = 0; j < mapWidth; j++) {
			map[i][j] = '0';
		}
	}

	mapCover = new bool *[mapHeight];
	for (int i = 0; i < mapHeight; i++) {
		mapCover[i] = new bool[mapWidth];
		for (int j = 0; j < mapWidth; j++) {
			mapCover[i][j] = false;
		}
	}

	Cells = mapWidth * mapHeight;
	numOfMines = mapWidth * mapHeight / 20;
}

void Minesweeper::Move(int &x, int &y, int _x, int _y) {
	util.SetColor(white, black);
	int whereToX = x + _x;
	int whereToY = y + _y;

	if (whereToX >= 0 && whereToX < mapWidth && whereToY >= 0 && whereToY < mapHeight) {
		util.Gotoxy(x, y);
		if (!mapCover[y][x]) {
			util.SetColor(white, white);
			cout << " ";
		} else {
			DrawCell(x, y);
		}
		util.SetColor(blue, blue);
		util.Gotoxy(x + _x, y + _y);
		printf(" ");

		x += _x;
		y += _y;
	}
}

void Minesweeper::Pang(int x, int y) {
	if (x < 0 || x > mapWidth - 1 || y < 0 || y > mapHeight - 1) {
		return;
	}
	if (!mapCover[y][x]) {
		mapCover[y][x] = true;
	} else {
		return;
	}
	util.Gotoxy(x, y);

	if (!DrawCell(x, y)) {
		Cells -= 1;
		if (Cells == numOfMines) {
			return;

		}
		Pang(x + 1, y);
		Pang(x - 1, y);
		Pang(x, y + 1);
		Pang(x, y - 1);
	}
}

void Minesweeper::GameLoop() {
	int x, y = 0;
	isPlaying = true;

	SelectLandfill();
	DrawMap(&x, &y);

	while (isPlaying) {
		switch (util.KeyControl()) {
		case UP:
			Move(x, y, 0, -1);
			break;
		case DOWN:
			Move(x, y, 0, 1);
			break;
		case LEFT:
			Move(x, y, -1, 0);
			break;
		case RIGHT:
			Move(x, y, 1, 0);
			break;
		case SUBMIT:
			Pang(x, y);
			break;
		case QUIT:
			util.SetColor(white, black);
			isPlaying = false;
			return;
		}
	}

	util.Gotoxy(22, 8);
}

bool Minesweeper::DrawCell(int &x, int &y) {
	char &mapObject = map[y][x];

	if (mapCover[y][x]) {
		if (mapObject == '0') {
			util.SetColor(black, black);
			cout << " ";
			return false;
		} else if (mapObject == 'M') {
			util.SetColor(red, black);
			isPlaying = false;
			GameFail('M');
			return true;
		} else {
			util.SetColor(white, black);
			cout << mapObject;
			return true;
		}
	}

	return false;
}

void Minesweeper::DrawMap(int *x, int *y) {
	system("cls");
	
	util.SetColor(white, white);
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			cout << " ";
		}
		cout << endl;
	}

	util.Gotoxy(0, 0);
	util.SetColor(blue, black);
	cout << " ";

	util.SetColor(white, black);
}

void Minesweeper::SelectLandfill() {
	for (int i = 0; i < numOfMines; i++) {
		Mine newMine = { util.RandomNumber(mapWidth), util.RandomNumber(mapHeight) };
		map[newMine.posY][newMine.posX] = 'M';
		CheckNearby(newMine.posX, newMine.posY);
	}
}

void Minesweeper::CheckNearby(const int &cellX, const int &cellY) {
	for (int nearbyX = cellX - 1; nearbyX < cellX + 2; nearbyX++) {
		for (int nearbyY = cellY - 1; nearbyY < cellY + 2; nearbyY++) {
			if (nearbyX >= 0 && nearbyX < mapWidth && nearbyY >= 0 && nearbyY < mapHeight) {
				if (map[nearbyY][nearbyX] != 'M') {
					int tmp = map[nearbyY][nearbyX] - '0';
					tmp += 1;
					map[nearbyY][nearbyX] = tmp + '0';
				}
			}
		}
	}
}

void Minesweeper::GameFail(char gameObject) {
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			if (map[y][x] == gameObject) {
				util.Gotoxy(x, y);
				cout << gameObject;
			}
		}
	}

	util.Gotoxy(mapWidth, mapHeight);
	cout << "Game Over!" << endl;
	Sleep(5000);
}