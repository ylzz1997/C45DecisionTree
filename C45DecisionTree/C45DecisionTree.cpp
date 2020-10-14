// C45DecisionTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "FileUtil.h"
#include "TrainSet.h"
using namespace std;
void initial(void);
FileUtil fileUtil;
static unordered_map<string, int> config;

int _tmain(int argc, _TCHAR* argv[])
{
	initial();
	vector<vector<string>> trainSetTemp;
	if(!fileUtil.readFileToVector(trainSetTemp)){
        cout << "���ļ�ʧ�ܣ�" << endl;
		getchar();
		return 1;
	}
	/*for (vector<vector<string>*>::iterator it = trainSetTemp->begin(); it != trainSetTemp->end(); it++){
		for (vector<string>::iterator it2 = (*it)->begin(); it2 != (*it)->end(); it2++){
			cout<<*it2<<endl;
		}
	}*/
	fileUtil.readConfig(config);
	//cout<<config["Continuous"]<<endl;
	TrainSet ts(trainSetTemp,config);
	getchar();
	return 0;
}

void initial(void){
	config["Continuous"]=0;
	config["FinalClass"]=-1;
}