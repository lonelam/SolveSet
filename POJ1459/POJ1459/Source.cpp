#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1100;

int maze[maxn][maxn];
int gap[maxn], dis[maxn], pre[maxn], cur[maxn];
int sap(int start, int end, int nodenum)
{
	memset(cur, 0, sizeof(cur));
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	int u = pre[start] = start, maxflow = 0, aug = -1;
	gap[0] = nodenum;
	while (dis[start] < nodenum)
	{
	loop:
		for (int v = cur[u]; v < nodenum; v++)
			if (maze[u][v] && dis[u] == dis[v] + 1)
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
			int mindis = nodenum - 1;
			for (int v = 0; v < nodenum; v++)
			{
				if (maze[u][v] && mindis > dis[v])
				{
					cur[u] = v;
					mindis = dis[v];
				}
			}
			if (--gap[dis[u]] == 0)break;
			gap[dis[u] = mindis + 1]++;
			u = pre[u];
	}
	return maxflow;
}
int main()
{
	int n, m, np, nc;
	while (scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF)
	{
		int u, v, w;
		int S = n;
		int T = n + 1;
		int tot = T + 1;
		memset(maze, 0, sizeof(maze));
		for (int i = 0; i < m; i++)
		{
			scanf(" (%d,%d)%d", &u, &v, &w);
			maze[u][v] = w;
		}
		for (int i = 0; i < np; i++)
		{
			scanf(" (%d)%d", &u, &w);
			maze[S][u] = w;
		}
		for (int i = 0; i < nc; i++)
		{
			scanf(" (%d)%d", &u, &w);
			maze[u][T] = w;
		}
		printf("%d\n", sap(S, T, tot));
	}
}