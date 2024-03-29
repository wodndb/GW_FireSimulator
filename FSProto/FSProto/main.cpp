/*
 * Name		: main.cpp
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * 본 시뮬레이터의 모든 기능들을 총괄하는 부분입니다.
 *
 */
#include <conio.h>
#include "main.h"

int main(void) {
	Map testMap;
	testMap.constructMapData();
	Fire fireData(&testMap);
	fireData.createFire(2, 2);
	int cnt;

	initMap(&fireData);

	cnt = 0;

	while (fireData.fireList.size() != 0) {
		Sleep(200);
		fireData.extendFire();
		//printMapData(fireData.fireMapData);
		updateMap(fireData);
		gotoxy(0, 10);
		printf("cnt : %d, Node : %d", cnt++, fireData.fireList.size());
	}

	_getch();
}