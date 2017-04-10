#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int dfs_clock, mem;
const int maxn = 50000 + 100;
vector<int> G[maxn];
int order[maxn];
int nex[maxn];
int n;
int vis[maxn];
int task[maxn * 4];
//int lazy[maxn * 4];
void init(int x = 1, int L = 0, int R = n)
{
	memset(task, -1, sizeof(task));
//	memset(lazy, -1, sizeof(lazy));
}
void push_down(int x)
{
	if (task[x] != -1)
	{
		task[x << 1] = task[x << 1 | 1] = task[x];
		task[x] = -1;
	}
}
void set(int ql, int qr, int tsk, int L = 0, int R = n, int x = 1)
{
	if (L > qr || R < ql) return;
	if (ql <= L && R <= qr)
	{
		task[x] = tsk;
		return;
	}
	push_down(x);
	const int mid = L + (R - L) / 2;
	if (ql < mid) set(ql, qr, tsk, L, mid, x << 1);
	if (mid < qr) set(ql, qr, tsk, mid, R, x << 1 | 1);
}
int query(int q, int L = 0, int R = n, int x = 1)
{
	if (task[x] != -1)
		return task[x];
	if (L + 1 == R) return task[x];
	push_down(x);
	const int mid = L + (R - L) / 2;
	if (q < mid) return query(q, L, mid, x << 1);
	else return query(q, mid, R, x << 1 | 1);
}
void dfs(int cur)
{
	order[cur] = dfs_clock++;
	for (int i = 0; i < G[cur].size(); i++)
	{
		dfs(G[cur][i]);
	}
	nex[cur] = dfs_clock;
}

int main()
{
	int T;
	int kase = 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) G[i].clear();
		memset(vis,0,sizeof(vis));
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[v - 1].push_back(u - 1);
			vis[u - 1] = true;
		}
		dfs_clock = 0;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				dfs(i);
				break;
			}
		}
		init();
		int m;
		scanf("%d", &m);
		printf("Case #%d:\n", kase++);
		char cmd[100];
		int x, y;
		for (int i = 0; i < m; i++)
		{
			scanf("%s", cmd);
			if (cmd[0] == 'T')
			{
				scanf("%d%d", &x, &y);
				set(order[x-1], nex[x-1], y);
			}
			else
			{
				scanf("%d", &x);
				printf("%d\n", query(order[x-1]));
			}
		}

	}
}