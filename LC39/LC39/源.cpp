#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> path;
		sort(candidates.begin(), candidates.end());
		dfs(result, candidates, path, 0, target);
		return result;
	}
	void dfs(vector<vector<int>> & result, vector<int> & candidates, vector<int> & path, int cur, int t)
	{
		if (t == 0)
		{
			result.push_back(path);
			return;
		}
		if (t < candidates[cur] || cur == candidates.size())
		{
			return;
		}
		
		path.push_back(candidates[cur]);
		dfs(result, candidates, path, cur, t - candidates[cur]);
		path.pop_back();
		dfs(result, candidates, path, cur + 1, t);
	}
};

int main()
{
	vector<int> nums = { 2,3,6,7 };
	Solution s;
	auto result = s.combinationSum(nums, 7);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}