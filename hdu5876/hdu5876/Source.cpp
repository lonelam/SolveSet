#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 200000 + 10;
const int maxm = 20000 + 10;
const int inf = 0x3f3f3f3f;
set<int> G[maxn];
int dis[maxn];
int main()
{
	int t;
	int n, m;
	int u, v;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d%d", &n, &m);
			set<int> nvis;
			for (int i = 1; i <= n; i++)
			{
				G[i].clear();
				nvis.insert(i);
			}
			memset(dis, -1, sizeof(dis));
			for (int i = 0; i < m; i++)
			{
				scanf("%d%d", &u, &v);
				G[u].insert(v);
				G[v].insert(u);
			}

			int s;
			scanf("%d", &s);
			queue<int> qq;
			nvis.erase(s);
			qq.push(s);
			dis[s] = 0;
			while (!qq.empty())
			{
				int cur = qq.front();
				qq.pop();

				for (set<int>::iterator it = nvis.begin(); it!=nvis.end();)
				{
					int x = *it;
					if (G[cur].find(x) == G[cur].end())
					{
						dis[x] = dis[cur] + 1;
						it = nvis.erase(it);
						qq.push(x);
						
					}
					else
					{
						it++;
					}
				}
			}
			for (int i = 1; i < n; i++)
			{
				if (i != s)
				{
					printf("%d ", dis[i]);
				}
			}
			if (n != s)
			{
				printf("%d\n", dis[n]);
			}
		}
	}
}