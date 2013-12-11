/*
 * FileBuffer.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: Randall Hudson
 */

#include "FileBuffer.h"

using namespace std;


void FileBuffer::determineSize()
{
	size = 0;
	while(true)
	{
		if(buffer[size] == '\n')
			break;

		size++;
	}
	size--;
}

//Part of this function was taken from the example at
// http://www.cplusplus.com/reference/cstdio/fread/?kw=fread
FileBuffer::FileBuffer(FILE* pFile)
{
	buffer = 0;
	iterator = 0;
	size = -1;
	//size_t result;
	long lSize;

	//pFile = fopen ( "compete6.txt" , "rb" );
	//if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);

	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	//if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

	// copy the file into the buffer:
	fread (buffer,1,lSize,pFile);
	//if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

	fclose(pFile);

	determineSize();
	iterator = buffer;

	numberOfLines = lSize / (size + 2);
}

//Part of this function was taken from the example at
// http://www.cplusplus.com/reference/cstdio/fread/?kw=fread
FileBuffer::FileBuffer(FILE* pFile, string filename)
{
	buffer = 0; currentPosition = 0;
	iterator = 0;
	size = -1;
	//size_t result;
	long lSize;

	pFile = fopen ( filename.c_str() , "rb" );
	//if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);

	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	//if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

	// copy the file into the buffer:
	fread (buffer,1,lSize,pFile);
	//if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

	fclose(pFile);

	determineSize();
	iterator = buffer;

	numberOfLines = lSize / (size + 2);

}

FileBuffer::~FileBuffer()
{
	//free (buffer); //TODO determine if i should leave this out or not
}

