#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;



class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto low = lower_bound(nums.begin(), nums.end(), target);
		auto high = upper_bound(nums.begin(), nums.end(), target);
		vector<int> result;
		if (low!=nums.end() && *low == target)
		{
			result.push_back(distance(nums.begin(), low));
			result.push_back(distance(nums.begin(), high) - 1);
		}
		else
		{
			return{ -1,-1 };
		}
		return result;
	}
};
