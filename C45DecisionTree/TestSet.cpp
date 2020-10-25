#include "stdafx.h"
#include "TestSet.h"

	

string TestSet::patternOneTestSetLoop(vector<string>& item, DecisionTreeNode* dtn)
{
	if (dtn == nullptr) return "没找到合适的匹配项，请检查训练集是否有冲突或测试集使用了未被训练的项";
	if (dtn->item->isFinalClass) return dtn->reason;
	else {
		bool a = itemNameTokey.count(dtn->item->name);
		if (!a) return "测试集与决策树不匹配";
		string value = item[itemNameTokey[dtn->item->name]];
		if (dtn->item->isContinuous) {
			if (atof(value.c_str()) <= atof(dtn->reason.c_str())) {
				return patternOneTestSetLoop(item, dtn->child["<="+ dtn->reason]);
			}
			else {
				return patternOneTestSetLoop(item, dtn->child[">" + dtn->reason]);
			}
		}
		else {
			return patternOneTestSetLoop(item, dtn->child[value]);
		}
	}
}

TestSet::TestSet()
{
}

TestSet::TestSet(vector<vector<string>> items)
{
	for (int i = 0; i < items[0].size(); i++) {
		itemNameTokey[items[0][i]] = i;
	}
	items.erase(items.begin());
	this->items = items;
}

TestSet::TestSet(unordered_map<string, int> itemNameTokey):itemNameTokey(itemNameTokey)
{
}

TestSet::TestSet(vector<vector<string>> items, unordered_map<string, int> itemNameTokey) :items(items), itemNameTokey(itemNameTokey)
{

}

TestSet::~TestSet()
{
}

string TestSet::patternOneTestSet(vector<string> item, DecisionTree dt)
{
	return patternOneTestSetLoop(item,dt.head);
}

vector<string> TestSet::patternTestSet(DecisionTree dt)
{
	vector<string> rtn;
	for each (vector<string> item in items)
	{
		rtn.push_back(patternOneTestSet(item, dt));
	}
	return rtn;
}