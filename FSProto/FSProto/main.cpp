/*
 * Name		: main.cpp
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * �� �ùķ������� ��� ��ɵ��� �Ѱ��ϴ� �κ��Դϴ�.
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