#pragma once
#include "Item.h"
#include "DecisionTreeNode.h"
class DateTable
{
public:
	vector<Item>& itemLable;
	vector<vector<string>>& trainSet;
	vector<bool> itemvisit;
	vector<bool> linevisit;
	int finalNum;
	DateTable(vector<Item>& itemLable,vector<vector<string>>& trainSet,vector<bool> itemvisit,vector<bool> linevisit,int finalNum,DecisionTreeNode* now);
	~DateTable(void);
	DecisionTreeNode* now;
	void desicisonTreeTrain();
};

