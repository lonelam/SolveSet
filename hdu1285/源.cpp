#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<functional>
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

int indegree[502];
int topo[502];
int n;
vector<int> G[502];
void bfs()
{
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	int cur = 0;
	while (!q.empty())
	{

		int b = topo[cur++] = q.top();
		q.pop();
		for (int f : G[b])
		{
			if (--indegree[f] == 0)
			{
				q.push(f);
			}
		}
		
	}
}
int main()
{
	int t,from,to,m;
	while (cin >> n>>m)
	{
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		while (m--)
		{
			cin >> from >> to;
			G[from].push_back(to);
			indegree[to]++;
		}
		bfs();
		cout << topo[0];
		for (int i = 1; i < n; i++)
		{
			cout << ' ' << topo[i];
		}
		cout << endl;
	}
}