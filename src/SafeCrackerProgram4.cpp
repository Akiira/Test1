//============================================================================
// Name        : SafeCrackerProgram4.cpp
// Author      : Randall Hudson
// Version     : 5
// Class	   : CMPSC 462, programming assignment 2
// Description : Finds the fastest way to a target value by building a tree of all
//				 possible moves in a breadth first manner.
//============================================================================

#include <iostream>
#include <string>
#include <time.h>
#include <bitset>

#include "Digits.h"
#include "DigitsTree.h"
#include "FileBuffer.h"

using namespace std;

void findShortestPath(string name);


int main(int argc, char *argv[])
{
	clock_t t1, t2;
	t1 = clock();

	findShortestPath(argv[2]);

	t2 = clock();
	float diff((float) t2 - (float) t1);
	float seconds = diff / CLOCKS_PER_SEC;
	cout << "Running time approx: " << seconds << endl;

	//cin.get();

	return 0;
}
void findShortestPath(string name)
{
	bitset<10000000> badValues;

	FileBuffer fileBuffer(stdin, name);

	string startDigits = fileBuffer.getNextLine();
	string targetDigits = fileBuffer.getNextLine();

	Digits start(fileBuffer.getNumberOfDigits(), startDigits);
	Digits target(fileBuffer.getNumberOfDigits(), targetDigits);

	badValues.set(atoi(startDigits.c_str()),1);

	//get all the values from the buffer
	while(!fileBuffer.isAtEnd()){
		badValues.set(fileBuffer.getNextInt(), 1);
	}

	DigitsTree searchTree(start, target.getDigitsAsInt());
	searchTree.findShortestPath(badValues);
}
