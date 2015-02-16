/*
 * Name		: fireNode.cpp
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * fireNode.h의 함수를 정의하는 소스코드입니다.
 *
 */

#include "fireNode.h"

void FireNode::updateFireNode(void) {
	//시간이 지날 때마다(Update) 불이 가연물을 태우는 강도(FireLevel) 증가
	//최대 강도는 30
	if (this->getFireLevel() <= 30) {
		this->setFireLevel(this->getFireLevel() + 1);
	}
	//남은 가연물 양 업데이트
	this->setInflammable(this->getInflammable() - this->getFireLevel());
	//가연물이 남지 않으면 상태를 전소(DESTROYED)로 변경, 불이 꺼진다.
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