#pragma once
#include "Item.h"
#include "DecisionTreeNode.h"
class DateTable
{
private:
	vector<Item>& itemLable;
	vector<vector<string>>& trainSet;
	vector<bool> itemvisit;
	vector<bool> linevisit;
	int finalNum;
	DecisionTreeNode*& now;
	double InfoNum(vector<int> a,int sum);
public:
	DateTable(vector<Item>& itemLable,vector<vector<string>>& trainSet,vector<bool> itemvisit,vector<bool> linevisit,int finalNum,DecisionTreeNode*& now);
	~DateTable(void);
	void desicisonTreeTrain();
};

