#include "CycleCheckerIntersect.h"
#include "CyclecCheckerIntersectJudment.h"
#include <iostream>
void CycleCheckerIntersect::cycleCheckerIntersect()
{
	ListNode node_one_1 = ListNode(1);
	ListNode node_one_2 = ListNode(2);
	ListNode node_one_3 = ListNode(3);
	ListNode node_one_4 = ListNode(4);
	ListNode node_one_5 = ListNode(5);
	ListNode node_one_6 = ListNode(6);
	ListNode node_one_7 = ListNode(7);
	ListNode node_one_8 = ListNode(8);
	ListNode node_one_9 = ListNode(9);
	ListNode node_one_10 = ListNode(10);
	ListNode node_one_11 = ListNode(11);

	node_one_1.next = &node_one_2;
	node_one_2.next = &node_one_3;
	node_one_3.next = &node_one_4;
	node_one_4.next = &node_one_5;
	node_one_5.next = &node_one_6;
	node_one_6.next = &node_one_7;
	node_one_7.next = &node_one_8;
	node_one_8.next = &node_one_9;
	node_one_9.next = &node_one_10;
	node_one_10.next = &node_one_11;
	node_one_11.next = &node_one_7;

	ListNode node_two_1 = ListNode(1);
	ListNode node_two_2 = ListNode(2);
	ListNode node_two_3 = ListNode(3);
	ListNode node_two_4 = ListNode(4);
	ListNode node_two_5 = ListNode(5);
	ListNode node_two_6 = ListNode(6);
	ListNode node_two_7 = ListNode(7);
	ListNode node_two_8 = ListNode(8);
	ListNode node_two_9 = ListNode(9);

	node_two_1.next = &node_two_2;
	node_two_2.next = &node_two_3;
	node_two_3.next = &node_two_4;
	node_two_4.next = &node_two_5;
	node_two_5.next = &node_two_6;
	node_two_6.next = &node_one_9;

	CyclecCheckerIntersectJudment cyclecCheckerIntersectJudment;

	list<ListNode*> cyceCheckerListNode = cyclecCheckerIntersectJudment.cycleCheckerIntersect(&node_one_1, &node_two_1);

	if (cyceCheckerListNode.empty())
		cout << "抱歉，这两个链表无相交" << endl;
	if (2 == cyceCheckerListNode.size())
	{
		cout << "这两个链表是有环链表并且有两个入环节点分别是: " << endl;
		for (auto it = cyceCheckerListNode.begin(); it != cyceCheckerListNode.end(); ++it)
			cout << *it << endl;
	}
	if (1 == cyceCheckerListNode.size())
	{
		auto it = cyceCheckerListNode.begin();
		advance(it, 0);
		cout << "这两个链表是有环链表相交只有一个入环节点: " << *it << endl;
	}
}
