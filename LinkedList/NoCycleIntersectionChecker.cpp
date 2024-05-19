#include "NoCycleIntersectionChecker.h"
#include "LinkedListInterserctionChecker.h"
#include <iostream>
void NoCycleIntersectionChecker::intersectionChecker()
{

	ListNode node_common_2 = ListNode(2);
	ListNode node_common_3 = ListNode(3);
	ListNode node_common_4 = ListNode(4);
	ListNode node_common_5 = ListNode(5);


	node_common_2.next = &node_common_3;
	node_common_3.next = &node_common_4;
	node_common_4.next = &node_common_5;
	node_common_5.next = nullptr;

	ListNode node_one_1 = ListNode(1);
	ListNode node_one_2 = ListNode(2);
	ListNode node_one_3 = ListNode(3);
	ListNode node_one_4 = ListNode(4);
	ListNode node_one_5 = ListNode(5);
	ListNode node_one_6 = ListNode(6);
	ListNode node_one_7 = ListNode(7);
	ListNode node_one_8 = ListNode(8);
	ListNode node_one_9 = ListNode(9);

	node_one_1.next = &node_one_2;
	node_one_2.next = &node_one_3;
	node_one_3.next = &node_one_4;
	node_one_4.next = &node_one_5;
	node_one_5.next = &node_one_6;
	node_one_6.next = &node_one_7;
	node_one_7.next = &node_one_8;
	node_one_8.next = &node_one_9;
	//node_one_9.next = nullptr;
	node_one_9.next = &node_common_2;

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
	//node_two_6.next = nullptr;
	node_two_6.next = &node_common_2;

	LinkedListInterserctionChecker linkedListInterserctionChecker;
	ListNode* interserctionNode_1 = linkedListInterserctionChecker.nodeInterserctionCheckerOne(&node_one_1, &node_two_1);

	std::cout << "构造的链表相交的节点【" << &node_common_2 << "】" << std::endl;

	std::cout << "调用 HASH 容器判断链表相交的方法" << std::endl;
	if (nullptr == interserctionNode_1)
		std::cout << "链表无相交" << std::endl;
	else
		std::cout << "链表相交，相交节点" << interserctionNode_1 << std::endl;

	std::cout << "调用快慢指针进行判断链表相交的方法" << std::endl;
	ListNode* interserctionNode_2 = linkedListInterserctionChecker.nodeInterserctionCheckerTwo(&node_one_1, &node_two_1);
	if (nullptr == interserctionNode_2)
		std::cout << "链表无相交" << std::endl;
	else
		std::cout << "链表相交，相交节点" << interserctionNode_2 << std::endl;
}
