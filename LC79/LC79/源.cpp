#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		m = board.size();
		n = board[0].size();
		vector<vector<bool>> used(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0])
				{
					if (dfs(board, word, 1, i, j, used))
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	int m, n;
	bool dfs(vector<vector<char>> &bd, string & wd, int cur, int x, int y, vector<vector<bool>>& used)
	{
		used[x][y] = true;
		if (cur == wd.size())
		{
			return true;
		}
		if (x > 0 && bd[x - 1][y] == wd[cur]&&!used[x-1][y])
		{
			if (dfs(bd, wd, cur + 1, x - 1, y, used))
			{
				return true;
			}
		}
		if (y > 0 && bd[x][y - 1] == wd[cur] && !used[x][y - 1])
		{
			if (dfs(bd, wd, cur + 1, x, y - 1, used))
			{
				return true;
			}
		}
		if (x + 1 < m&&bd[x + 1][y] == wd[cur] && !used[x + 1][y])
		{
			if (dfs(bd, wd, cur + 1, x + 1, y, used))
			{
				return true;
			}
		}
		if (y + 1 < n&& bd[x][y + 1] == wd[cur] && !used[x][y + 1])
		{
			if (dfs(bd, wd, cur + 1, x, y + 1, used))
			{
				return true;
			}
		}
		used[x][y] = false;
		return false;
	}
};