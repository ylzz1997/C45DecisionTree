#pragma once
#include "Item.h"
#include "DecisionTreeNode.h"
class DateTable
{
private:
	vector<Item>& itemLable;
	vector<vector<string>>& trainSet;
	unordered_map<string, int>& itemNameTokey;
	vector<bool> itemvisit;
	vector<bool> linevisit;
	int finalNum;
	DecisionTreeNode*& now;
	double InfoNum(unordered_map<string, double>& a, int sum);
public:
	DateTable(vector<Item>& itemLable,vector<vector<string>>& trainSet,vector<bool> itemvisit,vector<bool> linevisit,int finalNum,DecisionTreeNode*& now, unordered_map<string, int>& itemNameTokey);
	~DateTable(void);
	void desicisonTreeTrain();
};

