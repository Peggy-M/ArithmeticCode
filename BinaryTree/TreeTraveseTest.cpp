#include "TreeTraveseTest.h"
#include "TreeTraverse.h"
#include <iostream>
using namespace std;
void TreeOpertionTest::putThreeSortThreeTravese()
{
	TreeTraverse treeTraverse;

	NodeData* head;

	NodeData nodeData_1(1);
	NodeData nodeData_2(2);
	NodeData nodeData_3(3);
	NodeData nodeData_4(4);
	NodeData nodeData_5(5);
	NodeData nodeData_6(6);
	NodeData nodeData_7(7);

	head = &nodeData_1;
	nodeData_1.left = &nodeData_2;
	nodeData_1.right = &nodeData_3;
	nodeData_2.left = &nodeData_4;
	nodeData_2.right = &nodeData_5;
	nodeData_3.left = &nodeData_6;
	nodeData_3.right = &nodeData_7;

	nodeData_4.left = nullptr;
	nodeData_4.right = nullptr;
	nodeData_5.left = nullptr;
	nodeData_5.right = nullptr;
	nodeData_6.left = nullptr;
	nodeData_6.right = nullptr;
	nodeData_7.left = nullptr;
	nodeData_7.right = nullptr;

	list<NodeData*> sortListPerorder = treeTraverse.preorderTranverse(head);
	NodeData* nodePerorder;
	if (sortListPerorder.empty())
	{
		cout << "当前无树节点" << endl;

	}
	else
	{
		cout << "先序遍历" << endl;
		for (auto it = sortListPerorder.begin(); it != sortListPerorder.end(); it++)
		{
			nodePerorder = *it;
			printf(" %d", nodePerorder->val); //  1 2 4 5 3 6 7
		}
		printf("\n");
	}
	cout << "==============================================" << endl;

	list<NodeData*> sortListInfix = treeTraverse.infixTranverse(head);
	NodeData* nodeListInfix;
	if (sortListInfix.empty())
	{
		cout << "当前无树节点" << endl;

	}
	else
	{
		cout << "中序遍历" << endl;
		for (auto it = sortListInfix.begin(); it != sortListInfix.end(); it++)
		{
			nodeListInfix = *it;
			printf(" %d", nodeListInfix->val); //  4 2 5 1 6 3 7
		}
		printf("\n");
	}
	cout << "==============================================" << endl;

	list<NodeData*> sortListBehind = treeTraverse.behindTranverse(head);
	NodeData* nodeBehind;
	if (sortListBehind.empty())
	{
		cout << "当前无树节点" << endl;

	}
	else
	{
		cout << "后序遍历" << endl;
		for (auto it = sortListBehind.begin(); it != sortListBehind.end(); it++)
		{
			nodeBehind = *it; // 4 5 2 6 7 3 1
			printf(" %d", nodeBehind->val); //  
		}
	}
}
