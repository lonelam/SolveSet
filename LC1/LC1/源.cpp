#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> ns; 
		int sz= nums.size();
		for (int i = 0; i < sz;i++)
		{
			ns[nums[i]] = i;
		}
		for (int i = 0; i < sz; i++)
		{
			auto k = ns.count(target - nums[i]);
			if (k != 0 && ns[target - nums[i]]!= i)
			{
				return { min(i, ns[target - nums[i]]), max(i, ns[target - nums[i]]) };
			}
		}
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 3, 2, 4 };
	auto result = solution.twoSum(nums, 6);
	for (int i : result)
	{
		cout << i << endl;
	}
}