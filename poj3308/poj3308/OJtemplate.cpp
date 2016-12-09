#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn = 150;
const int maxm = 800;
const double inf = 1e8;
double ccost[maxn];
double rcost[maxn];
double maze[maxn][maxn];
void maze_init()
{
	memset(maze, 0, sizeof(maze));
}
void add_edge(int u, int v, double c)
{
	maze[u][v] = c;
}
int gap[maxn], dis[maxn], pre[maxn], cur[maxn];
double sap(int start, int end, int nodenum)
{
	memset(cur, 0, sizeof(cur));
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	int u = pre[start] = start;
	double aug = -1;
	double maxflow = 0;
	gap[0] = nodenum;
	while (dis[start] < nodenum)
	{
	loop:
		for (int v = cur[u]; v < nodenum; v++)
		{
			if (maze[u][v] != 0&& dis[u] == dis[v] + 1)
			{
				if (aug == -1 || aug > maze[u][v]) aug = maze[u][v];
				pre[v] = u;
				u = cur[u] = v;
				if (v == end)
				{
					maxflow += aug;
					for (u = pre[u]; v != start; v = u, u = pre[u])
					{
						maze[u][v] -= aug;
						maze[v][u] += aug;
					}
					aug = -1;
				}
				goto loop;
			}
		}
		int mindis = nodenum - 1;
		for (int v = 0; v < nodenum; v++)
			if (maze[u][v] != 0 && mindis > dis[v])
			{
				cur[u] = v;
				mindis = dis[v];
			}
			if ((--gap[dis[u]]) == 0) break;
			gap[dis[u] = mindis + 1]++;
			u = pre[u];
	}
	return maxflow;
}
int main()
{
	int t;
	int m, n, l;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d%d%d", &m, &n, &l);
			maze_init();
			int S = m + n;
			int r0 = 0;
			int c0 = m;
			int T = S + 1;
			int tot = T + 1;
			int u, v;
			for (int i = 0; i < m; i++)
			{
				scanf("%llf", rcost + i);
				add_edge(S, r0 + i, log(rcost[i]));
			}
			for (int i = 0; i < n; i++)
			{
				scanf("%llf", ccost + i);
				add_edge(c0 + i, T, log(ccost[i]));
			}
			for (int i = 0; i < l; i++)
			{
				scanf("%d%d", &u, &v);
				add_edge(r0 + u-1, c0 + v-1, inf);
			}
			printf("%.4f\n", exp(sap(S, T, tot)));
		}
	}
	return 0;
}