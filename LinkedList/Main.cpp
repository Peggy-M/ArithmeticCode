
#include "LinkedListCycleJudment.h"
#include "NoCycleIntersectionChecker.h"
#include "CycleCheckerIntersect.h"
#include <iostream>

int main() {
	//�Ƿ��л��жϷ���
	//LinkedListCycleJudment linkedListCycleJudment;
	//linkedListCycleJudment.isCycleJudment();
	
	//�ж������Ƿ����ཻ�ڵ�
	//NoCycleIntersectionChecker noCycleIntersectionChecker;
	//noCycleIntersectionChecker.intersectionChecker();

	//�ж������л��ڵ��Ƿ��ཻ
	CycleCheckerIntersect cycleCheckerIntersect;
	cycleCheckerIntersect.cycleCheckerIntersect();
	std::cout << "�������" << std::endl;
}
