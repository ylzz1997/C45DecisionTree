#include "stdafx.h"
#include "Item.h"
#pragma once
using namespace std;

class DecisionTreeNode
{
public:
	enum Decision_Condition {equal,unlessthan,ungreaterthan,greaterthan,lessthan};
	Item* item;
	Decision_Condition decisionCondition = equal;
	string reason;
	unordered_map<string,DecisionTreeNode*> child;
	DecisionTreeNode(Item* item);
	~DecisionTreeNode(void);
};

