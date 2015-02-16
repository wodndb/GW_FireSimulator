/*
* Name		: fire.cpp
* Date		: 2015.02.15
* Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
*
* Information of this source code
* fire.h�� �Լ��� �����ϴ� �ҽ��ڵ��Դϴ�.
*
*/

#include "fire.h"

void Fire::createFire(int coordX, int coordY) {
	//��� �� ���� ���� �ִ��� üũ
	if (coordX >= 0 && coordX < this->baseMapData->getWidth()
		&& coordY >= 0 && coordX < this->baseMapData->getHeight()) {
		//���� �ƴ϶� �ҿ� Ż �� �ִ� ������� üũ
		if (*(*(this->baseMapData->array + coordY) + coordX) != 1
			&& *(*(this->fireMapData.array + coordY) + coordX) == 0) {
			FireNode tempFireNode(coordX, coordY);
			tempFireNode.enableFireState(FSTATE_FIRE_ON | FSTATE_FIRE_NORMAL);
			tempFireNode.updateFireNode();
			*(*(this->fireMapData.array + coordY) + coordY) = tempFireNode.getFireLevel();
			this->fireList.push(tempFireNode);		//���� Call by Value�ε� Call by Reference�� �����Ҵ� ���� �ʿ�
		}
	}
}

void Fire::extendFire(void) {
	int fireNum = fireList.size();
	FireNode tempFireNode;

	for (int i = 0; i < fireNum; i++) {

		//�ش� ��尡 ���� Ȯ��� �� �ִ� ������ ��� -> �ֺ����� Ȯ��
		if ((this->fireList.front().fireState & FSTATE_EXTEND_DISABLE) != FSTATE_EXTEND_DISABLE) {
			//Ȯ�� ���� ��� ������Ʈ �� ť�� �� �ڷ� ������
			this->fireList.front().updateFireNode();
			*(*(this->fireMapData.array + this->fireList.front().getCoordY()) + this->fireList.front().getCoordX()) = this->fireList.front().getFireLevel();
			this->fireList.front().enableFireState(FSTATE_EXTEND_DISABLE);	//���� Ȯ���� ó���ǹǷ� ȭ�簡 Ȯ��� ���ɼ� �������� ���� ����.
			this->fireList.push(this->fireList.front());

			//���� �������� �ִ� �������� �� Ȯ��
			for (int borderY = -1; borderY < 2; borderY++) {
				for (int borderX = -1; borderX < 2; borderX++) {
					if (borderX != this->fireList.front().getCoordX()
						|| borderY != this->fireList.front().getCoordY()) {
						this->createFire(borderX, borderY);
					}
				}
			}

			//Ȯ�� ������ pop�Ͽ� ���� ��ȭ������ �̵�
			this->fireList.pop();
		}
		//�ش� ��尡 ���� Ȯ����� �ʴ� ������ ���
		else {
			//���� ���� ���� �� �ʿ� ���� ������Ʈ
			this->fireList.front().updateFireNode();
			*(*(this->fireMapData.array + this->fireList.front().getCoordY()) + this->fireList.front().getCoordX()) = this->fireList.front().getFireLevel();

			//�ش� ��ȭ���� ���ҵ� ��� : ť���� ����
			if ((this->fireList.front().fireState & FSTATE_DESTROYED) != FSTATE_DESTROYED) {
				this->fireList.pop();
			}
			//�ش� ��ȭ���� ���ҵ��� ���� ��� : ť�� �� �ڷ� �̵�
			else {
				this->fireList.push(this->fireList.front());
				this->fireList.pop();
			}
		}
	}
}