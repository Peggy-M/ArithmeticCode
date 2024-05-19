#include "LinkedListInterserctionChecker.h"
#include "unordered_map"
/**
* Ҫ���ж����������Ƿ��ཻ������ཻ�򷵻��ཻ�Ľڵ㣬���򷵻� NULL ��Լ������ -> ���뱣֤�ռ临�Ӷ� (O)1.
*
* - ����:������������һ���ཻҲ����ζ��������������սڵ�Ԫ����ָ��ĵ�ַһ����һ���ġ�
*
* ����һ��ͬ�������� HASH Ͱ������һ��������б����������еĽڵ�Ԫ�ط��뵽��Ͱ�У�Ȼ�������һ������һ��ͬ�ֵĽڵ�Ԫ��
*		�뵱ǰ�ı����ڵ�Ԫ����ͬ�����ʾ����������һ���ཻ�����Ҹýڵ�Ԫ��Ϊ�ཻ�Ľڵ㡣��������ռ临�Ӷ�Ϊ(O)1��
* ���������ֱ�������������¼��������ĳ��ȣ��ó��������߲�ֵ����Ȼ����������һ���д����������������ཻ�ģ���ô���յĽڵ�
* Ԫ��һ���������ͬ���������������������û���ҵ���ͬ�Ľڵ����ʾ������һ�����ཻ��
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

	//��ȡ����1 �� ����2 �ĳ��Ȳ�ֵ
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
	if (lengthDelta >= 0) //�������1 ���ȴ�������2 
	{
		while (lengthDelta != 0)
		{
			lengthDelta--;
			current_1 = current_1->next; //������ 1 ���߲�ֵ��
		}
	}
	else
	{
		while (lengthDelta != 0)
		{
			lengthDelta++;
			current_2 = current_2->next;//������ 2 ���߲�ֵ��
		}
	}

	//������������ͬʱ����ʣ����ͬ�ĳ���
	while (nullptr != current_1 && nullptr != current_2)
	{
		current_1 = current_1->next;
		current_2 = current_2->next;
		if (current_1 == current_2) //�������1 �Ľڵ�������2 �Ľڵ���ͬ�򷵻ص�ǰ�Ľڵ�
			return current_1;

	}

	return nullptr;
}
