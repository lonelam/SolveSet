#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
	int removeElement(vector<int>& nums, int val) {
		return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
	}
};


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int ind = nums.size();

		for (int i = 0; i < ind; i++)
		{
			if (nums[i] == val)
			{
				while (nums.back() == val)
				{
					nums.pop_back();
					ind--;
				}
				nums[i] = nums.back();
				nums.pop_back();
				ind--;
			}
		}
		return ind ;
	}
};

