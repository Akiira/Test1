/*
 * MemoryAllocator.cpp
 *
 *  Created on: Dec 5, 2013
 *      Author: Randall Hudson
 */

#include "MemoryAllocator.h"

MemoryAllocator::MemoryAllocator()
{
	currentIndex = 0;
	allocateMemory();
}

MemoryAllocator::~MemoryAllocator()
{
	// TODO Auto-generated destructor stub
}


