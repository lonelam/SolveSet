#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
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
struct island
{
	int x, y;
};
double distance(island &a, island& b)
{
	double dx = abs(a.x - b.x);
	double dy = abs(a.y - b.y);
	return sqrt(dx*dx + dy*dy);
}
const int maxn = 101;
const double inf = 100000000;
double G[maxn][maxn];
double mincost[maxn];
bool used[maxn];
island nodes[maxn];
int n;
double prim()
{
	for (int i = 0; i < n; i++)
	{
		mincost[i] = inf;
		used[i] = false;
	}
	mincost[0] = 0;
	double res = 0;
	while (true)
	{
		int v = -1;
		for (int u = 0; u < n; u++)
		{
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
			{
				v = u;
			}
		}
		if (v == -1)
		{
			break;
		}
		used[v] = true;
		res += mincost[v];
		for (int u = 0; u < n; u++)
		{
			mincost[u] = min(mincost[u], G[v][u]);
		}
	}
	return res * 100;
}

int main()
{
	cout.setf(ios::fixed);
	cout.precision(1);
	int t;
	int tx, ty;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> tx >> ty;
				nodes[i] = { tx,ty };
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					double td = distance(nodes[i], nodes[j]);
					if (td >= 10 && td <= 1000)
					{
						G[i][j] = G[j][i] = td;
					}
					else
					{
						G[i][j] = G[j][i] = inf;
					}
				}
			}
			double ans = prim();
			if (ans < inf)
			{
				cout << ans << endl;
			}
			else
			{
				cout << "oh!\n";
			}
		}
	}
}