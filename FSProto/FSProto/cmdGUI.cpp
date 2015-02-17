/*
 * Name		: cmdGUI.cpp
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * cmdGUI.h의 함수를 정의하는 소스코드입니다.
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
			printf("%s", *(*(tempMapArray + i) + j) == 0 ? "  " : "□");
		}
		printf("\n");
	}
}

void printMapData(Map* mapData) {
	int** tempMapArray = mapData->getArray();

	for (int i = 0; i < mapData->getHeight(); i++) {
		for (int j = 0; j < mapData->getWidth(); j++) {
			gotoxy(j * 2, i);
			printf("%d", *(*(tempMapArray + i) + j));
		}
		printf("\n");
	}
}

void initMap(Map mapData) {
	system("cls");
	printMap(mapData);
}

void initMap(Fire* fireData) {
	system("cls");
	printMap(*(fireData->baseMapData));
}

void updateMap(Fire fireData) {
	for (int i = 0; i < fireData.fireMapData->getHeight(); i++) {
		for (int j = 0; j < fireData.fireMapData->getWidth(); j++) {
			if (*(*(fireData.baseMapData->array + i) + j) != 1) {
				gotoxy(j * 2, i);
				switch (*(*(fireData.fireMapData->array + i) + j) / 5) {
				case 0:
					printf("  ");
					break;
				case 1:
					printf("·");
					break;
				case 2:
					printf("∴");
					break;
				case 3:
					printf("※");
					break;
				case 4:
					printf("▨");
					break;
				case 5:
					printf("▩");
					break;
				case 6:
					printf("■");
					break;
				case -1:
					printf("▒");
					break;
				default:
					printf("%2.2d", *(*(fireData.fireMapData->array + i) + j) / 5);
					break;
				}
			}
		}
		printf("\n");
	}
}