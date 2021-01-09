#include<iostream>
#include<cstdlib>

#ifndef __COMPLEX__
#define __COMPLEX__

#include<math.h>

#endif // !__COMPLEX__

using namespace std;

typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	}
};