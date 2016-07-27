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
	int t;
	int node;
	while (cin >> t)
	{
		bool one_left = false;
		bool is_valid = true;
		if (t == 1)
		{
			one_left = true;
		}
		for(int i=0;i<t;i++)
		{
			cin >> node;
			if (node == 0)
			{
				if (one_left == true)
				{
					i++;
					for (; i < t; i++)
					{
						cin >> node;
					}
					is_valid = false;
					break;
				}
				one_left = true;
			}
		}
		if (is_valid && one_left)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}