#include "StdAfx.h"
#include "DateTable.h"


double DateTable::InfoNum(vector<int> a, int sum)
{

	return 0.0;
}

DateTable::DateTable(vector<Item>& itemLable,vector<vector<string>>& trainSet,vector<bool> itemvisit,vector<bool> linevisit,int finalNum,DecisionTreeNode*& now):itemLable(itemLable),trainSet(trainSet),itemvisit(itemvisit),linevisit(linevisit),finalNum(finalNum),now(now)
{
	
}


DateTable::~DateTable(void)
{
}

void DateTable::desicisonTreeTrain()
{
	unordered_map<string, int> count;
	int sumCount = 0;
	for (int i = 0; i < trainSet.size(); i++) {
		if (linevisit[i]) {
			//if(count[trainSet[i])
			sumCount++;
		}
	}
}


