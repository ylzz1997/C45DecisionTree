#include "StdAfx.h"
#include "TrainSet.h"


TrainSet::TrainSet(vector<vector<string>>& a,unordered_map<string, int>& b):trainSet(a), config(b)
{
	int length = trainSet[0].size();
	/*int mask = 1u<<length-1;                       //≤‚ ‘∂Œ
	int ContinuousFlag = config["Continuous"]&mask;
	*/
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
	/*for (vector<Item>::iterator it = itemLable.begin(); it!= itemLable.end(); it++){        //≤‚ ‘∂Œ
		cout.setf(ios_base::boolalpha);
		cout<<"name:"<<it->name<<" continue:"<<it->isContinuous<<" final:"<<it->isFinalClass<<endl;
	}*/
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
	//cout << "item:" << itemvisit.size() << " line:" << linevisit.size()<< endl;

	//cout << linevisit.size() << endl;
	DateTable datetable(itemLable,trainSet,itemvisit,linevisit,finalNum,desicsionTree.head,itemNameTokey);
	this->datetable = new DateTable(itemLable, trainSet, itemvisit, linevisit, finalNum, desicsionTree.head, itemNameTokey);

}


void TrainSet::start(){
	datetable->desicisonTreeTrain();
}

DecisionTree TrainSet::getDecisionTree(){
	return this->desicsionTree;
}

TrainSet::~TrainSet(void)
{
	delete(this->datetable);
}
