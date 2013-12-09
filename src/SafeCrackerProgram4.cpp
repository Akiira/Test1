//============================================================================
// Name        : SafeCrackerProgram4.cpp
// Author      : Randall Hudson
// Version     : 4
// Class	   : CMPSC 462, programming assignment 2
// Description : Finds the fastest way to a target value by building a tree of all
//				 possible moves in a breadth first manner.
//============================================================================

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstdio>
#include <time.h>
#include <bitset>

#include "Digits.h"
#include "DigitsTree.h"
#include "FileBuffer.h"

using namespace std;

void findShortestPath(string name);
void findShortestPath2(string name);

int main(int argc, char *argv[])
{
	clock_t t1, t2;
	t1 = clock();

	findShortestPath2(argv[2]);

	t2 = clock();
	float diff((float) t2 - (float) t1);
	float seconds = diff / CLOCKS_PER_SEC;
	cout << "Running time approx: " << seconds << endl;

	//cin.get();

	return 0;
}
void findShortestPath(string name)
{
	bitset<10000000> badValues3;

	FileBuffer fileBuffer(stdin, name);

	string startDigits = fileBuffer.getNextLine();
	string targetDigits = fileBuffer.getNextLine();

	Digits start(fileBuffer.getNumberOfDigits(), startDigits);
	Digits target(fileBuffer.getNumberOfDigits(), targetDigits);

	badValues3.set(atoi(startDigits.c_str()),1);

	while(!fileBuffer.isAtEnd()){
		badValues3.set(fileBuffer.getNextInt(), 1);
	}

	DigitsTree t(start, target.getDigitsAsInt());
	t.findShortestPath(badValues3);
}
void findShortestPath2(string name)
{
	bitset<10000000> badValues3;

	//FileBuffer fileBuffer(stdin, name);

	//FILE* p;
	freopen(name.c_str(), "rb", stdin);
	//p = fopen (name.c_str() , "rb" );

	//stdin = p;
	cin.sync_with_stdio(false);
	string startDigits;
	string targetDigits;

	cin >> startDigits;
	cin >> targetDigits;

	cout <<"Starting digits: " << startDigits << "\n";
	cout << "Target digits: " << targetDigits << "\n";


	Digits start(startDigits.length(), startDigits);
	Digits target(startDigits.length(), targetDigits);

	badValues3.set(atoi(startDigits.c_str()),1);
	int i;
	while(!cin.eof()){

		cin >> i;
		badValues3.set(i, 1);
	}

	cout << "Last i: " << i << "\n";

	DigitsTree t(start, target.getDigitsAsInt());
	t.findShortestPath(badValues3);
}
