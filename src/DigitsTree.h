/*
 * DigitsTree.h
 *
 *  Created on: Nov 6, 2013
 *      Author: Randall Hudson
 */

#ifndef DIGITSTREE_H_
#define DIGITSTREE_H_

#include "Node.h"
#include "Digits.h"

#include <vector>
#include <queue>
#include <bitset>


class DigitsTree
{
private:
	//TODO change as much as possible to pass by reference instead of by value



public:
	Node* root;
		int targetDigits;
		std::queue<Node*> Q;
		std::queue<Node*> orphanedNodes;
	DigitsTree();
	DigitsTree(Digits &startValue, int targetDigits);
	~DigitsTree();

	void findShortestPath();
	void findShortestPath(std::bitset<10000000>&);
	void printRoute(Node*&);

	/********************************TEST FUNCTIONS*********************/
	void toString();
};

#endif /* DIGITSTREE_H_ */
