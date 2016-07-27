#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n > 0) generate(n, "", 0, 0, result);
		return result;
	}
	void generate(int n, string s, int l, int r, vector<string> & result)
	{
		if (l == n)
		{
			result.push_back(s.append(')', n - r));
			return;
		}
		generate(n, s + '(', l + 1, r, result);
		if (l > r)
		{
			generate(n, s + ')', l, r + 1, result);
		}
	}
};



class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return vector<string>(1, "");
		if (n == 1) return vector<string>(1, "()");
		vector<string> result;
		for (int i = 0; i < n; i++)
		{
			for (auto inner : generateParenthesis(i))
			{
				for (auto outer : generateParenthesis(n - i - 1))
				{
					result.push_back("(" + inner + ")" + outer);
				}
			}
		}
		return result;
	}
};