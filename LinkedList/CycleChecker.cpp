#include "CycleChecker.h"
#include <unordered_map>

//ͨ��Ͱ�����ж�
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

//ͨ������ָ���ж�
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
	while (quick != slow) //��ָ��������㿪ʼ����ָ���ͷ��ʼ
	{
		quick = quick->next;
		slow = slow->next;
	}
	return slow;
}
