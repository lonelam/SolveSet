#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<queue>
#include<functional>
#include<algorithm>
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
struct stone
{
	int p, d;
};
struct stonecmp
{
	bool operator()(stone & a, stone & b)
	{
		if (a.p > b.p)
		{
			return true;
		}
		if (a.p == b.p)
		{
			return a.d > b.d;
		}
		return false;
	}
};
int main()
{
	int t, n,p,d,throwp,throwtmp;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			bool flip = true;
			throwp = 0;
			scanf("%d", &n);
			priority_queue<stone, vector<stone>, stonecmp> q;
			for (int i = 0; i < n; i++)
			{
				scanf("%d%d", &p, &d);
				q.push({ p,d });
			}
			while (!q.empty())
			{
				stone cur = q.top();
				q.pop();
				if (flip)
				{
					cur.p = cur.d + cur.p;
					throwp = max(throwp, cur.p);
					q.push(cur);
				}
				flip = !flip;
			}
			printf("%d\n", throwp);
		}
	}
}