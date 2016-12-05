#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
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
	int t,x,n;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> x >> n;
			if (x == 2)
			{
				if (n & 1)
				{
					cout << 1 << endl;
				}
				else
				{
					cout << 2 << endl;
				}
			}
			else
			{
				if (n & 1)
				{
					cout << 2 << endl;
				}
				else if( n==0)
				{
					cout << x << endl;
				}
				else
				{
					cout << 1 << endl;
				}
			}
		}
	}
}