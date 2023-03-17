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
	printf("> 지 뢰 찾 기 ");
	util.Gotoxy(24, 13);
	printf("미 로 탈 출 ");
	util.Gotoxy(24, 14);
	printf("게 임 정 보 ");
	util.Gotoxy(24, 15);
	printf("종 료  ");

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
	printf("[맵 선택]\n\n");
	util.Gotoxy(x - 2, y);
	printf("> 쉬움");
	util.Gotoxy(x, y + 1);
	printf("어려움");
	util.Gotoxy(x, y + 2);
	printf("뒤 로");

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
	printf("[ 조작법 ]\n\n");
	printf("이동 : W, A, S, D\n");
	printf("스페이스바 누르면 메인화면\n");

	while (true) {
		if (util.KeyControl() == SUBMIT) {
			break;
		}
	}
}