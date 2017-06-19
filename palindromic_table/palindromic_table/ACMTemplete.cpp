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
vector<int> grid[maxn];
vector<int> presum[maxn][10];
int n, m;
int a[maxn];
int vis[maxn];
vector<int> prerec[maxn];
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int ans = 1;
		vector<int> aindex = {0, 0, 0, 0};
		bool swaped = false;
		if (n <= m)
		{
			for (int i = 0; i < n; i++)
			{
				grid[i].clear();
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
				    scanf("%d", a + i * n + j);
					grid[i].push_back(a[i * n + j]);
				}
			}
		}
		else
		{
			swaped = true;
			swap(n, m);
			for (int i = 0; i < n; i++)
			{
				grid[i].clear();
			}
			for (int j = 0; j < m; j++)
			{
				for (int i = 0; i < n; i++)
				{
					scanf("%d", a + i * n + j);
					grid[i].push_back(a[i * n + j]);
				}
			}
		}
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				presum[j][k].clear();
			  presum[j][k].push_back(0);
			}
			for (int i = 0; i < n; i++)
			{
				for (int k = 0; k < 10; k++)
				{
				  if (k == grid[i][j]) presum[j][k].push_back(*presum[j][k].rbegin() ^ 1);
					else presum[j][k].push_back(*presum[j][k].rbegin());
				}
			}
		}
		prerec[0] = vector<int>(m + 1, 0);
		for (int i = 0; i < n; i++)
		{
			prerec[i + 1].clear();
			prerec[i + 1].push_back(0);
			for (int j = 0; j < m; j++)
			{
				prerec[i + 1].push_back(*prerec[i + 1].rbegin() + prerec[i][j + 1] - prerec[i][j]);
				if (grid[i][j])
				{
					++*prerec[i + 1].rbegin();
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				//interval [i, j]
				memset(vis, -1, sizeof(vis));
				vis[0] = 0;
				int cur = 0;
				for (int o = 0; o < m; o++)
				{
					for (int k = 0; k < 10; k++)
					{
						if (presum[o][k][j + 1] ^ presum[o][k][i]) cur ^= (1 << k);
					}
					if (vis[cur] != -1)
					{
						int tmp = prerec[j + 1][o + 1] - prerec[i][o + 1] - prerec[j + 1][vis[cur]] + prerec[i][vis[cur]];
						if (tmp>1 && ans < (j - i + 1) * (o - vis[cur] + 1))
						{
							ans = (j - i + 1) * (o - vis[cur] + 1);
							aindex = {i, vis[cur], j, o};
						}
					}
					else
					{
						vis[cur] = o + 1;
					}


					for (int k = 0; k < 10; k++)
					{
						int tar = cur ^ (1 << k);
						if (vis[tar] != -1)
						{
						  int tmp = prerec[j + 1][o + 1] - prerec[i][o + 1] - prerec[j + 1][vis[tar]] + prerec[i][vis[tar]];
							if (tmp>1 && ans < (j - i + 1) * (o - vis[tar] + 1))
							{
								ans = (j - i + 1) * (o - vis[tar] + 1);
							  aindex = {i, vis[tar] , j, o};
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
		if (swaped) swap(aindex[0], aindex[1]), swap(aindex[2], aindex[3]);
		printf("%d %d %d %d\n", aindex[0], aindex[1], aindex[2], aindex[3]);
	}
}
