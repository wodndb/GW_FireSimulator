/*
	Name		: fire.h
	Date		: 2015.02.15
	Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
	Information of this source code
	본 시뮬레이터에서 맵 위의 불의 정보 및 통신 기능을 구현하기 위한 헤더파일입니다.
*/

#include "fireNode.h"
#include "map.h"
#include <list>


#ifndef FIRE_H
#define FIRE_H

class Fire {
	Map* mapData;						//맵 데이터를 참조한다. (Call by reference)
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