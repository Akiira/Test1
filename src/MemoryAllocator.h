/*
 * MemoryAllocator.h
 *
 *  Created on: Dec 5, 2013
 *      Author:
 */

#ifndef MEMORYALLOCATOR_H_
#define MEMORYALLOCATOR_H_

#include "Node.h"
#include <malloc.h>
#include <iostream>

class MemoryAllocator
{
private:
	const static int SIZE = 10000;
	int currentIndex;
	Node* memory;
public:
	MemoryAllocator();
	~MemoryAllocator();

	void getNewNode(Node*& ptr)
	{
		ptr = memory;
		memory += 1;
		currentIndex++;

		if(currentIndex == SIZE-1)
			allocateMemory();
	}

	void allocateMemory()
	{
		currentIndex = 0;
		memory = NULL;
		memory = (Node*)malloc(SIZE * sizeof(Node));
		if (memory == NULL) {std::cout<< "Memory Error!\n"; exit (2);}
		//memory = new Node[SIZE];
	}
};

#endif /* MEMORYALLOCATOR_H_ */
