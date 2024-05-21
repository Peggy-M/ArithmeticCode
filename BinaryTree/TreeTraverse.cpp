#include "TreeTraverse.h"

/**
*  �����������нڵ㣬Ҫ��ʹ�� �ȡ��С��� �������
*  Ҫ��һ: �ռ临�Ӷ�O(1)
*
*/
list<NodeData*> sortNodeDataRreorder;
list<NodeData*> sortNodeDataIinfix;
list<NodeData*> sortNodeDataBehind;

list<NodeData*> TreeTraverse::preorderTranverse(NodeData* head)
{
	NodeData* current = head;
	if (nullptr == current)return sortNodeDataRreorder;
	sortNodeDataRreorder.push_back(current);
	this->preorderTranverse(current->left);
	this->preorderTranverse(current->right);
	return sortNodeDataRreorder;
}

list<NodeData*> TreeTraverse::infixTranverse(NodeData* head)
{
	NodeData* current = head;
	if (nullptr == current)return sortNodeDataIinfix;
	this->infixTranverse(current->left);
	sortNodeDataIinfix.push_back(current);
	this->infixTranverse(current->right);
	return sortNodeDataIinfix;
}

list<NodeData*> TreeTraverse::behindTranverse(NodeData* head)
{
	NodeData* current = head;
	if (nullptr == current)return sortNodeDataBehind;
	this->behindTranverse(current->left);
	this->behindTranverse(current->right);
	sortNodeDataBehind.push_back(current);
	return sortNodeDataBehind;
}
