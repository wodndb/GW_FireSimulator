/*
 * Name		: cmdGUI.cpp
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * cmdGUI.h�� �Լ��� �����ϴ� �ҽ��ڵ��Դϴ�.
 *
 */

#include "cmdGUI.h"

void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void printMap(Map mapData) {
	int** tempMapArray = mapData.getArray();

	for (int i = 0; i < mapData.getHeight(); i++) {
		for (int j = 0; j < mapData.getWidth(); j++) {
			printf("%s", *(*(tempMapArray + i) + j) == 0 ? "  " : "��");
		}
		printf("\n");
	}
}