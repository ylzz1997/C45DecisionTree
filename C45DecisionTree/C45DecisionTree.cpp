// C45DecisionTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "FileUtil.h"
#include "TrainSet.h"
#include "TestSet.h"
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
	vector<vector<string>> testSetTemp;
	if (!fileUtil.readFileToVector(testSetTemp,"testset.csv")) {
		cout << "���ļ�ʧ�ܣ�" << endl;
		getchar();
		return 1;
	}
	TestSet tsa(testSetTemp);
	vector<string> rtn = tsa.patternTestSet(dt);
	for each (string var in rtn)
	{
		cout << var << endl;
	}
	getchar();
	return 0;
}

void initial(void){
	config["Continuous"]=0;
	config["FinalClass"]=-1;
}