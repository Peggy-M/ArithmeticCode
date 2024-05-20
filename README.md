# 算法练习

## 链表部分

### 链表的环判断

> 【判断一个链表是否有环,并确定入环节点，空间复杂度 O(1)】
> - 分析：如果一个链表有环，那么该链表的尾指针一定是不为 NULL 并且入环节点的指针一定是指向链表的某一个节点的。
>   确定入环节点：
> 	   方法一：同过一个额外的 HASH 桶空间对链表遍历，如果桶中的元素在循环遍历的过程当中出现，
> 	      则表示该链表有环，同时该节点为入环节点，但是并不满足空间复杂度为 O(1) 的要求。
> 	   方法二：通过快慢指针，将两个指针设定为指定的步长，通过相差的步长进行遍历。如果两个指针最终相遇，则表示有环，如果其中
> 			  任意一个指针指向了空，则表示无环。

- 通过 hash 桶判断

~~~ c++
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
~~~

- 通过快慢指针判断

~~~ c++
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
~~~

### 无环链表的相交判断

> 
> * 要求：判断两个链表是否相交，如果相交则返回相交的节点，否则返回 NULL 。约束条件 -> 必须保证空间复杂度 (O)1.
>
>   分析:首先两个链表一旦相交也就意味这两个链表的最终节点元素所指向的地址一定是一样的。
>
>   - 方法一：同样的利用 HASH 桶对任意一个链表进行遍历，将所有的节点元素放入到该桶中，然后遍历另一个链表，一旦同种的节点元素与当前的遍历节点元素相同，则表示这两个链表一定相交，并且该节点元素为相交的节点。【不满足空间复杂度为(O)1】
>   - 方法二：分别遍历两个链表记录两个链表的长度，让长链表先走差值步，然后两个链表一起编写，如果两个链表是相交的，那么最终的节点元素一定会出现相同，如果遍历完整个链表，都没有找到相同的节点则表示该链表一定不相交。

- 通过 hash 桶进行判断

~~~ c++

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
~~~

- 通过链表的长度差值步长进行判断

~~~ c++
ListNode* LinkedListInterserctionChecker::nodeInterserctionCheckerTwo(ListNode* node_1, ListNode* node_2)
{
	ListNode* current_1 = node_1;
	ListNode* current_2 = node_2;

	int lengthDelta = 0;

	//获取链表1 与 链表2 的长度差值
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
	if (lengthDelta >= 0) //如果链表1 长度大于链表2 
	{
		while (lengthDelta != 0)
		{
			lengthDelta--;
			current_1 = current_1->next; //让链表 1 先走差值步
		}
	}
	else
	{
		while (lengthDelta != 0)
		{
			lengthDelta++;
			current_2 = current_2->next;//让链表 2 先走差值步
		}
	}

	//最终两个链表同时走完剩余相同的长度
	while (nullptr != current_1 && nullptr != current_2)
	{
		current_1 = current_1->next;
		current_2 = current_2->next;
		if (current_1 == current_2) //如果链表1 的节点与链表2 的节点相同则返回当前的节点
			return current_1;

	}

	return nullptr;
}
~~~

### 有环链表的相交判断

> 判断两个链表是否相交并且返回相交点
> 分析:
>   - 首先对于两个链表可能存在的两种情况，有环，无环。因此对于这两种状态需要分别研究；
>     1.第一种，一个链表有环，另一个无环。其实这种是不可能相交的，因为一旦相交也就意味这，这两个链表其实本身都是有环的。
>     因此对于这种情况，先进行链表的有环无环判定，如果其中一个有，另一个无。则之间返回不相交即可，无需后续的相交判断。
>     2.第二种，两个链表都是无环，既然无环，那就与之间的链表相交判定过程是一样的，采用无环链表的相交判断逻辑即可。
>     3.第三种，两个链表都是有环的。这种情况会衍生出三种不同的链表存在位置状态。
>     两个有环不相交、两个有环相交只有一个入环节点、两个有环相交两个入环节点
>     - 两个有环相交只有一个入环节点：
>       这种结构比较简单，任意一个链表先进行有环判定，当确定了其中一个链表的入环节点之后。在去判断另一个链表的并确定入环节点，
>       然后去对比两个如何节点指向的地址是否一致即可。
>     - 区分剩余两种:
>       先确定任意一个链表的入环节点，当确定之后，用该节点在另一个链表当中进行遍历，只要结束。如果在遍历的过程当中找到了第一个
>       链表入环节点的地址，那就说明两个链表一定是相交的，并且入环节点不相同，否则不相交。
>       接下来就是对于两个不相交的链表如何确定确定入环节点的问题。

~~~ c++
list<ListNode*> CyclecCheckerIntersectJudment::cycleCheckerIntersect(ListNode* node_1, ListNode* node_2)
{
	//判断两个链表是否有环
	CycleChecker cycleChecker;
	list<ListNode*> nodeList;
	LinkedListInterserctionChecker linkedListInterserctionChecker;
	ListNode* isCycle_1 = cycleChecker.judgeListIsCycleTwo(node_1);
	ListNode* isCycle_2 = cycleChecker.judgeListIsCycleTwo(node_2);

	if (nullptr != isCycle_1 && nullptr != isCycle_2)
	{
		//单链表相交
		ListNode* interserctionNode = linkedListInterserctionChecker.nodeInterserctionCheckerTwo(isCycle_1, isCycle_2);
		nodeList.push_back(interserctionNode);
		return nodeList;
	}

	//两个链表有环的
	if (nullptr == isCycle_1 && nullptr == isCycle_2)
	{
		ListNode* current = node_1;
		//一个入环节点
		nodeList.push_back(current);
		return nodeList;
		//两个入环节点
		nodeList.push_front(isCycle_1);
		nodeList.push_front(isCycle_2);
		return nodeList;
	}
	return nodeList;
}
~~~



