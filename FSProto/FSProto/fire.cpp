/*
* Name		: fire.cpp
* Date		: 2015.02.15
* Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
*
* Information of this source code
* fire.h의 함수를 정의하는 소스코드입니다.
*
*/

#include "fire.h"

void Fire::createFire(int coordX, int coordY) {
	//허용 맵 범위 내에 있는지 체크
	if (coordX >= 0 && coordX < this->baseMapData->getWidth()
		&& coordY >= 0 && coordX < this->baseMapData->getHeight()) {
		//벽이 아니라 불에 탈 수 있는 장소인지 체크
		if (*(*(this->baseMapData->array + coordY) + coordX) != 1
			&& *(*(this->fireMapData.array + coordY) + coordX) == 0) {
			FireNode tempFireNode(coordX, coordY);
			tempFireNode.enableFireState(FSTATE_FIRE_ON | FSTATE_FIRE_NORMAL);
			tempFireNode.updateFireNode();
			*(*(this->fireMapData.array + coordY) + coordY) = tempFireNode.getFireLevel();
			this->fireList.push(tempFireNode);		//현재 Call by Value인데 Call by Reference로 동적할당 변경 필요
		}
	}
}

void Fire::extendFire(void) {
	int fireNum = fireList.size();
	FireNode tempFireNode;

	for (int i = 0; i < fireNum; i++) {

		//해당 노드가 불이 확산될 수 있는 지점일 경우 -> 주변으로 확산
		if ((this->fireList.front().fireState & FSTATE_EXTEND_DISABLE) != FSTATE_EXTEND_DISABLE) {
			//확산 원점 노드 업데이트 및 큐의 맨 뒤로 보내기
			this->fireList.front().updateFireNode();
			*(*(this->fireMapData.array + this->fireList.front().getCoordY()) + this->fireList.front().getCoordX()) = this->fireList.front().getFireLevel();
			this->fireList.front().enableFireState(FSTATE_EXTEND_DISABLE);	//불의 확산이 처리되므로 화재가 확산될 가능성 없음으로 정보 수정.
			this->fireList.push(this->fireList.front());

			//주위 가연물이 있는 공간으로 불 확산
			for (int borderY = -1; borderY < 2; borderY++) {
				for (int borderX = -1; borderX < 2; borderX++) {
					if (borderX != this->fireList.front().getCoordX()
						|| borderY != this->fireList.front().getCoordY()) {
						this->createFire(borderX, borderY);
					}
				}
			}

			//확산 원점을 pop하여 다음 발화점으로 이동
			this->fireList.pop();
		}
		//해당 노드가 불이 확산되지 않는 지점일 경우
		else {
			//불의 강도 증가 및 맵에 정보 업데이트
			this->fireList.front().updateFireNode();
			*(*(this->fireMapData.array + this->fireList.front().getCoordY()) + this->fireList.front().getCoordX()) = this->fireList.front().getFireLevel();

			//해당 발화점이 전소된 경우 : 큐에서 제거
			if ((this->fireList.front().fireState & FSTATE_DESTROYED) != FSTATE_DESTROYED) {
				this->fireList.pop();
			}
			//해당 발화점이 전소되지 않은 경우 : 큐의 맨 뒤로 이동
			else {
				this->fireList.push(this->fireList.front());
				this->fireList.pop();
			}
		}
	}
}