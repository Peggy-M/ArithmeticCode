#pragma once
#include "NodeData.h"
#include <list>
using namespace std;
class TreeTraverse
{
public:
	list<NodeData*> preorderTranverse(NodeData* head);

	list<NodeData*> infixTranverse(NodeData* head);

	list<NodeData*> behindTranverse(NodeData* head);
};

