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


double DateTable::InfoNum(unordered_map<string, ItemCount>::iterator& it, int sum)
{
	//cout << it->first << ":" << it->second.sum << endl;  //²âÊÔÓï¶Î
	double b = (double)it->second.sum / (double)sum;
	double rtn = - ((b) * (log(b) / log(2)));
	//cout << it->first << ":" << it->second << endl;  //²âÊÔÓï¶Î
	return rtn;
}

DateTable::DateTable(vector<Item>& itemLable,vector<vector<string>>& trainSet,vector<bool> itemvisit,vector<bool> linevisit,int finalNum,DecisionTreeNode* now,unordered_map<string, int>& itemNameTokey):itemLable(itemLable),trainSet(trainSet),itemvisit(itemvisit),linevisit(linevisit),finalNum(finalNum),now(now),itemNameTokey(itemNameTokey)
{
	//cout << this->linevisit.size() << endl;
	//cout << trainSet.size() << endl;
}


DateTable::~DateTable(void)
{
}

void DateTable::desicisonTreeTrain()
{
	unordered_map<string, double>* finalCount = new unordered_map<string, double>;
	int sumCount = 0;
	//cout << this->linevisit.size() << endl; //²âÊÔÓï¶Î
	for (int i = 0; i < trainSet.size(); i++) {
		if (linevisit[i]) {
			if (finalCount->count(trainSet[i][finalNum])) {
				(*finalCount)[trainSet[i][finalNum]]++;
			}
			else {
				(*finalCount)[trainSet[i][finalNum]] = 1.0;
			}
			sumCount++;
		}
	}
	double infoF = InfoNum(*finalCount, sumCount);
	delete(finalCount);
	unordered_map<string, double> H;
	for (int i = 0; i < itemLable.size(); i++) {
		if (i == finalNum) continue;
		H[itemLable[i].name] = 0.0;
		unordered_map<string, ItemCount> ict ;
		if (itemvisit[i]) {
			for (int j = 0; j < trainSet.size(); j++) {
				if (linevisit[j]) {
					/*if (!ict.count(trainSet[i][j])) {
						ict[trainSet[i][j]] = ItemCount();
					}*/
					if (ict[trainSet[j][i]].count.count(trainSet[j][finalNum])) {
						ict[trainSet[j][i]].count[trainSet[j][finalNum]]++;
					}
					else {
						ict[trainSet[j][i]].count[trainSet[j][finalNum]]=1.0;
					}
					ict[trainSet[j][i]].sum++;
				}
			}
			double infonum = 0.0;
			unordered_map<string, ItemCount>::iterator it = ict.begin();
			//cout << itemLable[i].name << endl;  //²âÊÔÓï¶Î
			while (it != ict.end()) {
				it->second.info = InfoNum(it->second.count, it->second.sum);
				H[itemLable[i].name] += ((double)it->second.sum / (double)sumCount) * it->second.info;
				infonum += InfoNum(it, sumCount);
				//cout <<"  "<< it->first << ":" << it->second.sum << endl;  //²âÊÔÓï¶Î
				/*unordered_map<string, double>::iterator it2 = it->second.count.begin();
				while (it2 != it->second.count.end()) {
					cout<<"    " << it2->first << " proper:" << it2->second << endl;   //²âÊÔÓï¶Î
					it2++;
				}*/
				it++;
			}
			//cout << itemLable[i].name << " infoNum:"<< infonum << endl;  //²âÊÔÓï¶Î
			H[itemLable[i].name] = (infoF - H[itemLable[i].name])/ infonum;
		}
	}

	unordered_map<string, double>::iterator it =  H.begin();
	unordered_map<string, double>::iterator& max = it;
	while (it != H.end()) {
		
		it++;
	}
}


