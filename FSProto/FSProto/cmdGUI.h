/*
 * Name		: cmdGUI.h
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 * 
 * Information of this source code
 * 본 시뮬레이터에서 그래픽 효과를 구현하기 위한 헤더파일입니다.
 *
 */

#include <Windows.h>
#include "fire.h"

#ifndef CMD_GUI_H
#define CMD_GUI_H

/*
	커서를 콘솔 창의 특정 위치로 이동
	
	- int x, int y : 콘솔 창에서 커서를 이동시키고자 하는 2차원 좌표값
*/
void gotoxy(int x, int y);

void printMap(Map mapData);
void printMapData(Map* mapData);
void initMap(Map mapData);
void initMap(Fire* fireData);
void updateMap(Fire fireData);

#endif /* CMD_GUI_H */