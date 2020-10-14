#include "StdAfx.h"
#include "DateTable.h"


DateTable::DateTable(vector<Item>& itemLable,vector<vector<string>>& trainSet,vector<bool> itemvisit,vector<bool> linevisit,int finalNum,DecisionTreeNode* now):itemLable(itemLable),trainSet(trainSet),itemvisit(itemvisit),linevisit(linevisit),finalNum(finalNum),now(now)
{
	
}


DateTable::~DateTable(void)
{
}

void DateTable::desicisonTreeTrain()
{

}
