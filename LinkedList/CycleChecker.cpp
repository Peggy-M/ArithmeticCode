#include "CycleChecker.h"
#include <unordered_map>
/**
* ���ж�һ�������Ƿ��л�,��ȷ���뻷�ڵ㣬�ռ临�Ӷ� O(1)��
*
*- ���������һ�������л�����ô�������βָ��һ���ǲ�Ϊ NULL �����뻷�ڵ��ָ��һ����ָ�������ĳһ���ڵ�ġ�
* ȷ���뻷�ڵ㣺
*    ����һ��ͬ��һ������� HASH Ͱ�ռ��������������Ͱ�е�Ԫ����ѭ�������Ĺ��̵��г��֣�
*       ���ʾ�������л���ͬʱ�ýڵ�Ϊ�뻷�ڵ㣬���ǲ�������ռ临�Ӷ�Ϊ O(1) ��Ҫ��
*    ��������ͨ������ָ�룬������ָ���趨Ϊָ���Ĳ�����ͨ�����Ĳ������б������������ָ���������������ʾ�л����������
* 		  ����һ��ָ��ָ���˿գ����ʾ�޻���
*/

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
		quick = quick->next->next;
		slow = slow->next;
	}
	return slow;
}
