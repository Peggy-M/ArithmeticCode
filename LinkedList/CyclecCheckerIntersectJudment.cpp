#include "CyclecCheckerIntersectJudment.h"
#include "CycleChecker.h"
#include "LinkedListInterserctionChecker.h"


/**
* �ж����������Ƿ��ཻ���ҷ����ཻ��
* ����:
*   - ���ȶ�������������ܴ��ڵ�����������л����޻�����˶���������״̬��Ҫ�ֱ��о���
*   1.��һ�֣�һ�������л�����һ���޻�����ʵ�����ǲ������ཻ�ģ���Ϊһ���ཻҲ����ζ�⣬������������ʵ�������л��ġ�
*     ��˶�������������Ƚ���������л��޻��ж����������һ���У���һ���ޡ���֮�䷵�ز��ཻ���ɣ�����������ཻ�жϡ�
*   2.�ڶ��֣������������޻�����Ȼ�޻����Ǿ���֮��������ཻ�ж�������һ���ģ������޻�������ཻ�ж��߼����ɡ�
*   3.�����֣������������л��ġ�������������������ֲ�ͬ���������λ��״̬��
*     �����л����ཻ�������л��ֻཻ��һ���뻷�ڵ㡢�����л��ཻ�����뻷�ڵ�
*     - �����л��ֻཻ��һ���뻷�ڵ㣺
*       ���ֽṹ�Ƚϼ򵥣�����һ�������Ƚ����л��ж�����ȷ��������һ��������뻷�ڵ�֮����ȥ�ж���һ������Ĳ�ȷ���뻷�ڵ㣬
*       Ȼ��ȥ�Ա�������νڵ�ָ��ĵ�ַ�Ƿ�һ�¼��ɡ�
*     - ����ʣ������:
*       ��ȷ������һ��������뻷�ڵ㣬��ȷ��֮���øýڵ�����һ�������н��б�����ֻҪ����������ڱ����Ĺ��̵����ҵ��˵�һ��
*       �����뻷�ڵ�ĵ�ַ���Ǿ�˵����������һ�����ཻ�ģ������뻷�ڵ㲻��ͬ�������ཻ��
*       ���������Ƕ����������ཻ���������ȷ��ȷ���뻷�ڵ�����⡣
*/
list<ListNode*> CyclecCheckerIntersectJudment::cycleCheckerIntersect(ListNode* node_1, ListNode* node_2)
{
	//�ж����������Ƿ��л�
	CycleChecker cycleChecker;
	list<ListNode*> nodeList;
	LinkedListInterserctionChecker linkedListInterserctionChecker;
	ListNode* isCycle_1 = cycleChecker.judgeListIsCycleTwo(node_1);
	ListNode* isCycle_2 = cycleChecker.judgeListIsCycleTwo(node_2);

	if (nullptr == isCycle_1 && nullptr == isCycle_2)
	{
		//�������ཻ
		ListNode* interserctionNode = linkedListInterserctionChecker.nodeInterserctionCheckerTwo(isCycle_1, isCycle_2);
		nodeList.push_back(interserctionNode);
		return nodeList;
	}

	//���������л���
	if (nullptr != isCycle_1 && nullptr != isCycle_2)
	{
		if (isCycle_1 == isCycle_2)
		{
			//һ���뻷�ڵ�
			nodeList.push_back(isCycle_1);
			return nodeList;
		}

		ListNode* current = node_1;
		int flag = -1;
		while (1 != flag)
		{
			//�����뻷�ڵ�
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
