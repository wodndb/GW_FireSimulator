/*
 * Name		: map.cpp
 * Date		: 2015.02.14
 * Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
 *
 * Information of this source code
 * map.h�� �Լ��� �����ϴ� �ҽ��ڵ��Դϴ�.
 *
 */

#include "map.h"

//---- Other Functions ----//

void Map::loadMapFileStream(char* _fileName) {
	FILE* tempStream;
	fopen_s(&tempStream, _fileName, "r");
	
	// ������ �����ϴ��� Ȯ��
	if (tempStream == NULL) {
		printf("�������� �ʴ� �����Դϴ�. ���α׷��� �����մϴ�.");
		exit(1);
	}
	// ������ �����ϴ� ��� ���� �̸��� �� ����ü�� ����Ǿ� �ִ��� Ȯ��,
	// ����Ǿ����� ���� ��� ���� �̸��� �� ����ü�� ����.
	else  {
		printf("������ ������\n");
		if (this->getFileName() == NULL) {
			printf("���ϸ� �����޸� �Ҵ���\n");
			char* tempStr = (char*)malloc(sizeof(char) * strlen(_fileName));
			printf("���ϸ� �����޸� �Ҵ� �Ϸ�(%d byte), ���ϸ� ������\n", sizeof(char) * strlen(_fileName) + 1);
			strcpy_s(tempStr, strlen(_fileName) + 1, _fileName);
			printf("���ϸ� ����Ϸ�, ������\n");
			this->setFileName(tempStr);
			printf("���ϸ� ����Ϸ�, ����Ϸ�\n");
		}
		// �ҷ��� ���� ��Ʈ���� �� ����ü�� ����.
			this->setFilestream(tempStream);
	}
}

void Map::parsingMapSize(void) {
	FILE* tempStream;
	int cntX;
	int cntY;
	char buffChar;

	if (this->getFileStream() == NULL) {
		printf("���� ��Ʈ���� �������� �ʽ��ϴ�. ���α׷��� �����մϴ�.");
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

		rewind(tempStream);	//���� ��Ʈ�� ��ġ �ʱ�ȭ
	}
}

void Map::constructMapData(void) {
	this->loadMapFileStream("temp01.txt");
	this->parsingMapSize();
	int coordX, coordY;
	char buffChar;
	FILE* tempStream = this->getFileStream();

	// �����޸� �Ҵ�, 2���� �� ����
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