/*
	Name		: fire.h
	Date		: 2015.02.15
	Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
	Information of this source code
	�� �ùķ����Ϳ��� �� ���� ���� ���� �� ��� ����� �����ϱ� ���� ��������Դϴ�.
*/

#include "fireNode.h"
#include "map.h"
#include <queue>


#ifndef FIRE_H
#define FIRE_H

class Fire {
public:
	Map* baseMapData;						//��� �� ������ ����
	Map* fireMapData;						//�� �󿡼� ���� �����͸� �����ϴ� ������.
	std::queue<FireNode> fireList;

	/* Constructor (Default, Not need to input any parameter) */
	Fire(void) {
		this->baseMapData = NULL;
		this->fireMapData = NULL;
		this->fireList = std::queue<FireNode>();
	}

	/* Constructor (Need to input parameter about Map Class) */
	Fire(Map* _baseMapData) {
		this->baseMapData = _baseMapData;
		this->fireMapData = new Map(*_baseMapData);
		this->fireList = std::queue<FireNode>();
	}

	/* Constructor (Need to input parameter about all of member variables) */
	Fire(Map* _baseMapData, Map* _mapData, std::queue<FireNode> _fireList) {
		this->baseMapData = _baseMapData;
		this->fireMapData = _mapData;
		this->fireList = _fireList;
	}

	/* Copy Constructor */
	Fire(const Fire &f) {
		this->baseMapData = f.baseMapData;
		this->fireMapData = f.fireMapData;
		this->fireList = f.fireList;
	}

	/* Destructor */
	~Fire() {
		this->baseMapData->~Map();
		this->fireMapData->~Map();
	}

	void createFire(int coordX, int coordY);
	void extendFire();
};

#endif /*FIRE_H*/