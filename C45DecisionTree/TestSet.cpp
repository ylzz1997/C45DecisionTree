#include "stdafx.h"
#include "TestSet.h"

	

string TestSet::patternOneTestSetLoop(vector<string>& item, DecisionTreeNode* dtn)
{
	if (dtn == nullptr) return "û�ҵ����ʵ�ƥ�������ѵ�����Ƿ��г�ͻ����Լ�ʹ����δ��ѵ������";
	if (dtn->item->isFinalClass) return dtn->reason;
	else {
		bool a = itemNameTokey.count(dtn->item->name);
		if (!a) return "���Լ����������ƥ��";
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