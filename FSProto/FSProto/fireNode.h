/*
 * Name		: Firenode.h
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * �� �ùķ����Ϳ��� ���� ������ ��� ����ü�� �ٷ�� ����� �����Ͽ����ϴ�.
 *
 */

#include <list>
#include "map.h"

#ifndef FIRENODE_H
#define FIRENODE_H

#define FIRENODE_DEFAULT_INFLAMMABLE	1000	//������ �⺻�� ��ũ��

#define FSTATE_FIRE_INIT		0x00000000	// ���� ���� �ʱ�ȭ
#define FSTATE_FIRE_ON			0x00000001	// �ش� ������ ���� ���� ����ġ ON
#define FSTATE_EXTEND_DISABLE	0x00000008	// �ش� ������ ���� Ȯ��� ������ ON
#define FSTATE_FIRE_NORMAL		0x00000010	// ȭ�� ���� 1 : �Ϲ� ȭ��
#define FSTATE_FIRE_OIL			0x00000020	// ȭ�� ���� 2 : ���� ȭ��
#define FSTATE_FIRE_ELEC		0x00000040	// ȭ�� ���� 3 : ���� ȭ��
#define FSTATE_FIRE_STEEL		0x00000080	// ȭ�� ���� 4 : �ݼ� ȭ��
#define FSTATE_FIRE_ISTOXIC		0x00000100	// ���� ȭ��
#define FSTATE_BURN_EASY		0x01000000	// ȭ�� ģȭ�� : Ÿ�� ����
#define FSTATE_BURN_NORMAL		0x02000000	// ȭ�� ģȭ�� : ����
#define FSTATE_BURN_HARD		0x04000000	// ȭ�� ģȭ�� : Ÿ�� �����
#define FSTATE_BURN_DISABLE		0x08000000	// ȭ�� ģȭ�� : Ÿ�� ����
#define FSTATE_DESTROYED		0x10000000	// ���ҵǾ� �������� �������� �ʴ� ����.

/***********************************************************
Information : Save and change area state that can be and is fired.
***********************************************************/
class FireNode {
public:
	int fireState;
	int coordX;
	int coordY;
	int fireLevel;
	int inflammable;	//������, ���� �����ϴ� ü�°������� ���� ����.

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