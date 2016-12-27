#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
int app[1050];

typedef long long ll;
int main()
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			int n, k;
			scanf("%d%d", &n, &k);
			memset(app, 0, sizeof(app));
			int pi, ai;
			for (int i = 0; i < n; i++)
			{
				scanf("%d%d", &pi, &ai);
				app[pi] += ai;
			}
			int p = 1000;
			int blanck = 0;
			int ans = 0;
			while (p)
			{
				while (p && !app[p])
					p--;
				if (p == 0)
					break;
				ans += 2 * p;
				while (p && blanck < k)
				{
					if (app[p] <= k - blanck)
					{
						blanck += app[p];
						app[p] = 0;
						p--;
					}
					else
					{
						app[p] -= k - blanck;
						blanck = k;
					}
				}
				blanck = 0;
			}
			printf("%d\n", ans);
		}
	}
}