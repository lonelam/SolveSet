#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				swap(matrix[i][j], matrix[n - 1 - j][n - i - 1]);
			}
		}
		const int mid = n / 2;
		for (int i = 0; i < mid; i++)
		{
			for (int j = 0; j < n; j++)
			{
				swap(matrix[i][j], matrix[n - 1 - i][j]);
			}
		}
	}
};


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

	}
};