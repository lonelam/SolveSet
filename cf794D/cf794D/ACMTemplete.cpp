#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
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
const int maxn = 300000 + 100;
typedef long long ll;
typedef long double ld;
struct node
{
	vector<int> adj;
	int id;
	node() {}
	node(int x) : id(x) {}
	bool operator<(const node & rhs) const
	{
		return adj < rhs.adj;
	}
}G[maxn];
set<int> group[maxn];
int gno[maxn];
void add_edge(int u, int v)
{
	G[u].adj.push_back(v);
	G[v].adj.push_back(u);
}
int eu[maxn], ev[maxn];
int lab[maxn];
int n, m;
void init()
{
	for (int i = 0; i < n; i++)
	{
		G[i].id = i;
		G[i].adj.clear();
		group[i].clear();
	}
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &eu[i], &ev[i]);
			eu[i]--;
			ev[i]--;
			add_edge(eu[i], ev[i]);
		}
		for (int i = 0; i < n; i++)
		{
			G[i].adj.push_back(i);
			sort(G[i].adj.begin(), G[i].adj.end());
		}
		sort(G, G + n);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || G[i].adj == G[i - 1].adj)
			{
				gno[G[i].id] = cnt;
			}
			else gno[G[i].id] = ++cnt;
		}
		cnt++;
		for (int i = 0; i < m; i++)
		{
			if (gno[eu[i]] != gno[ev[i]])
			{
				group[gno[eu[i]]].insert(gno[ev[i]]);
				group[gno[ev[i]]].insert(gno[eu[i]]);
			}
		}
		bool ans = true;
		int head = -1;
		int headcnt = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (group[i].size() > 2 || group[i].size() == 0)
			{
				ans = false;
				break;
			}
			else if (group[i].size() == 1)
			{
				head = i;
				headcnt++;
			}
		}
		if (headcnt != 2)
		{
			ans = false;
		}
		if (cnt == 1)
		{
			printf("YES\n");
			for (int i = 0; i < n; i++)
			{
				printf("1 ", lab[gno[i]]);
			}
		}
		else if (ans)
		{
			int clock = 1;
			memset(lab, -1, sizeof(lab));
			lab[head] = clock++;
			int p = head;
			int cur = *group[head].begin();
			while (group[cur].size() == 2)
			{
				if (lab[cur] == -1)
				lab[cur] = clock++;
				for (int nex : group[cur])
				{
					if (nex != p)
					{
						if (lab[cur] == -1)
						lab[cur] = clock++;
						p = cur;
						cur = nex;
						break;
					}
				}
			}
			if (lab[cur] == -1)
			lab[cur] = clock++;
			printf("YES\n");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", lab[gno[i]]);
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}
/*

7 8
1 2
2 3
1 3
3 4
4 5
4 6
5 6
5 7


7 12
7 4
4 1
4 2
4 3
5 1
5 2
5 3
5 6
1 3
1 2
2 3
4 5
*/