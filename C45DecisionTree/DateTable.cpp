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

double DateTable::InfoNum(unordered_map<string, double>& a, int sum, unordered_map<string, vector<pair<string, string>>>& pure,string first,string second)
{
	unordered_map<string, double>::iterator it = a.begin();
	double rtn = 0;
	while (it != a.end()) {
		pair<string, string> temp(second,it->first);
		it->second = it->second / (double)sum;
		if ((char)it->second) {
			pure[first].push_back(temp);
		}
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

double DateTable::InfoNum(ItemCount& it, int sum)
{
	//cout << it->first << ":" << it->second.sum << endl;  //²âÊÔÓï¶Î
	double b = (double)it.sum / (double)sum;
	double rtn = -((b) * (log(b) / log(2)));
	//cout << it->first << ":" << it->second << endl;  //²âÊÔÓï¶Î
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
	unordered_map<string, double>* finalCount = new unordered_map<string, double>;
	int sumCount = 0;
	//cout << this->linevisit.size() << endl; //²âÊÔÓï¶Î
	for (int i = 0; i < trainSet.size(); i++) {
		//cout << "´Ë¿ÌÐÐÈ¨ÏÞ:" << linevisit[i] << endl;  //²âÊÔ×Ö¶Î
		if (linevisit[i]) {
			//	cout << " ´Ë¿Ì·ÃÎÊÐÐ:" << i << endl;  //²âÊÔ×Ö¶Î
			if (finalCount->count(trainSet[i][finalNum])) {
				(*finalCount)[trainSet[i][finalNum]]++;
			}
			else {
				(*finalCount)[trainSet[i][finalNum]] = 1.0;
			}
			sumCount++;
		}
	}
	//cout<<"´ËÊ±ÐÐ×ÜÊý:"<< sumCount << endl;
	if (sumCount == 0) {delete(finalCount); return; }
	double infoF = InfoNum(*finalCount, sumCount);
	delete(finalCount);
	unordered_map<string, double> H;
	unordered_map<string,vector<pair<string,string>>> pure;
	unordered_map<string,vector<bool>> value;
	unordered_map<string, string> continueVlitem;
	pair<string, double>  max("",0);
	for (int i = 0; i < itemLable.size(); i++) {
		if (i == finalNum) continue;
		if (itemvisit[i]) {
			H[itemLable[i].name] = 0.0;	
			if (!itemLable[i].isContinuous) {
				unordered_map<string, ItemCount> ict;
				for (int j = 0; j < trainSet.size(); j++) { 
					if (linevisit[j]) {
						if (ict[trainSet[j][i]].count.count(trainSet[j][finalNum])) {
							ict[trainSet[j][i]].count[trainSet[j][finalNum]]++;
						}
						else {
							ict[trainSet[j][i]].count[trainSet[j][finalNum]] = 1.0;
						}
						ict[trainSet[j][i]].sum++;
					}
				}
				double infonum = 0.0;
				unordered_map<string, ItemCount>::iterator it = ict.begin();
				while (it != ict.end()) {
					it->second.info = InfoNum(it->second.count, it->second.sum, pure, itemLable[i].name, it->first);
					H[itemLable[i].name] += ((double)it->second.sum / (double)sumCount) * it->second.info;
					infonum += InfoNum(it, sumCount);
					it++;
				}
				H[itemLable[i].name] = (infoF - H[itemLable[i].name]) / infonum;
			}
			else {
				vector<double> continueValue; 
				for (int j = 0; j < trainSet.size(); j++) {
					continueValue.push_back(atof(trainSet[j][i].c_str()));
				}
				sort(continueValue.begin(), continueValue.end());
				for (int j = 0; j < continueValue.size()-1; j++) {
					continueValue[j] = (continueValue[j] + continueValue[j + 1]) / 2;
				}
				continueValue.pop_back();
				vector<ItemCount[2]> ict;
				double maxH = 0;
				double nowDevide = 0;
				for each (double n in continueValue)
				{
					ItemCount ic[2];
					for (int j = 0; j < trainSet.size(); j++) {
						if (linevisit[j]) {
							char b = atof(trainSet[j][i].c_str()) > n;
							ic[b].sum++;
							if (ic[b].count.count(trainSet[j][finalNum])) {
								ic[b].count[trainSet[j][finalNum]]++;
							}
							else {
								ic[b].count[trainSet[j][finalNum]] = 1.0;
							}
						}
					}
					ic[0].info = InfoNum(ic[0].count, ic[0].sum, pure, itemLable[i].name, "<="+to_string(n));
					ic[1].info = InfoNum(ic[0].count, ic[0].sum, pure, itemLable[i].name, ">"+to_string(n));
					double Htemp = 0;
					double infonum = 0.0;
					for each (ItemCount t in ic)
					{
						Htemp += ((double)t.sum / (double)sumCount) *t.info;
						infonum += InfoNum(t, sumCount);
					}
					Htemp = (infoF - H[itemLable[i].name]) / infonum;
					if (Htemp >= maxH) {
						maxH = Htemp;
						nowDevide = n;
					}
				}
				continueVlitem[itemLable[i].name] = nowDevide;
				H[itemLable[i].name] = maxH;
			}
			pair<string, double>  temp(itemLable[i].name,H[itemLable[i].name]);
			max = temp.second > max.second ? temp : max;
			cout << itemLable[i].name << " IGR:" << H[itemLable[i].name] << endl;  //²âÊÔ×Ö¶Î
		}
	}

	if (H.size() == 0) return;
	cout << max.first<< "(×î´óÖµ):"<<max.second << endl;  //²âÊÔ×Ö¶Î
	now = new DecisionTreeNode(&itemLable[itemNameTokey[max.first]]);
	vector<bool> aitemvisit = itemvisit;
	aitemvisit[itemNameTokey[max.first]]=false;
	for (vector<pair<string,string>>::iterator it = pure[max.first].begin(); it!= pure[max.first].end(); it++) {
		now->child[it->first] = new DecisionTreeNode(&itemLable[finalNum]);
		now->child[it->first]->reason = it->second;
		//cout << it->first << "·ÖÀà½á¹ûÎª:" << it->second << endl;  //²âÊÔ×Ö¶Î
	}

	for (int i = 0; i < trainSet.size(); i++){
		if (itemLable[itemNameTokey[max.first]].isContinuous) {
			double devideItem = atof(continueVlitem[max.first].c_str());
			if (!now->child.count("<="+continueVlitem[max.first])) {
				if (!value.count(trainSet[i][itemNameTokey[max.first]])) {
					for (int d = 0; d < linevisit.size(); d++) {
						value["<=" + continueVlitem[max.first]].push_back(false);
					}
				}
				if(atof(trainSet[i][itemNameTokey[max.first]].c_str()) <= devideItem) value["<=" + continueVlitem[max.first]][i] = true;
			}
			if (!now->child.count(">" + continueVlitem[max.first])) {
				if (!value.count(trainSet[i][itemNameTokey[max.first]])) {
					for (int d = 0; d < linevisit.size(); d++) {
						value[">" + continueVlitem[max.first]].push_back(false);
					}
				}
				if (atof(trainSet[i][itemNameTokey[max.first]].c_str()) > devideItem) value[">" + continueVlitem[max.first]][i] = true;
			}
		}
		else
		{
			if (!value.count(trainSet[i][itemNameTokey[max.first]])) {
				for (int d = 0; d < linevisit.size(); d++) {
					value[trainSet[i][itemNameTokey[max.first]]].push_back(false);
				}
			}
			value[trainSet[i][itemNameTokey[max.first]]][i] = true;
		}
	}

	for (unordered_map<string, vector<bool>>::iterator it = value.begin(); it != value.end(); it++) {
		if (!now->child.count(it->first)) {
			vector<bool> alinevisit = linevisit;
			for(int n=0;n<alinevisit.size();n++)
			{
				alinevisit[n] = alinevisit[n]&&(it->second)[n];
			}
			if (H.size() != 1) {
				DateTable next(itemLable, trainSet, aitemvisit, alinevisit, finalNum, now->child[it->first], itemNameTokey);
				next.desicisonTreeTrain();
			}
		}
	}
}