#include "CycleChecker.h"
#include <unordered_map>

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
		quick = quick->next;
		slow = slow->next;
	}
	return slow;
}
