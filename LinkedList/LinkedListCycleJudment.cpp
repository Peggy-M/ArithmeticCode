#include "LinkedListCycleJudment.h"
#include <stdio.h>
#include <iostream>
#include "ListNode.h"
#include "CycleChecker.h"

void LinkedListCycleJudment::isCycleJudment()
{

	ListNode node_1 = ListNode(1);
	ListNode node_2 = ListNode(2);
	ListNode node_3 = ListNode(3);
	ListNode node_4 = ListNode(4);
	ListNode node_5 = ListNode(5);
	ListNode node_6 = ListNode(6);
	ListNode node_7 = ListNode(7);
	ListNode node_8 = ListNode(8);
	ListNode node_9 = ListNode(9);

	node_1.next = &node_2;
	node_2.next = &node_3;
	node_3.next = &node_4;
	node_4.next = &node_5;
	node_5.next = &node_6;
	node_6.next = &node_7;
	node_7.next = &node_8;
	node_8.next = &node_9;
	node_9.next = nullptr;

	CycleChecker cycleChecker;
	ListNode* cycleNode1 = cycleChecker.judgeListIsCycleOne(&node_1);
	std::cout << "使用 HASH 桶进行判断" << std::endl;
	if (nullptr != cycleNode1)
		std::cout << "有环的节点" << cycleNode1->val << std::endl;
	else
		std::cout << "无环的节点" << std::endl;

	std::cout << "使用 快慢指针 进行判断" << std::endl;
	ListNode* cycleNode2 = cycleChecker.judgeListIsCycleTwo(&node_1);
	if (nullptr != cycleNode2)
		std::cout << "有环的节点" << cycleNode2->val << std::endl;
	else
		std::cout << "无环的节点" << std::endl;
}
