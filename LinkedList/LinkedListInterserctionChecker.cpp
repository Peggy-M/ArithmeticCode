#include "LinkedListInterserctionChecker.h"
#include "unordered_map"
/**
* 要求：判断两个链表是否相交，如果相交则返回相交的节点，否则返回 NULL 。约束条件 -> 必须保证空间复杂度 (O)1.
*
* - 分析:首先两个链表一旦相交也就意味这两个链表的最终节点元素所指向的地址一定是一样的。
*
* 方法一：同样的利用 HASH 桶对任意一个链表进行遍历，将所有的节点元素放入到该桶中，然后遍历另一个链表，一旦同种的节点元素
*		与当前的遍历节点元素相同，则表示这两个链表一定相交，并且该节点元素为相交的节点。【不满足空间复杂度为(O)1】
* 方法二：分别遍历两个链表记录两个链表的长度，让长链表先走差值步，然后两个链表一起编写，如果两个链表是相交的，那么最终的节点
* 元素一定会出现相同，如果遍历完整个链表，都没有找到相同的节点则表示该链表一定不相交。
*
*/
ListNode* LinkedListInterserctionChecker::nodeInterserctionCheckerOne(ListNode* node_1, ListNode* node_2)
{
	std::unordered_map<ListNode*, ListNode*> nodeMap;
	ListNode* current_1 = node_1;
	ListNode* current_2 = node_2;

	while (nullptr != current_1 && nullptr != current_1->next)
	{
		nodeMap[current_1] = current_1;
		current_1 = current_1->next;
	}

	while (nullptr != current_2 && nullptr != current_2->next)
	{
		if (nullptr != nodeMap[current_2])
			return current_2;
		current_2 = current_2->next;

	}

	return nullptr;
}

ListNode* LinkedListInterserctionChecker::nodeInterserctionCheckerTwo(ListNode* node_1, ListNode* node_2)
{
	ListNode* current_1 = node_1;
	ListNode* current_2 = node_2;

	int lengthDelta = 0;

	//获取链表1 与 链表2 的长度差值
	while (nullptr != current_1 && nullptr != current_1->next)
	{
		lengthDelta++;
		current_1 = current_1->next;
	}
	while (nullptr != current_2 && nullptr != current_2->next)
	{
		lengthDelta--;
		current_2 = current_2->next;

	}

	current_1 = node_1;
	current_2 = node_2;
	if (lengthDelta >= 0) //如果链表1 长度大于链表2 
	{
		while (lengthDelta != 0)
		{
			lengthDelta--;
			current_1 = current_1->next; //让链表 1 先走差值步
		}
	}
	else
	{
		while (lengthDelta != 0)
		{
			lengthDelta++;
			current_2 = current_2->next;//让链表 2 先走差值步
		}
	}

	//最终两个链表同时走完剩余相同的长度
	while (nullptr != current_1 && nullptr != current_2)
	{
		current_1 = current_1->next;
		current_2 = current_2->next;
		if (current_1 == current_2) //如果链表1 的节点与链表2 的节点相同则返回当前的节点
			return current_1;

	}

	return nullptr;
}
