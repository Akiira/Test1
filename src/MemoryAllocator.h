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
	const static int SIZE = 1000000;
	int currentIndex;
	Node* memory;
public:
	MemoryAllocator();
	~MemoryAllocator();

	void getNewNode(Node*& ptr)
	{
		ptr = &(memory[currentIndex]);
		//memory += 1;
		currentIndex++;

		if(currentIndex == SIZE)
			allocateMemory();
	}

	void allocateMemory()
	{
		currentIndex = 0;
		memory = NULL;
		memory = (Node*)calloc(SIZE, sizeof(Node));
	}
};

#endif /* MEMORYALLOCATOR_H_ */
