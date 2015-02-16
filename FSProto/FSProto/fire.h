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
	Map fireMapData;						//�� �󿡼� ���� �����͸� �����ϴ� ������.
	std::queue<FireNode> fireList;

	/* Constructor (Default, Not need to input any parameter) */
	Fire(void) {
		printf("Fire Ŭ���� ����Ʈ ������ ����\n");
		this->baseMapData = NULL;
		this->fireMapData = Map();
		this->fireList = std::queue<FireNode>();
	}

	/* Constructor (Need to input parameter about Map Class) */
	Fire(Map* _baseMapData) {
		printf("Fire Ŭ���� _baseMapData ������ ����\n");
		this->baseMapData = _baseMapData;
		this->fireMapData = *(_baseMapData);
		this->fireList = std::queue<FireNode>();
	}

	/* Constructor (Need to input parameter about all of member variables) */
	Fire(Map* _baseMapData, Map _mapData, std::queue<FireNode> _fireList) {
		printf("Fire Ŭ���� ��ü �Ķ���� �Է� ������ ����\n");
		this->baseMapData = _baseMapData;
		this->fireMapData = _mapData;
		this->fireList = _fireList;
	}

	/* Copy Constructor */
	Fire(const Fire &f) {
		printf("Fire Ŭ���� ���� ������ ����\n");
		this->baseMapData = f.baseMapData;
		this->fireMapData = f.fireMapData;
		this->fireList = f.fireList;
	}

	/* Destructor */
	~Fire() {
		printf("Fire Ŭ���� �Ҹ��� ����\n");
		this->baseMapData->~Map();
		this->fireMapData.~Map();
	}

	void createFire(int coordX, int coordY);
	void extendFire();
};

#endif /*FIRE_H*/