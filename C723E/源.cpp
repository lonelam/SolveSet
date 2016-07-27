#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<utility>
#include<functional>
#include<algorithm>
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
const int maxn = 102;
typedef pair<int, int> P;
vector<P> G[maxn];//{weight,to}
int least[maxn];
bool ind[maxn];
bool used[maxn];
void dijkstra(int s)
{
	priority_queue<P,vector<P>,less<P>> q;
	q.push({ least[s],s });
	while (!q.empty())
	{
		P cur = q.top();
		q.pop();
		int pos = cur.second;
		int wt = cur.first;
		if (least[pos] < wt||!used[pos])
		{
			used[pos] = true;
			least[pos] = max(least[pos],wt);
			for (P path : G[pos])
			{
				int to = path.second;
				int w = path.first;
				q.push({ w + least[pos],to });
			}
		}
	}
}

int main()
{
	int t, n, p, q, a, b, x;
	while (scanf("%d",&t)!=EOF)
	{
		while (t--)
		{
			
			scanf("%d%d%d", &n, &p, &q);
			for (int i = 1; i <= n; i++)
			{
				G[i].clear();
			}
			memset(ind, 0, sizeof(ind));
			memset(least, 0, sizeof(least));
			memset(used, 0, sizeof(used));
			for (int i = 0; i < p; i++)
			{
				scanf("%d%d", &a, &x);
				least[a] = max(x,least[a]);
			}
			for (int i = 0; i < q; i++)
			{
				scanf("%d%d%d", &a, &b, &x);
				G[b].push_back({ x,a });
				ind[a] = true;
			}
			for (int i = 1; i <= n; i++)
			{
				if (!ind[i])
				{
					dijkstra(i);
				}
			}
			printf("%d\n", least[1]);
		}
	}
}