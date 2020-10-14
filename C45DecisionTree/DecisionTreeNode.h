#include "stdafx.h"
#include "Item.h"
#pragma once
using namespace std;

class DecisionTreeNode
{
public:
	enum Decision_Condition {equal,unlessthan,ungreaterthan,greaterthan,lessthan};
	Item* item;
	Decision_Condition decisionCondition;
	vector<string> value;
	string reason;
	vector<DecisionTreeNode*> child;
	DecisionTreeNode(void);
	~DecisionTreeNode(void);	
};

