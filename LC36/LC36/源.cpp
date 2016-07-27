#include<vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
		vector<vector<bool>> col(9, vector<bool>(9, false));
		vector<vector<vector<bool>>> square(3, vector<vector<bool>>(3, vector<bool>(9, false)));
		int cur;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				cur = board[i][j] - '1';
				if (!row[i][cur])
				{
					row[i][cur] = true;
				}
				else
				{
					return false;
				}
				if (!col[j][cur])
				{
					col[j][cur] = true;
				}
				else
				{
					return false;
				}
				if (!square[i / 3][j / 3][cur])
				{
					square[i / 3][j / 3][cur] = true;
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
	
};