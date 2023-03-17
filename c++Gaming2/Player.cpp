#include "Player.h"

void Player::Move(int &x, int &y, int _x, int _y) {
	util.Gotoxy(x, y);
	util.SetColor(black, black);
	printf(" ");

	util.Gotoxy(x + _x, y + _y);
	util.SetColor(white, white);
	printf(" ");

	x += _x;
	y += _y;
}