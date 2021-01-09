/*
	Description��
	Integer Array��nums[]
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
		/*���ǹ���map��find(target�������)��
		���ǣ��������������map���Ⱥ�����ƥ�����ʱ��ֱ��find��ǰ���ֵ��λ�ã�
		e.g��target=13;[2,7,11,15]
		i=0��13-2=11��map��ʱΪ��[]��û��ƥ�䣬���Ը�map�������ݣ�[2,0]
		i=1��13-7=5��map�ڣ�û��ƥ�����5����[2,0],[7,1]
		i=2��13-11=2��map�ڣ���ƥ�����2�����������λ�ã�λ����iterator����ĵڶ���
		*/
		map<int, int> table;
		for (int i = 0; i < nums.size(); ++i) {
			int temp = target - nums[i];
			auto it = table.find(temp);
			if (it != table.end()) {
				return {it->second,i};//map���iterator��ʹ�÷���,->first����ý����һ����ֵ��->second����ڶ�����ֵ��
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