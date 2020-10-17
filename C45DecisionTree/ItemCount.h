#include"stdafx.h"
#pragma once
using namespace std;
class ItemCount
{
public:
	unordered_map<string, double> count;
	int sum = 0;
	double info = 0.0;
	ItemCount(void);
	~ItemCount(void);
};

