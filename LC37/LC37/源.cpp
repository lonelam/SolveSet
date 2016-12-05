#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> isblank(n, vector<bool>(n, false));
		vector<vector<bool>> row_valid(n, vector<bool>(n+1, true));//0 to 9
		vector<vector<bool>> col_valid(n, vector<bool>(n + 1, true));//0 to 9
		vector<vector<vector<bool>>> square_valid(3, vector<vector<bool>>(3, vector<bool>(n + 1, true)));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == '.')
				{
					isblank[i][j] = true;
				}
				else
				{
					int digit = board[i][j] - '0';
					row_valid[i][digit] = false;
					col_valid[j][digit] = false;
					square_valid[i / 3][j / 3][digit] = false;
				}
			}
		}
		dfs(board, isblank, row_valid, col_valid, square_valid);
		return;
	}
	static const int n = 9;
	bool dfs(vector<vector<char>> & board, vector<vector<bool>> &isblank, vector<vector<bool>>& row_valid, vector<vector<bool>>& col_valid, vector<vector<vector<bool>>> & square_valid)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (isblank[i][j])
				{

					for (int k = 1; k <= n; k++)
					{
						if (row_valid[i][k] && col_valid[j][k] && square_valid[i / 3][j / 3][k])
						{
							row_valid[i][k] = col_valid[j][k] = square_valid[i / 3][j / 3][k] = false;
							isblank[i][j] = false;
							board[i][j] = '0' + k;
							if (dfs(board, isblank, row_valid, col_valid, square_valid))
							{
								return true;
							}
							board[i][j] = '.';
							isblank[i][j] = true;
							row_valid[i][k] = col_valid[j][k] = square_valid[i / 3][j / 3][k] = true;
						}
					}
					return false;
				}
			}
		}
		return true;
	}
};

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}
	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
				{
					for (int k = 0; k < 9; k++)
					{
						board[i][j] = '1' + k;
						if (isvalid(board, i, j) && solve(board))
						{
							return true;
						}
						board[i][j] = '.';
					}
					return false;
				}
			}
		}
		return true;
	}
private:
	bool isvalid(const vector<vector<char>> & board, int x, int y)
	{
		int i, j;
		for (i = 0; i < 9; i++)
		{
			if (i != x&&board[i][y] == board[x][y])
			{
				return false;
			}
		}
		for (j = 0; j < 9; j++)
		{
			if (j != y && board[x][j] == board[x][y])
			{
				return false;
			}
		}
		for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
		{
			for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
			{
				if ((i != x || j != y) && board[i][j] == board[x][y])
				{
					return false;
				}
			}
		}
		return true;
	}
};