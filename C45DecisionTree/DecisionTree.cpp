#include "StdAfx.h"
#include "DecisionTree.h"
using namespace std;

void DecisionTree::printTreeStructLoop(DecisionTreeNode* now,string nowPath)
{
	if (now == nullptr) return;
	cout << "当前路径:" << nowPath << endl;
	cout << "	当前结点信息:" << endl;
	cout << "		标签名称:" <<now->item->name <<endl;
	if(!now->item->isFinalClass) cout << "		是否是连续值:" << now->item->isContinuous << endl;
	cout << "		是否是分类节点:" << now->item->isFinalClass << endl;
	if (now->item->isFinalClass) {
		cout << "		分类结果:" << now->reason << endl;
		return;
	}
	else {
		cout << "		拥有子节点:  " ;
		deque<pair<string, DecisionTreeNode*>> a;
		for each (pair<string,DecisionTreeNode*> n in now->child)
		{
			cout << n.first << "  ";
			a.push_back(n);
		}
		cout << endl;
		for each (pair<string, DecisionTreeNode*> b in a)
		{
			printTreeStructLoop(b.second, nowPath + now->item->name+"("+b.first+")" + " -> ");
		}
	}
}

void DecisionTree::printTreeStruct(void) {
	printTreeStructLoop(head, "***Root*** -> ");
}

DecisionTree::DecisionTree(void)
{
	head = nullptr;
}

DecisionTree::DecisionTree(vector<Item*> itemLable):itemLable(itemLable)
{
	head = nullptr;
}

DecisionTree::DecisionTree(DecisionTreeNode* head,vector<Item*> itemLable) : itemLable(itemLable),head(head)
{
}

DecisionTree::~DecisionTree(void)
{

	for each (Item* i in itemLable)
	{
		delete(i);
	}
}


