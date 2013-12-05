/*
 * FileBuffer.h
 *
 *  Created on: Nov 25, 2013
 *      Author:
 */

#ifndef FILEBUFFER_H_
#define FILEBUFFER_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

//TODO add isAtEnd() which returns a boolean if iterator is at the end of buffer

class FileBuffer
{
private:
	char* buffer;
	char* iterator;
	int size;
	int numberOfLines;
	int currentPosition;

	void determineSize();
public:
	FileBuffer();
	FileBuffer(FILE * pFile);
	FileBuffer(FILE * pFile, string filename);
	~FileBuffer();

	void next(){
		iterator+= size + 2;
		currentPosition++;
	}

	bool isAtEnd(){
		if(currentPosition > numberOfLines)
			return true;
		else
			return false;
	}

	int getNextInt(){currentPosition++; return strtol(iterator, &iterator, 10);}

	string getNextLine(){
		string s(iterator, size);
		next();
		return s;
	}
	int getNumberOfDigits(){return size;}
};

#endif /* FILEBUFFER_H_ */
