#include "stdafx.h"
#include "Item.h"
#pragma once
using namespace std;

class DecisionTreeNode
{
public:
	Item* item;
	string reason;
	unordered_map<string,DecisionTreeNode*> child;
	DecisionTreeNode(Item* item);
	~DecisionTreeNode(void);
};