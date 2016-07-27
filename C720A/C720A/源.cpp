#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<functional>
#include<utility>
#include<cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 304;
typedef pair<int, int> P;
int dis[maxn];
int G[maxn][maxn];
int n;
int p[maxn];
int sp[maxn];

void dijkstra(int zz)
{
	memset(dis, inf, sizeof(dis));
	priority_queue<P, vector<P>, greater<P> > q;
	q.push({ 0, zz });
	while (!q.empty())
	{
		P cur = q.top();
		q.pop();
		int pos = cur.second;
		int dd = cur.first;
		if (dis[pos] > dd)
		{
			dis[pos] = dd;
			for (int i = 1; i <= n; i++)
			{
				if (G[i][pos] < inf)
				{
					q.push({ dd + G[i][pos] , i });
				}
			}
		}
	}
}
int main()
{
	int m,a,b,c,k;
	while (scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		int theone = -1;
		double fastest = INT_MAX;
		int fsd;
		memset(G, inf, sizeof(G));
		for (int i = 0; i < k; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			G[a][b] = min(G[a][b], c);
		}
		scanf("%d", &p[0]);
		dijkstra(p[0]);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", p + i);
		}
		for (int i = 1; i <= m; i++)
		{

			scanf("%d", sp + i);
			if (dis[p[i]]!=inf  && (dis[p[i]] * 1.0 / sp[i]) < fastest )
			{
				theone = i;
				fastest = (dis[p[i]] * 1.0 / sp[i]);
				fsd = dis[p[i]];
			}
			else if (dis[p[i]] * 1.0 / sp[i] == fastest)
			{
				if (dis[p[i]] >= fsd)
				{
					theone = i;
					fastest = (dis[p[i]] * 1.0 / sp[i]);
					fsd = dis[p[i]];
				}
				
			}
		}
		if (theone == -1)
		{
			printf("No one\n");
		}
		else
		{
			printf("%d\n", theone);
		}
	}
}