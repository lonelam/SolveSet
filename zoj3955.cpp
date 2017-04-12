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
const int maxn = 1000 + 100;
typedef long long ll;
typedef long double ld;
const ll moder = 1e9 + 7;
int n;
ll raw[maxn][maxn];
ll row[maxn][maxn];
ll col[maxn][maxn];
ll bmask[maxn * 2];
int main()
{
	int n, m;
	bmask[0] = 1;
    //cout <<"debug"<< endl;
	for (int i = 1; i < 2005; i++)
	{
		bmask[i] = (bmask[i - 1] * 2LL) % moder;
	}
	int T;

	while (scanf("%d", &T) != EOF)
		while (T--)
		{
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					scanf("%lld", raw[i] + j);
					col[j][i] = row[i][j] = raw[i][j];
				}
			}
			for (int i = 0; i < n; i++)
			{
				sort(row[i], row[i] + m);
			}
			for (int j = 0; j < m; j++)
			{
				sort(col[j], col[j] + n);
			}
			ll ans = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					int rnkrow = m - (upper_bound(row[i], row[i] + m, raw[i][j]) - row[i]);
					int rnkcol = lower_bound(col[j], col[j] + n, raw[i][j]) - col[j];
					ans = (ans + bmask[rnkcol + rnkrow]) % moder;
				}
			}
			printf("%lld\n", ans);
		}
	return 0;
	//system("pause");
}
