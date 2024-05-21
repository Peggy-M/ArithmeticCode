#include "CyclecCheckerIntersectJudment.h"
#include "CycleChecker.h"
#include "LinkedListInterserctionChecker.h"


/**
* 判断两个链表是否相交并且返回相交点
* 分析:
*   - 首先对于两个链表可能存在的两种情况，有环，无环。因此对于这两种状态需要分别研究；
*   1.第一种，一个链表有环，另一个无环。其实这种是不可能相交的，因为一旦相交也就意味这，这两个链表其实本身都是有环的。
*     因此对于这种情况，先进行链表的有环无环判定，如果其中一个有，另一个无。则之间返回不相交即可，无需后续的相交判断。
*   2.第二种，两个链表都是无环，既然无环，那就与之间的链表相交判定过程是一样的，采用无环链表的相交判断逻辑即可。
*   3.第三种，两个链表都是有环的。这种情况会衍生出三种不同的链表存在位置状态。
*     两个有环不相交、两个有环相交只有一个入环节点、两个有环相交两个入环节点
*     - 两个有环相交只有一个入环节点：
*       这种结构比较简单，任意一个链表先进行有环判定，当确定了其中一个链表的入环节点之后。在去判断另一个链表的并确定入环节点，
*       然后去对比两个如何节点指向的地址是否一致即可。
*     - 区分剩余两种:
*       先确定任意一个链表的入环节点，当确定之后，用该节点在另一个链表当中进行遍历，只要结束。如果在遍历的过程当中找到了第一个
*       链表入环节点的地址，那就说明两个链表一定是相交的，并且入环节点不相同，否则不相交。
*       接下来就是对于两个不相交的链表如何确定确定入环节点的问题。
*/
list<ListNode*> CyclecCheckerIntersectJudment::cycleCheckerIntersect(ListNode* node_1, ListNode* node_2)
{
	//判断两个链表是否有环
	CycleChecker cycleChecker;
	list<ListNode*> nodeList;
	LinkedListInterserctionChecker linkedListInterserctionChecker;
	ListNode* isCycle_1 = cycleChecker.judgeListIsCycleTwo(node_1);
	ListNode* isCycle_2 = cycleChecker.judgeListIsCycleTwo(node_2);

	if (nullptr == isCycle_1 && nullptr == isCycle_2)
	{
		//单链表相交
		ListNode* interserctionNode = linkedListInterserctionChecker.nodeInterserctionCheckerTwo(isCycle_1, isCycle_2);
		nodeList.push_back(interserctionNode);
		return nodeList;
	}

	//两个链表有环的
	if (nullptr != isCycle_1 && nullptr != isCycle_2)
	{
		if (isCycle_1 == isCycle_2)
		{
			//一个入环节点
			nodeList.push_back(isCycle_1);
			return nodeList;
		}

		ListNode* current = node_1;
		int flag = -1;
		while (1 != flag)
		{
			//两个入环节点
			if (current == isCycle_2)
			{
				nodeList.push_front(isCycle_1);
				nodeList.push_front(isCycle_2);
				return nodeList;
			}
			if (current == isCycle_2)
				flag++;
			current = current->next;
		}
	}
	return nodeList;
}
