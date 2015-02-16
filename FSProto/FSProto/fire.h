/*
	Name		: fire.h
	Date		: 2015.02.15
	Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
	Information of this source code
	본 시뮬레이터에서 맵 위의 불의 정보 및 통신 기능을 구현하기 위한 헤더파일입니다.
*/

#include "fireNode.h"
#include "map.h"
#include <queue>


#ifndef FIRE_H
#define FIRE_H

class Fire {
public:
	Map* baseMapData;						//기반 맵 데이터 참조
	Map fireMapData;						//맵 상에서 불의 데이터를 저장하는 데이터.
	std::queue<FireNode> fireList;

	/* Constructor (Default, Not need to input any parameter) */
	Fire(void) {
		printf("Fire 클래스 디폴트 생성자 실행\n");
		this->baseMapData = NULL;
		this->fireMapData = Map();
		this->fireList = std::queue<FireNode>();
	}

	/* Constructor (Need to input parameter about Map Class) */
	Fire(Map* _baseMapData) {
		printf("Fire 클래스 _baseMapData 생성자 실행\n");
		this->baseMapData = _baseMapData;
		this->fireMapData = *(_baseMapData);
		this->fireList = std::queue<FireNode>();
	}

	/* Constructor (Need to input parameter about all of member variables) */
	Fire(Map* _baseMapData, Map _mapData, std::queue<FireNode> _fireList) {
		printf("Fire 클래스 전체 파라미터 입력 생성자 실행\n");
		this->baseMapData = _baseMapData;
		this->fireMapData = _mapData;
		this->fireList = _fireList;
	}

	/* Copy Constructor */
	Fire(const Fire &f) {
		printf("Fire 클래스 복사 생성자 실행\n");
		this->baseMapData = f.baseMapData;
		this->fireMapData = f.fireMapData;
		this->fireList = f.fireList;
	}

	/* Destructor */
	~Fire() {
		printf("Fire 클래스 소멸자 실행\n");
		this->baseMapData->~Map();
		this->fireMapData.~Map();
	}

	void createFire(int coordX, int coordY);
	void extendFire();
};

#endif /*FIRE_H*/