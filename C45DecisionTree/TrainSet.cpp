#include "StdAfx.h"
#include "TrainSet.h"


TrainSet::TrainSet(vector<vector<string>>& a,unordered_map<string, int>& b):trainSet(a), config(b)
{
	int length = trainSet[0].size();
	for(int i=0;i<trainSet[0].size();i++){
		int continuous = config["Continuous"];
		bool rec = (continuous>>(trainSet[0].size()-i-1))&1;
		Item a(trainSet[0][i],rec);
		itemLable.push_back(a);
		itemNameTokey[trainSet[0][i]] = i;
	}
	finalNum = config["FinalClass"];
	if(finalNum>=0){
		itemLable[finalNum].isFinalClass=true;
	}else{
		itemLable[itemLable.size()+finalNum].isFinalClass=true;
		finalNum = itemLable.size() + finalNum;
	}
	vector<bool> itemvisit,linevisit;
	trainSet.erase(trainSet.begin());
	int max = itemLable.size()>trainSet.size()?itemLable.size():trainSet.size();



	for(int i = 0;i<max;i++){
		if(i<itemLable.size()){
			itemvisit.push_back(true);
		}
		if(i<trainSet.size()){
			linevisit.push_back(true);
		}
	}
	this->datetable = new DateTable(itemLable, trainSet, itemvisit, linevisit, finalNum, desicsionTree.head, itemNameTokey);
}


void TrainSet::start(){
	datetable->desicisonTreeTrain();
	cout << "ÑµÁ·½áÊø" << endl;
}

DecisionTree TrainSet::getDecisionTree(){
	return this->desicsionTree;
}

TrainSet::~TrainSet(void)
{
	delete(this->datetable);
}
