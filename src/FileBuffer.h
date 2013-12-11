/*
 * FileBuffer.h
 *
 *  Created on: Nov 25, 2013
 *      Author: Randall Hudson
 */

#ifndef FILEBUFFER_H_
#define FILEBUFFER_H_

#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

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
	FileBuffer(FILE * pFile);
	FileBuffer(FILE * pFile, string filename);
	~FileBuffer();

	inline bool isAtEnd();
	inline int getNextInt();
	inline string getNextLine();
	inline int getNumberOfDigits();
};
inline int FileBuffer::getNumberOfDigits()
{
	return size;
}
inline int FileBuffer::getNextInt()
{
	currentPosition++;
	return strtol(iterator, &iterator, 10);
}
inline string FileBuffer::getNextLine()
{
	string s(iterator, size);
	iterator += size + 2;
	currentPosition++;
	return s;
}
inline bool FileBuffer::isAtEnd()
{
	return (currentPosition > numberOfLines);
}

#endif /* FILEBUFFER_H_ */
