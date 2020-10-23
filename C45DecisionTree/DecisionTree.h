#include "stdafx.h"
#pragma once
#include "DecisionTreeNode.h"

class DecisionTree
{
private:
	void printTreeStructLoop(DecisionTreeNode* now, string nowPath);
public:
	void printTreeStruct(void);
	DecisionTree(void);
	DecisionTree(vector<Item*> itemLable);
	DecisionTree(DecisionTreeNode* head, vector<Item*> itemLable);
	~DecisionTree(void);
	DecisionTreeNode* head;
	vector<Item*> itemLable;
};

