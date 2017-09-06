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
vector<int> seq[maxn];
bool vis[maxn];
int tot;
int a[maxn], n;
int b[maxn];
inline int pos(int x)
{
	return lower_bound(b, b + n, a[x]) - b;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		tot = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			b[i] = a[i];
		}
		sort(b, b + n);
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				int orig = i;
				int p = pos(i);
				vis[i] = true;
				seq[tot].clear();
				seq[tot].push_back(i);
				while (orig != p)
				{
					vis[p] = true;
					seq[tot].push_back(p);
					p = pos(p);
					
				}
				tot++;
			}
		}
		printf("%d\n", tot);
		for (int i = 0; i < tot; i++)
		{
			printf("%d", seq[i].size());
			sort(seq[i].begin(), seq[i].end());
			for (int j : seq[i])
			{
				printf(" %d", j + 1);
			}
			printf("\n");
		}
		
	}
}