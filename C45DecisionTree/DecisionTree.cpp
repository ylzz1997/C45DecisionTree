#include "StdAfx.h"
#include "DecisionTree.h"
using namespace std;

void DecisionTree::printTreeStructLoop(DecisionTreeNode* now,string nowPath)
{
	if (now == nullptr) return;
	cout << "��ǰ·��:" << nowPath << endl;
	cout << "	��ǰ�����Ϣ:" << endl;
	cout << "		��ǩ����:" <<now->item->name <<endl;
	if(!now->item->isFinalClass) cout << "		�Ƿ�������ֵ:" << now->item->isContinuous << endl;
	cout << "		�Ƿ��Ƿ���ڵ�:" << now->item->isFinalClass << endl;
	if (now->item->isFinalClass) {
		cout << "		������:" << now->reason << endl;
		return;
	}
	else {
		cout << "		ӵ���ӽڵ�:  " ;
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


