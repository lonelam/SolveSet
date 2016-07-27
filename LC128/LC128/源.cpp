#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution1 {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, bool> used;
		for (auto i : nums)
		{
			used[i] = false;
		}
		int longest = 0;
		for (auto i : nums)
		{
			if (used[i] == true)
			{
				continue;
			}
			used[i] = true;
			int length = 1;
			for (int j = i + 1; used.find(j)!=used.end(); j++)
			{
				used[j] = true;
				length++;
			}
			for (int j = i - 1; used.find(j) != used.end(); j--)
			{
				used[j] = true;
				length++;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> map;
		int size = nums.size();
		int l = 1;
		for (int i = 0; i < size; i++)
		{
			if (map.find(nums[i]) != map.end())
			{
				continue;
			}
			map[nums[i]] = 1;
			if (map.find(nums[i] - 1) != map.end())
			{
				l = max(l, mergeCluster(map,nums[i] - 1, nums[i]));
			}
			if (map.find(nums[i] + 1) != map.end())
			{
				l = max(l, mergeCluster(map, nums[i], nums[i] + 1));
			}
		}
		return l;
	}
private:
	int mergeCluster(unordered_map<int, int>& map, int left, int right)
	{
		int upper = right + map[right] - 1;
		int lower = left - map[left] + 1;
		int length = upper - lower + 1;
		map[upper] = length;
		map[lower] = length;
		return length;
	}
};

