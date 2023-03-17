#include "Utils.h"

void Utils::Init() {
	system("mode con cols = 56 lines = 20 | title ��������");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//�ܼ� �ڵ鰡������
	CONSOLE_CURSOR_INFO consoleCursor;
	consoleCursor.bVisible = false;		//false �Ǵ� 0 : �����
	consoleCursor.dwSize = true;
	SetConsoleCursorInfo(consoleHandle, &consoleCursor);	//consoleHandle�� &�� ������ �ȵ�
}

void Utils::Gotoxy(const int& x, const int& y) {
	HANDLE consolHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consolHandle, pos);
}

void Utils::SetColor(const int& foreground, const int& background) {
	HANDLE consolHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = foreground + background * 16;
	SetConsoleTextAttribute(consolHandle, color);
}

int Utils::RandomNumber(const int &number) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, number - 1);

	return dist(gen);
}

int Utils::KeyControl() {
	char pressedKey = _getch();

	if (pressedKey == 'w' || pressedKey == 'W') {
		return UP;
	}
	else if (pressedKey == 's' || pressedKey == 'S') {
		return DOWN;
	}
	else if (pressedKey == 'a' || pressedKey == 'A') {
		return LEFT;
	}
	else if (pressedKey == 'd' || pressedKey == 'D') {
		return RIGHT;
	}
	else if (pressedKey == ' ') {
		return SUBMIT;
	}
	else if (pressedKey == 27) {
		return QUIT;
	}
}