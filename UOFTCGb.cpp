#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	node *next;
	int where;
} *first[100001], a[200001];
int test, n, m, l, c[100001], dist[100001], f[100001];

inline void makelist(int x, int y) {
	a[++l].where = y; a[l].next = first[x]; first[x] = &a[l];
}

int main() {
	//freopen("1.txt", "r", stdin);
	scanf("%d", &test);
	for (;test--;)
	{
		memset(first, 0, sizeof(first));
		l = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			makelist(x, y);
			makelist(y, x);
		}
		memset(dist, 0, sizeof(dist));
		memset(f, 0, sizeof(f));
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (!dist[i])
			{
				c[1] = i; dist[i] = 1;
				int k = 1, l = 1;
				for (; l <= k; l++)
				{
					int m = c[l];
					for (node *x = first[m]; x; x = x->next)
						if (!dist[x->where])
							dist[x->where] = dist[m] + 1, c[++k] = x->where;
				}
				for (int j = k; j; --j)
				{
					int m = c[j], tot = 0;
					for (node *x = first[m]; x; x = x->next)
						if (dist[x->where] == dist[m] + 1)
							tot += f[x->where];
					ans += max(0, tot - 1);
					f[m] = (tot >= 2) ? 0: 1;
				}
				if (f[i])
					++ans;
			}
		printf("%d\n", ans + n - 1);
	}
}
