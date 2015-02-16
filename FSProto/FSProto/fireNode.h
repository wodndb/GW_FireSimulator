/*
 * Name		: Firenode.h
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * 본 시뮬레이터에서 불의 정보를 담는 구조체를 다루는 기능을 정리하였습니다.
 *
 */

#include <list>
#include "map.h"

#ifndef FIRENODE_H
#define FIRENODE_H

#define FIRENODE_DEFAULT_INFLAMMABLE	1000	//가연물 기본값 매크로

#define FSTATE_FIRE_INIT		0x00000000	// 불의 정보 초기화
#define FSTATE_FIRE_ON			0x00000001	// 해당 영역에 불이 나면 스위치 ON
#define FSTATE_EXTEND_DISABLE	0x00000008	// 해당 영역에 불이 확장될 없으면 ON
#define FSTATE_FIRE_NORMAL		0x00000010	// 화재 종류 1 : 일반 화재
#define FSTATE_FIRE_OIL			0x00000020	// 화재 종류 2 : 유류 화재
#define FSTATE_FIRE_ELEC		0x00000040	// 화재 종류 3 : 전기 화재
#define FSTATE_FIRE_STEEL		0x00000080	// 화재 종류 4 : 금속 화재
#define FSTATE_FIRE_ISTOXIC		0x00000100	// 독성 화재
#define FSTATE_BURN_EASY		0x01000000	// 화재 친화성 : 타기 쉬움
#define FSTATE_BURN_NORMAL		0x02000000	// 화재 친화성 : 보통
#define FSTATE_BURN_HARD		0x04000000	// 화재 친화성 : 타기 어려움
#define FSTATE_BURN_DISABLE		0x08000000	// 화재 친화성 : 타지 않음
#define FSTATE_DESTROYED		0x10000000	// 전소되어 가연물이 존재하지 않는 공간.

/***********************************************************
Information : Save and change area state that can be and is fired.
***********************************************************/
class FireNode {
public:
	int fireState;
	int coordX;
	int coordY;
	int fireLevel;
	int inflammable;	//가연물, 불이 지속하는 체력게이지와 같은 개념.

	/* Constructor (Default, Not need to input any parameter) */
	FireNode(void) {
		this->fireState = 0x00 | FSTATE_BURN_NORMAL;
		this->coordX = 0;
		this->coordY = 0;
		this->fireLevel = 0;
		this->inflammable = FIRENODE_DEFAULT_INFLAMMABLE;
	}

	/* Constructor (Need to input parameter about all coordinate of fire) */
	FireNode(int x, int y) {
		this->fireState = 0x00 | FSTATE_BURN_NORMAL;
		this->coordX = x;
		this->coordY = y;
		this->fireLevel = 0;
		this->inflammable = FIRENODE_DEFAULT_INFLAMMABLE;
	}

	/* Constructor (Need to input parameter about all of member variables) */
	FireNode(int fstate, int x, int y, int fLevel, int inflam) {
		this->fireState = fstate;
		this->coordX = x;
		this->coordY = y;
		this->fireLevel = fLevel;
		this->inflammable = inflam;
	}

	/* Copy Constructor */
	FireNode(const FireNode &f) {
		this->fireState = f.fireState;
		this->coordX = f.coordX;
		this->coordY = f.coordY;
		this->fireLevel = f.fireLevel;
		this->inflammable = f.inflammable;
	}

	/* Destructor */
	~FireNode(void) {
	
	}

	void setFireState(int fState) { this->fireState = fState; }
	void setCoordX(int x) { this->coordX = x; }
	void setCoordY(int y) { this->coordY = y; }
	void setFireLevel(int fLevel) { this->fireLevel = fLevel; }
	void setInflammable(int inflam) { this->inflammable = inflam; }

	int getFireState(void) { return this->fireState; }
	int getCoordX(void) { return this->coordX; }
	int getCoordY(void) { return this->coordY; }
	int	getFireLevel(void) { return this->fireLevel; }
	int getInflammable(void) { return this->inflammable; }

	void updateFireNode(void);
	void enableFireState(int fstate);
	void disableFireState(int fstate);
};

#endif /* FIRENODE_H */