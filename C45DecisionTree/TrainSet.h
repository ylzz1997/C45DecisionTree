#include "StdAfx.h"
#include "DateTable.h"
#include "DecisionTree.h"
#include "Item.h"

#pragma once
using namespace std;
class TrainSet
{
private:
	unordered_map<string, int>& config; 
	unordered_map<string,int> itemNameTokey;
	vector<vector<string>>& trainSet;
	vector<Item*> itemLable;
	DateTable* datetable;
	int finalNum;
	DecisionTree desicsionTree;
public:
	TrainSet(vector<vector<string>>& a,unordered_map<string, int>& b);
	~TrainSet(void);
	void start();
	DecisionTree getDecisionTree();
	unordered_map<string, int> getItemNameTokey();
	vector<Item*> getItemLable();
};