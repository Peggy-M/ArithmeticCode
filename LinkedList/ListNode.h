#pragma once
// ����ڵ�
class ListNode
{
public:
	int val;
	ListNode* next;
	

	ListNode() = default;

	ListNode(int val)
		: val(val), next(nullptr)
	{
	}
};

