// add_two_numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


 struct ListNode {
     int val;
     ListNode *next;

     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//要对节点进行操作：
		/*
		1、先安排一个目录性节点，至少要有头节点、尾节点：初始化为NULL；
		2、在将每个节点插入到链表时：是否是第一个节点
									 a).是。则头节点、尾节点都指向它；
									 b).不是。让头节点不变，先让【尾节点】（即将进行操作的节点）的next指针，指向下一个new的节点；
											 再让new节点成为新的【尾节点】。
		*/
		ListNode *tempFront = NULL;
		ListNode *tempRear = NULL;
		int carry = 0;//进位

		while ( l1 || l2 ) {					//l1、l2其中一个仍存在；
			//计算节点相加的内容
			int tempSum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			if (!tempFront) //没有指向首节点的情况下；
				tempFront = tempRear = new ListNode(tempSum % 10);
			else {
				tempRear->next = new ListNode(tempSum % 10);
				tempRear = tempRear->next;
			}
			carry = tempSum / 10;		//即进位的数，一般为0 or. 1；
			//这两个if是为了让while决定 是否 能继续下去
			if (l1)
				l1 = l1->next;			//如果该节点是存在的，向下个节点移动
			if (l2)
				l2 = l2->next;			//如果该节点是存在的，向下个节点移动
			//在最后，l1、l2均为NULL时；tempSum==1,
		}
		if (carry)
			tempRear->next = new ListNode(carry);
		return tempFront;
	}
};

int main()
{
	Solution addnum;
    std::cout << "Hello World!\n";
}