#include "MazeRunner.h"

MazeRunner::MazeRunner(const int &mapWidth, const int &mapHeight): mapWidth(mapWidth), mapHeight(mapHeight) {
	map = new char *[mapHeight];
	for (int height = 0; height < mapHeight; height++) {
		map[height] = new char[mapWidth];
		for (int width = 0; width < mapWidth; width++) {
			if (height % 2 != 0 && width % 2 != 0) {
				map[height][width] = '1';
				CreateMaze(width, height);
			} else {
				if(map[height][width] != '1')
					map[height][width] = '0';
			}
		}
	}
	map[0][1] = '1';
	map[mapHeight-1][mapWidth - 2] = 'd';

	numOfEnemys = int(mapHeight * mapWidth / 50);
	enemys = new Enemy[numOfEnemys];
	SpawnEnemys();
};

void MazeRunner::SpawnEnemys() {
	for (int i = 0; i < numOfEnemys; i++) {
		while(true) {
			int x = mapWidth - 5;
			x = util.RandomNumber(x);
			x += 5;

			int y = mapHeight - 5;
			y = util.RandomNumber(y);
			y += 5;

			if (map[y][x] != '0') {
				enemys[i].Initializer(x, y);
				break;
			}
		};
	}
}

void MazeRunner::CreateMaze(const int &x, const int &y) {
	int range = 2;
	int randNum = util.RandomNumber(range);
	if (x < 2) {
		randNum = 1;
	} else if (y < 2) {
		randNum = 0;
	}
	randNum > 0 ? map[y - 1][x] = '1' : map[y][x - 1] = '1';
}

void MazeRunner::GameLoop(int mapCode) {
	int x = 1; int y = 0;
	isPlaying = true;

	DrawMap(&x, &y);

	while (isPlaying) {
		switch (util.KeyControl()) {
		case UP:
			Move(x, y,  0, -1);
			break;
		case DOWN:
			Move(x, y,  0,  1);
			break;
		case LEFT:
			Move(x, y, -1,  0);
			break;
		case RIGHT:
			Move(x, y,  1,  0);
			break;
		case QUIT:
			util.SetColor(white, black);
			isPlaying = false;
			return;
		}
	}
	GameClear();

	util.SetColor(white, black);
	util.Gotoxy(22, 8);
}


void MazeRunner::DrawMap(int *x, int *y) {
	system("cls");

	for (int height = 0; height < mapHeight; height++) {
		for (int width = 0; width < mapWidth; width++) {
			char &cell = map[height][width];

			if (cell == '0') {
				util.SetColor(brown, brown);
				printf(" ");
			} else if (cell == '1') {
				util.SetColor(black, black);
				printf(" ");
			} else if (cell == 'd') {
				util.SetColor(green, green);
				printf(" ");
			}
		}
		printf("\n");
	}
	
	for (int i = 0; i < numOfEnemys; i++) {
		util.Gotoxy(enemys[i].PosX(), enemys[i].PosY());
		util.SetColor(red, red);
		printf(" ");
	}

	util.Gotoxy(1, 0);
	util.SetColor(white, white);
	cout << " ";

	util.SetColor(white, black);
}

void MazeRunner::GameClear() {
	util.SetColor(red, black);
	util.Gotoxy(mapWidth, mapHeight);
	cout << "Game Clear!" << endl;
	Sleep(5000);
}

void MazeRunner::GameFail() {
	util.SetColor(red, black);
	util.Gotoxy(mapWidth, mapHeight);
	cout << "Game Fail!" << endl;
	Sleep(5000);
}

void MazeRunner::Move(int &x, int &y, int _x, int _y) {
	util.SetColor(white, black);
	int whereToX = x + _x;
	int whereToY = y + _y;
	char &mapObject = map[whereToY][whereToX];

	if (mapObject == '0') {
		return;
	} else {
		player.Move(x, y, _x, _y);
		for (int i = 0; i < numOfEnemys; i++) {
			if (enemys[i].CollisionCheck(Pos{ whereToX, whereToY })) {
				isPlaying = false;
				GameFail();
				return;
			}
			EnemyMove(&enemys[i]);
		}

		if (mapObject == 'd') {
			isPlaying = false;
			return;
		}
	}
}

void MazeRunner::EnemyMove(Enemy *enemy) {
	const Pos pos = { enemy->PosX(), enemy->PosY() };
	Pos direction = { 0, 0 };

	do {
		int dir = util.RandomNumber(4);

		switch (dir) {
		case UP:
			direction = {  0,  1 };
			break;
		case DOWN:
			direction = {  0, -1 };
			break;
		case LEFT:
			direction = { -1,  0 };
			break;
		case RIGHT:
			direction = {  1,  0 };
			break;
		}
	} while (map[pos.y + direction.y][pos.x + direction.x] != '1');

	enemy->Move(direction.x, direction.y);

	util.Gotoxy(pos.x, pos.y);
	util.SetColor(black, black);
	printf(" ");

	util.Gotoxy(pos.x + direction.x, pos.y + direction.y);
	util.SetColor(red, red);
	printf(" ");
}