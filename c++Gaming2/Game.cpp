#include "Game.h"

void Game::TitleDraw() {
	printf("\n\n\n\n");
	printf("ESCAPE");
	printf("\n\n\n\n");
}

int Game::MenuDraw() {
	int x = 24;
	int y = 12;

	util.Gotoxy(24 - 2, 12);
	printf("> �� �� ã �� ");
	util.Gotoxy(24, 13);
	printf("�� �� Ż �� ");
	util.Gotoxy(24, 14);
	printf("�� �� �� �� ");
	util.Gotoxy(24, 15);
	printf("�� ��  ");

	while (true) {
		int n = util.KeyControl();
		switch (n) {
			case UP: {
				if (y > 12) {
					util.Gotoxy(x - 2, y);
					printf(" ");
					util.Gotoxy(x - 2, --y);
					printf(">");
				}
				break;
			}
			case DOWN: {
				if (y < 15) {
					util.Gotoxy(x - 2, y);
					printf(" ");
					util.Gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y - 12;
			}
		}
	}
}

int Game::MaplistDraw() {
	int x = 24;
	int y = 6;

	system("cls");
	printf("\n\n");
	printf("[�� ����]\n\n");
	util.Gotoxy(x - 2, y);
	printf("> ����");
	util.Gotoxy(x, y + 1);
	printf("�����");
	util.Gotoxy(x, y + 2);
	printf("�� ��");

	while (true) {
		int pressedKey = util.KeyControl();
		switch (pressedKey) {
		case UP:
			if (y > 6) {
				util.Gotoxy(x - 2, y);
				printf(" ");
				util.Gotoxy(x - 2, --y);
				printf(">");
			}
			break;

		case DOWN:
			if (y < 9) {
				util.Gotoxy(x - 2, y);
				printf(" ");
				util.Gotoxy(x - 2, ++y);
				printf(">");
			}
			break;

		case SUBMIT:
			return y - 6;
		}
	}
}

void Game::InfoDraw() {
	system("cls");
	printf("\n\n");
	printf("[ ���۹� ]\n\n");
	printf("�̵� : W, A, S, D\n");
	printf("�����̽��� ������ ����ȭ��\n");

	while (true) {
		if (util.KeyControl() == SUBMIT) {
			break;
		}
	}
}