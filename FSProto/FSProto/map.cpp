/*
 * Name		: map.cpp
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * map.h의 함수를 정의하는 소스코드입니다.
 *
 */

#include "map.h"

//---- Other Functions ----//

void Map::loadMapFileStream(char* _fileName) {
	FILE* tempStream;
	fopen_s(&tempStream, _fileName, "r");
	
	// 파일이 존재하는지 확인
	if (tempStream == NULL) {
		printf("존재하지 않는 파일입니다. 프로그램을 종료합니다.");
		exit(1);
	}
	// 파일이 존재하는 경우 파일 이름이 맵 구조체에 저장되어 있는지 확인,
	// 저장되어있지 않은 경우 파일 이름을 맵 구조체에 저장.
	else  {
		printf("파일은 존재함\n");
		if (this->getFileName() == NULL) {
			printf("파일명 동적메모리 할당중\n");
			char* tempStr = (char*)malloc(sizeof(char) * strlen(_fileName));
			printf("파일명 동적메모리 할당 완료(%d byte), 파일명 복사중\n", sizeof(char) * strlen(_fileName) + 1);
			strcpy_s(tempStr, strlen(_fileName) + 1, _fileName);
			printf("파일명 복사완료, 저장중\n");
			this->setFileName(tempStr);
			printf("파일명 복사완료, 저장완료\n");
		}
		// 불러온 파일 스트림을 맵 구조체에 저장.
			this->setFilestream(tempStream);
	}
}

void Map::parsingMapSize(void) {
	FILE* tempStream;
	int cntX;
	int cntY;
	char buffChar;

	if (this->getFileStream() == NULL) {
		printf("파일 스트림이 존재하지 않습니다. 프로그램을 종료합니다.");
		exit(1);
	}
	else {
		cntX = 0;
		cntY = 0;
		tempStream = this->getFileStream();
		while (!feof(tempStream)) {
			buffChar = fgetc(tempStream);
			if (buffChar == ' ') {
				cntX++;
			}
			if (buffChar == '\n') {
				cntX++;
				cntY++;
			}
		}

		cntX /= cntY;

		this->setWidth(cntX);
		this->setHeight(cntY);

		rewind(tempStream);	//파일 스트림 위치 초기화
	}
}

void Map::constructMapData(void) {
	this->loadMapFileStream("temp01.txt");
	this->parsingMapSize();
	int coordX, coordY;
	char buffChar;
	FILE* tempStream = this->getFileStream();

	// 동적메모리 할당, 2차원 맵 구성
	int** tempArray = (int**)malloc(sizeof(int*) * this->getHeight());
	for (int i = 0; i < this->getHeight(); i++) {
		*(tempArray + i) = (int*)malloc(sizeof(int) * this->getWidth());
	}

	rewind(tempStream);

	coordX = 0;
	coordY = 0;

	while (coordY != this->getHeight()){
		fscanf_s(tempStream, "%d%c", (*(tempArray + coordY) + coordX), &buffChar);
		coordX++;
		if (buffChar == '\n') {
			coordX = 0;
			coordY++;
		}
	}

	this->setArray(tempArray);
}