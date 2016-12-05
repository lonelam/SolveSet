#include<iostream>
#include<string>
#include<vector>
using namespace std;
//（其实并不严格算dfs
bool dfs(string &s, bool inserted, int low, int high)
{
	while (low < high)
	{
		if (s[low] != s[high])//不合法的情况
		{
			if (inserted)//判断是否已经插入
			{
				return false;
			}
			else
			{
				if (dfs(s, true, low + 1, high) || dfs(s, true, low, high - 1))//插入一个字符和跳过一个字符是等价的
				{
					return true;
				}
				else
					return false;
			}
		}
		low++;
		high--;
	}
	return true;

}
int main()
{
	int t;
	string line;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> line;
			if (dfs(line, false, 0, line.size() - 1))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}