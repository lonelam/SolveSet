#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
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

	int t;
	while (scanf("%d",&t)!=EOF)
	{
		if (t == 0)
		{
			return 0;
		}
		while (true)
		{
			stack<int>  station;
			bool valid = true;
			int cur = 1;
			int out;
			scanf("%d", &out);
			if (out == 0)
			{
				valid = false;
				printf("\n");
				break;
			}
			else
			{
				while (station.empty() || station.top() != out)
				{
					station.push(cur++);
				}
				station.pop();
			}
			for (int i = 1; i < t && valid; i++)
			{
				scanf("%d", &out);
				while (station.empty() || station.top() != out)
				{
					if (out < cur)
					{
						valid = false;
						i++;
						for (; i < t; i++)
						{
							scanf("%d", &out);
						}
						break;
					}
					else
					{
						station.push(cur++);
					}
				}
				station.pop();
			}
			if (valid)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
}