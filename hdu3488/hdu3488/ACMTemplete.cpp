#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
const int maxm = 400 + 5;
struct edge
{
	int from, to, c, f, cost;
	edge(int a, int b, int m, int n, int p) : from(a), to(b), c(m), f(n), cost(p) {}
};
int aabs(int a)
{
	return a >= 0 ? a : -a;
}
struct MCMF
{
	int m, s, t;
	vector<edge> es;
	vector<int> G[maxm];
	int dis[maxm], a[maxm], p[maxm];
	bool vis[maxm];
	void init(int n)
	{
		for (int i = 0; i <= n; i++)
		{
			G[i].clear();
		}
		es.clear();
	}
	void add(int a, int b, int c, int v)
	{
		es.emplace_back(edge({ a, b, c, 0, v }));
		es.emplace_back(edge({ b, a, 0, 0, -v }));
		m = es.size();
		G[a].push_back(m - 2);
		G[b].push_back(m - 1);
	}
	bool spfa(int & flow, int & cost)
	{
		memset(dis, inf, sizeof(dis));
		memset(vis, 0, sizeof(vis));
	}
};
int main()
{


}