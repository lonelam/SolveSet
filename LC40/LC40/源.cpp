#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> path;
		dfs(candidates, target, 0, path, result);
		return result;
	}
private:
	static void dfs(vector<int> & candidates, int gap, int start, vector<int> & path, vector<vector<int>> &result)
	{
		if (gap == 0)
		{
			result.push_back(path);
			return;
		}
		int previous = -1;
		for (size_t i = start; i < candidates.size(); i++)
		{
			if (previous == candidates[i])
			{
				continue;
			}
			if (gap < candidates[i])
			{
				return;
			}
			previous = candidates[i];
			path.push_back(candidates[i]);
			dfs(candidates, gap - candidates[i], i + 1, path, result);
			path.pop_back();
		}
	}

};