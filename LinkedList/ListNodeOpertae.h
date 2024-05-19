#pragma once
#include "ListNode.h"
//元素节点的基础操作功能
class BaseLinkedList
{
private:
	int length;
	ListNode* head;
	ListNode* end;
public:
	void addNode(ListNode* node);
	void delNode(int index);
	void updateNode(ListNode* node, int index);
	ListNode* getNode(int index);
	
	BaseLinkedList() = default;


	BaseLinkedList(int length, ListNode* head, ListNode* end)
		: length(length), head(head), end(end);
};

