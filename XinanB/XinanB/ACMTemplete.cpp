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
int vis[maxn][2];
int last[maxn][2];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		memset(vis, -1, sizeof(vis));
		memset(last, -1, sizeof(last));
		for (int i = 0; i < q; i++)
		{
			static int op, k, v;
			scanf("%d%d%d", &op, &k, &v);
			vis[k - 1][op - 1] = v;
			last[k - 1][op - 1] = i;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int c = 0;
				if (vis[i][0] != -1 && last[i][0] > last[j][1])
				{
					c = vis[i][0];
				}
				else if (vis[j][1] != -1 && last[j][1] > last[i][0])
				{
					c = vis[j][1];
				}
				printf("%d%c", c, (j == n - 1) ? '\n' : ' ');
			}
		}

	}
}