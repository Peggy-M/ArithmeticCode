#include "CycleChecker.h"
#include <unordered_map>
/**
* 【判断一个链表是否有环,并确定入环节点，空间复杂度 O(1)】
*
*- 分析：如果一个链表有环，那么该链表的尾指针一定是不为 NULL 并且入环节点的指针一定是指向链表的某一个节点的。
* 确定入环节点：
*    方法一：同过一个额外的 HASH 桶空间对链表遍历，如果桶中的元素在循环遍历的过程当中出现，
*       则表示该链表有环，同时该节点为入环节点，但是并不满足空间复杂度为 O(1) 的要求。
*    方法二：通过快慢指针，将两个指针设定为指定的步长，通过相差的步长进行遍历。如果两个指针最终相遇，则表示有环，如果其中
* 		  任意一个指针指向了空，则表示无环。
*/

//通过桶容器判断
ListNode* CycleChecker::judgeListIsCycleOne(ListNode* node)
{
	std::unordered_map<ListNode*, ListNode*> nodeMap;

	while (nullptr != node->next)
	{
		if (nullptr == nodeMap[node])
		{
			nodeMap[node] = node;
			node = node->next;
		}
		else
			return node;
	}
	return nullptr;
}

//通过快慢指针判断
ListNode* CycleChecker::judgeListIsCycleTwo(ListNode* node)
{
	if (nullptr == node || nullptr == node->next || nullptr == node->next->next)
		return nullptr;

	ListNode* slow = node;
	ListNode* quick = node->next->next;

	while (quick != slow)
	{
		if (nullptr == slow->next || nullptr == quick->next || nullptr == quick->next->next)
			return nullptr;
		quick = quick->next->next;
		slow = slow->next;
	}

	quick = node;
	while (quick != slow) //慢指针从相遇点开始，快指针从头开始
	{
		quick = quick->next->next;
		slow = slow->next;
	}
	return slow;
}
