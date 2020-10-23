#pragma once
#include "Item.h"
#include"ItemCount.h"
#include "DecisionTreeNode.h"
using namespace std;
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
	double InfoNum(unordered_map<string, double>& a, int sum, unordered_map<string, vector<pair<string, string>>>& pure,string first,string second);
	double DateTable::InfoNum(unordered_map<string, ItemCount>::iterator& it, int sum);
	double InfoNum(ItemCount& it, int sum);

public:
	DateTable(vector<Item>& itemLable,vector<vector<string>>& trainSet,vector<bool> itemvisit,vector<bool> linevisit,int finalNum,DecisionTreeNode*& now, unordered_map<string, int>& itemNameTokey);
	~DateTable(void);
	void desicisonTreeTrain();
};

