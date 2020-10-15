#include "StdAfx.h"
#include "DateTable.h"


double DateTable::InfoNum(unordered_map<string, double>& a, int sum)
{
	unordered_map<string, double>::iterator it = a.begin();
	double rtn = 0;
	while (it != a.end()) {
		it->second = it->second / (double)sum;
		rtn -= (it->second) * (log(it->second) / log(2));
		//cout << it->first << ":" << it->second << endl;  //²âÊÔÓï¶Î
		it++;
	}
	return rtn;
}

DateTable::DateTable(vector<Item>& itemLable,vector<vector<string>>& trainSet,vector<bool> itemvisit,vector<bool> linevisit,int finalNum,DecisionTreeNode*& now,unordered_map<string, int>& itemNameTokey):itemLable(itemLable),trainSet(trainSet),itemvisit(itemvisit),linevisit(linevisit),finalNum(finalNum),now(now),itemNameTokey(itemNameTokey)
{
	//cout << this->linevisit.size() << endl;
	//cout << trainSet.size() << endl;
}


DateTable::~DateTable(void)
{
}

void DateTable::desicisonTreeTrain()
{
	unordered_map<string, double> finalCount;
	int sumCount = 0;
	//cout << this->linevisit.size() << endl;
	for (int i = 0; i < trainSet.size(); i++) {
		if (linevisit[i]) {
			if (finalCount.count(trainSet[i][finalNum])) {
				finalCount[trainSet[i][finalNum]]++;
			}
			else {
				finalCount[trainSet[i][finalNum]] = 1.0;
			}
			sumCount++;
		}
	}
	cout << InfoNum(finalCount, sumCount) << endl;
}


