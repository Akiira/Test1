/*
 * DigitsTree.h
 *
 *  Created on: Nov 6, 2013
 *      Author: Randall Hudson
 */

#ifndef DIGITSTREE_H_
#define DIGITSTREE_H_

#include "Digits.h"
#include <unordered_set>
#include <tr1/unordered_set>
#include <vector>
#include <queue>
#include <bitset>


class DigitsTree
{
private:
	//TODO change as much as possible to pass by reference instead of by value
	struct Node{
		Digits data;
		char operation;
		int index;
		Node* parent;
		Node(): data(),operation('!'), index(-1), parent(nullptr) {}
		Node(Digits &d, Node* p) : data(d), operation('!'), index(-1), parent(p){}
		Node(Digits &d, Node* p, char op, int in) : data(d), operation(op), index(in), parent(p){}
	};

	typedef Node* nodePointer;

	Node* root;
	int targetDigits;
	std::queue<Node*> Q;
	std::queue<Node*> orphanedNodes;

public:
	DigitsTree();
	DigitsTree(Digits &startValue, int targetDigits);
	~DigitsTree();

	void findShortestPath();
	void findShortestPath(std::bitset<10000000>&);
	void printRoute(nodePointer&);

	/********************************TEST FUNCTIONS*********************/
	void toString();
};

#endif /* DIGITSTREE_H_ */
