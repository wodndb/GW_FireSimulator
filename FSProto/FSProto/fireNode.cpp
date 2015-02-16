/*
 * Name		: fireNode.cpp
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * fireNode.h�� �Լ��� �����ϴ� �ҽ��ڵ��Դϴ�.
 *
 */

#include "fireNode.h"

void FireNode::updateFireNode(void) {
	//�ð��� ���� ������(Update) ���� �������� �¿�� ����(FireLevel) ����
	//�ִ� ������ 30
	if (this->getFireLevel() <= 30) {
		this->setFireLevel(this->getFireLevel() + 1);
	}
	//���� ������ �� ������Ʈ
	this->setInflammable(this->getInflammable() - this->getFireLevel());
	//�������� ���� ������ ���¸� ����(DESTROYED)�� ����, ���� ������.
	if (this->getInflammable() < 0) {
		this->enableFireState(FSTATE_DESTROYED);
		this->setFireLevel(-1);
	}
}

void FireNode::enableFireState(int fstate) {
	this->setFireState(this->getFireState() | fstate);
}

void FireNode::disableFireState(int fstate) {
	this->setFireState(this->getFireState() & ~(fstate));
}