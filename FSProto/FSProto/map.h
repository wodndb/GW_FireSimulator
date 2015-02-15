/*
* Name		: map.h
* Date		: 2015.02.14
* Author	: Jeong, Jae-U (KOREATECH CSE 2012136116)
*
* Information of this source code
* 본 시뮬레이터에서 사용할 맵을 다루기 위한 기능들을 정리한 헤더파일입니다.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAP_H
#define MAP_H

class Map{
public:

	//---- Memnber Variables ----//

	FILE* filestream;
	char* fileName;
	int width;
	int height;
	int** array;	//<- 나중에 fireNode 구조체를 원소로 갖는 2차원 배열로 변경할 예정임.

	//---- Constructor ----//

	Map(void) {
		this->setFilestream(NULL);
		this->setFileName(NULL);
		this->setWidth(0);
		this->setHeight(0);
		this->setArray(NULL);
	}

	Map(FILE* _filestream, char* _fileName, int _width, int _height, int** _array) {
		this->setFilestream(_filestream);
		this->setFileName(_fileName);
		this->setWidth(_width);
		this->setHeight(_height);
		this->setArray(_array);
	}

	//---- Copy constructor ----//
	
	Map(const Map &m) {
		this->filestream = m.filestream;
		this->height = m.height;
		this->width = m.width;
		
		//Deep Copy fileName
		this->fileName = (char*)malloc(sizeof(char) * strlen(m.fileName) + 1);
		strcpy_s(this->fileName, strlen(m.fileName) + 1, m.fileName);

		//Deep copy array
		this->array = (int**)malloc(sizeof(int*) * m.height);
		for (int i = 0; i < m.height; i++) {
			*(this->array + i) = (int*)malloc(sizeof(int) * m.width);
		}

		for (int i = 0; i < m.height; i++) {
			for (int j = 0; j < m.width; j++) {
				*(*(this->array + i) + j) = *(*(m.array + i) + j);
			}
		}
	}
	
	//---- Destructor ----//

	~Map(void) {
		if (this->getFileStream() != NULL) {
			fclose(this->getFileStream());
		}
		/*if (this->getFileName() != NULL) {
			free(this->getFileName());
		}*/
		/*if (this->getArray() != NULL) {
			free(this->getArray());
		}*/
	}


	//---- Set Functions ----//

	void setFilestream(FILE* _filestream) { this->filestream = _filestream; }
	void setFileName(char* _fileName) { this->fileName = _fileName; }	//WARNING : shallow copy
	void setWidth(int _width) { this->width = _width; }
	void setHeight(int _height) { this->height = _height; }
	void setArray(int** _array) { this->array = _array; }	//WARNING : shallow copy

	//---- Get Functions ----//

	FILE* getFileStream(void) { return this->filestream; }
	char* getFileName(void) { return this->fileName; }
	int getWidth(void) { return this->width; }
	int getHeight(void) { return this->height; }
	int** getArray(void) { return this->array; }

	//---- Other Functions ----//

	void loadMapFileStream(char* _fileName);
	void parsingMapSize(void);
	void constructMapData(void);
};

#endif /* MAP_H */