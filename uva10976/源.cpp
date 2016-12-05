#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
/*
-----------Answered by Lonelam---------
*
*          ┌─┐       ┌─┐
*       ┌──┘ ┴───────┘ ┴──┐
*       │                 │
*       │       ───       │
*       │  ─┬┘       └┬─  │
*       │                 │
*       │       ─┴─       │
*       │                 │
*       └───┐         ┌───┘
*           │         │
*           │         │
*           │         │
*           │         └──────────────┐
*           │                        │
*           │                        ├─┐
*           │                        ┌─┘
*           │                        │
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!
*/
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int k, x, y;
	vector<pair<int, int>> ans;
	while (cin >> k)
	{
		ans.clear();
		for (x = k + 1; x <= 2 * k; x++)
		{
			y = k*x / (x - k);
			if (x*y == k*(x + y))
			{
				ans.push_back({ y,x });

			}
		}
		cout << ans.size() << endl;
		for (auto i : ans)
		{
			cout << "1/" << k << " = " << "1/" << i.first << " + " << "1/" << i.second << endl;
		}
	}
}
