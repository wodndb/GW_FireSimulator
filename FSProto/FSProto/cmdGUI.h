/*
 * Name		: cmdGUI.h
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 * 
 * Information of this source code
 * �� �ùķ����Ϳ��� �׷��� ȿ���� �����ϱ� ���� ��������Դϴ�.
 *
 */

#include <Windows.h>
#include "fire.h"

#ifndef CMD_GUI_H
#define CMD_GUI_H

/*
	Ŀ���� �ܼ� â�� Ư�� ��ġ�� �̵�
	
	- int x, int y : �ܼ� â���� Ŀ���� �̵���Ű���� �ϴ� 2���� ��ǥ��
*/
void gotoxy(int x, int y);

void printMap(Map mapData);
void printMapData(Map* mapData);
void initMap(Map mapData);
void initMap(Fire* fireData);
void updateMap(Fire fireData);

#endif /* CMD_GUI_H */