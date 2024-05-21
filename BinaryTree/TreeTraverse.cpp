#include "TreeTraverse.h"

/**
*  遍历树的所有节点，要求使用 先、中、后 序遍历。
*  要求一: 空间复杂度O(1)
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
