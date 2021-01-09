/*
	Description：
	Integer Array：nums[]
	Integer Target: target
	plz Find out the sum of two Interger Array members which equals to target;
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
	int sum;
	vector<int> twoSum(vector<int>& nums, int target) {
		/*不是构建map后，find(target减后对象)；
		而是，将减的数，组成map，等后面有匹配的数时，直接find到前面的值的位置；
		e.g：target=13;[2,7,11,15]
		i=0；13-2=11；map此时为空[]，没有匹配，所以给map增加内容：[2,0]
		i=1；13-7=5；map内，没有匹配的数5，∴[2,0],[7,1]
		i=2；13-11=2；map内，有匹配的数2，∴输出它的位置，位置在iterator对象的第二空
		*/
		map<int, int> table;
		for (int i = 0; i < nums.size(); ++i) {
			int temp = target - nums[i];
			auto it = table.find(temp);
			if (it != table.end()) {
				return {it->second,i};//map类的iterator的使用方法,->first代表该结果第一个数值，->second代表第二个数值；
			}
			table[nums[i]] = i;
		}
		return {};

		//map<int, int> table;
		//for (int i = 0; i < nums.size(); i++) {
		//	table[i] = nums[i];
		//}
		//for (int j = 0; j < nums.size(); j++) {
		//	int temp = target-nums[j];
		//	auto res = table.find(temp);
		//	if (res != table.end()) {
		//		cout << res->first << endl;
		//		return { res->first,res->second };
		//	}
		//}
		//return {};
		
	}
};
int main() {
	Solution A;
	A.sum = 0;
	int arr[] = { 2, 7, 11, 15 };
	vector<int> nums(arr,arr+4);
	int target = 13;
	A.twoSum(nums, target);
	system("pause");
	return 0;


}