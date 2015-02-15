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
	printMap(testMap);

	_getch();
}