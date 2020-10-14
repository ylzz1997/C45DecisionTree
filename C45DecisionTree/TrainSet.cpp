#include "StdAfx.h"
#include "TrainSet.h"


TrainSet::TrainSet(vector<vector<string>>& a,unordered_map<string, int>& b):trainSet(a), config(b)
{
	int length = trainSet[0].size();
	/*int mask = 1u<<length-1;
	int ContinuousFlag = config["Continuous"]&mask;
	*/
	for(int i=0;i<trainSet[0].size();i++){
		int continuous = config["Continuous"];
		bool rec = (continuous>>(trainSet[0].size()-i-1))&1;
		Item a(trainSet[0][i],rec);
		itemLable.push_back(a);
	}
	finalNum = config["FinalClass"];
	if(finalNum>=0){
		itemLable[finalNum].isFinalClass=true;
	}else{
		itemLable[itemLable.size()+finalNum].isFinalClass=true;
	}
	/*for (vector<Item>::iterator it = itemLable.begin(); it!= itemLable.end(); it++){
		cout.setf(ios_base::boolalpha);
		cout<<"name:"<<it->name<<" continue:"<<it->isContinuous<<" final:"<<it->isFinalClass<<endl;
	}*/
	vector<bool> itemvisit,linevisit;
	int max = itemLable.size()>trainSet.size()?itemLable.size():trainSet.size();
	for(int i = 0;i<max;i++){
		if(i<itemLable.size()){
			itemvisit.push_back(false);
		}
		if(i<trainSet.size()){
			linevisit.push_back(false);
		}
	}
	DateTable datetable(itemLable,trainSet,itemvisit,linevisit,finalNum,desicsionTree.head);
	this->datetable = &datetable;
}


void TrainSet::start(){

}

DecisionTree TrainSet::getDecisionTree(){
	return this->desicsionTree;
}

TrainSet::~TrainSet(void)
{
}
