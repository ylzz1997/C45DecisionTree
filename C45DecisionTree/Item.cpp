#include "StdAfx.h"
#include "Item.h"


Item::Item(string name,bool isContinuous,bool isFinalClass)
{
	this->name = name;
	this->isFinalClass = isFinalClass;
	this->isContinuous = isContinuous;
}


Item::~Item(void)
{
}
