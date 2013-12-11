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
	Node* root;
	int targetDigits;
	std::queue<Node*> Q;

public:
	DigitsTree(Digits &startValue, int targetDigits);
	~DigitsTree();

	void findShortestPath(std::bitset<10000000>&);
	void printRoute(Node*&);

};

#endif /* DIGITSTREE_H_ */
