#pragma once
#include"stdafx.h"
#include"DecisionTree.h"
using namespace std;
class TestSet
{
private:
	string patternOneTestSetLoop(vector<string>& item, DecisionTreeNode* dtn);
	unordered_map<string, int> itemNameTokey;
	vector<vector<string>> items;
public:
	TestSet();
	TestSet(vector<vector<string>> items);

	TestSet(unordered_map<string, int> itemNameTokey);
	TestSet(vector<vector<string>> items, unordered_map<string, int> itemNameTokey);
	~TestSet();
	string patternOneTestSet(vector<string> item, DecisionTree dt);
};