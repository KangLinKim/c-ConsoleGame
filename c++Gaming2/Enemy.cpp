#include "Enemy.h"

Enemy::~Enemy() {
	delete &position;
}

void Enemy::Initializer(int x, int y) {
	this->position = { x, y };
}

void Enemy::Move(const int &x, const int &y) {
	position.x += x;
	position.y += y;
}

bool Enemy::CollisionCheck(const Pos &playerPos) {
	if (this->position.x == playerPos.x && this->position.y == playerPos.y) {
		return true;
	}
	return false;
}