/*
 * DigitsTree.cpp
 *
 *  Created on: Nov 6, 2013
 *      Author: Randall Hudson
 */

#include "DigitsTree.h"
#include "Digits.h"
#include "Node.h"
#include "MemoryAllocator.h"

#include <iostream>
#include <cstddef>
#include <vector>
#include <stack>
#include <sstream>
typedef Node* nodePointer;
DigitsTree::DigitsTree()
{
	root = nullptr;
	targetDigits = -1;
}

DigitsTree::DigitsTree(Digits &startValue, int targetDigits)
{
	root = new Node(startValue, nullptr);
	this->targetDigits = targetDigits;

	Q.push(root);
}
DigitsTree::~DigitsTree()
{
//	while(!orphanedNodes.empty())
//	{
//		Node* p = orphanedNodes.front();
//		orphanedNodes.pop();
//
//		delete p;
//	}
}

//TODO add pre and post conditions
void DigitsTree::findShortestPath(std::bitset<10000000>& badValues2)
{
	//TODO add check for very first state being target state
	//TODO move where badvalues is checked to early pos to avoid cost of uneeded nodes
	int moves = 0;
	int numberOfChildren = root->data.getCountOfChildren();
	std::vector<Digits> children(16);
	MemoryAllocator memAllocator;

	while(!Q.empty())
	{
		int size = Q.size();//get the number of nodes on the previous level
		moves++; 			//each level in the tree represents a move

		for(int i = 0; i < size; i++) //For each node on the previous level make all its children
		{
			Node* parent = Q.front();
			Q.pop();

			parent->data.getAllPossibleChildren(children);

			for(int j = 0; j < numberOfChildren; j++)
			{
				Node* child;
				if(j % 2 == 0)
				{
					//child = new Node(children[j], parent, 'U', j/2);
					memAllocator.getNewNode(child);
					child->setAll(children[j], parent, 'U', j/2);
				}
				else
				{
					//child = new Node(children[j], parent, 'D', j/2);
					memAllocator.getNewNode(child);
					child->setAll(children[j], parent, 'D', j/2);
				}


				int value = children[j].getDigitsAsInt();
				//orphanedNodes.push(child);

				if(!badValues2[value])
				{
					badValues2.set(value, 1);
					Q.push(child);

					if(targetDigits == value)
					{
						printRoute(child);
						std::cout<< "Shortest path is " << moves << " moves\n";

						goto DONE;//This goto lets me avoid overhead of additional if-then statements
					}
				}

			}//End children loop
		}//End parent loop
	}//End Q loop

	std::cout << "-1\n";//Only outputted if value is not found

	DONE:;

}
void DigitsTree::printRoute(nodePointer& p)
{
	while(p != root && p != nullptr)
	{
		p->parent->next = p;
		p = p->parent;
	}

	while(p != nullptr)
	{
		std::cout << p->operation << p->index << " " << p->data.getDigits() << "\n";
		p = p->next;
	}

}

