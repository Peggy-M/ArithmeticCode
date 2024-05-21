
#include "LinkedListCycleJudment.h"
#include "NoCycleIntersectionChecker.h"
#include "CycleCheckerIntersect.h"
#include <iostream>

int main() {
	//是否有环判断方法
	//LinkedListCycleJudment linkedListCycleJudment;
	//linkedListCycleJudment.isCycleJudment();
	
	//判断链表是否有相交节点
	//NoCycleIntersectionChecker noCycleIntersectionChecker;
	//noCycleIntersectionChecker.intersectionChecker();

	//判断两个有环节点是否相交
	CycleCheckerIntersect cycleCheckerIntersect;
	cycleCheckerIntersect.cycleCheckerIntersect();
	std::cout << "输出数据" << std::endl;
}
