/*
	Name		: fire.h
	Date		: 2015.02.15
	Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
	Information of this source code
	�� �ùķ����Ϳ��� �� ���� ���� ���� �� ��� ����� �����ϱ� ���� ��������Դϴ�.
*/

#include "fireNode.h"
#include "map.h"
#include <list>


#ifndef FIRE_H
#define FIRE_H

class Fire {
	Map* mapData;						//�� �����͸� �����Ѵ�. (Call by reference)
	std::list<FireNode> fireList;

	/* Constructor (Default, Not need to input any parameter) */
	Fire(void) {
		this->mapData = NULL;
		this->fireList = std::list<FireNode>();
	}

	/* Constructor (Need to input parameter about Map Class) */
	Fire(Map* _mapData) {
		this->mapData = _mapData;
		this->fireList = std::list<FireNode>();
	}

	/* Constructor (Need to input parameter about all of member variables) */
	Fire(Map* _mapData, std::list<FireNode> _fireList) {
		this->mapData = _mapData;
		this->fireList = _fireList;
	}

	/* Destructor */
	~Fire() {
	}

	void createFire(int coordX, int coordY);
	void extendFire();
};

#endif /*FIRE_H*/