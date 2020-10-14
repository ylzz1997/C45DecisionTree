#pragma once
#include "StdAfx.h"
using namespace std;
class Item
{
public:
	bool isFinalClass;
	bool isContinuous;
	string name;
	Item(string name,bool isContinuous=false,bool isFinalClass = false);
	~Item(void);
};