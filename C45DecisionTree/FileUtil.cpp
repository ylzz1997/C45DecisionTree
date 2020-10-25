#include "StdAfx.h"
#include "FileUtil.h"

using namespace std;
FileUtil::FileUtil(void)
{
}


FileUtil::~FileUtil(void)
{
}

bool FileUtil::readFileToVector(vector<vector<string>>& a){
	ifstream csvInput(TRAINSET_FILEURL);
	if (!csvInput)
    {
		csvInput.close();
		return false;
    }
    string line;
	int i = 0;
	while (getline(csvInput, line)){
		//cout<<line<<endl;
		a.push_back(vector<std::string>());
		istringstream sin(line);
		string field;
		while(getline(sin, field, ',')){
			a[i].push_back(field);
			//cout<<field<<endl;
		}
		i++;
	}
	csvInput.close();
	return true;
}

bool FileUtil::readConfig(unordered_map<string, int>& config){
	ifstream iniInput(CONFIG_FILEURL);
	if (!iniInput)
    {
		iniInput.close();
		return false;
    }
	string line;
	while (getline(iniInput, line)){
		istringstream sin(line);
		string field,key;
		int value;
		int i=0;
		while(getline(sin, field, '=')){
			if(i==0){
				key=field;
			}else if(i==1){
				value = atoi(field.c_str());
			}else{
				break;
			}
			i++;
			//cout<<field<<endl;
		}
		iniInput.close();
		config[key]=value;
	}
	return true;
}