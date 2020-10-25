#pragma once
#include "StdAfx.h"
#define TRAINSET_FILEURL "trainset.csv"
#define CONFIG_FILEURL "config.ini"
using namespace std;

class FileUtil
{
public:
	FileUtil(void);
	~FileUtil(void);
	bool readFileToVector(vector<vector<string>>& a);
	bool readFileToVector(vector<vector<string>>& a, string ts);
	bool readConfig(unordered_map<string, int>& config);
	bool readConfig(unordered_map<string, int>& config, string cf);
};

