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
	fileUtil.readConfig(config);
	TrainSet ts(trainSetTemp, config);
	ts.start();
	DecisionTree dt = ts.getDecisionTree();
 	dt.printTreeStruct();
	getchar();
	return 0;
}

void initial(void){
	config["Continuous"]=0;
	config["FinalClass"]=-1;
}