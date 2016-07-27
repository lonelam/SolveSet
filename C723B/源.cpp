#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<utility>
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
const int inf = 0x3f3f3f3f;
const int maxn = 101;
const int maxm = 1002;
int dis[maxn];
int mreal[maxn];
typedef pair<int, int> P;
int Gv[maxn][maxn];//a、b分别代表这条边的估计长度与实际长度。
int Gr[maxn][maxn];
struct pos2
{
	int to, real;
};
typedef pair<int, pos2> PD;
int s, e;
int n,m;
struct grt
{
	bool operator()(PD & a, PD &b)
	{
		return a.first > b.first;
	}
};
int dijkstra()
{
	memset(dis, inf, sizeof(dis));
	memset(mreal, 0, sizeof(mreal));
	priority_queue<PD, vector<PD>, grt> q;
	q.push({ 0,{s,0} });
	while (!q.empty())
	{
		PD cur = q.top();
		q.pop();
	    int pos = cur.second.to;
		int rd = cur.second.real;
		int dd = cur.first;
		if (dis[pos] >= dd)
		{
			dis[pos] = dd;
			mreal[pos] = max(mreal[pos], rd);
			for (int i = 1; i <= n; i++)
			{
				if (Gv[pos][i] < inf)
				{
					q.push({ Gv[pos][i] + dd,{i,Gr[pos][i] + rd} });
				}
			}
		}
	}
	return mreal[e];
}
int main()
{
	int t;
	int u, v, a, b;
	P stand = { inf,-1 };
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> m >> s >> e;
			memset(Gv, inf, sizeof(Gv));
			memset(Gr, 0, sizeof(Gr));
			for (int i = 0; i < m; i++)
			{
				cin >> u >> v >> a >> b;
				Gv[u][v] = min(a, Gv[u][v]);
				Gv[v][u] = Gv[u][v];
				Gr[u][v] = max(b, Gr[u][v]);
				Gr[v][u] = Gr[u][v];
			}
			dijkstra();
			cout <<  dis[e]<<' '<<mreal[e]<< endl;
		}
	}
}