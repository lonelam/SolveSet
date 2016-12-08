#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 12;
const int maxs = 1 << maxn;
const ll moder = 100000000;
ll dp[maxs][2];
int G[maxn][maxn];
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> G[i][j];
			}

		}
		memset(dp, 0, sizeof(dp));
		int flip = 0;
		int ms = 1 << n;
		dp[0][flip] = 1;
		for (int i = 0; i < m; i++)
		{

			flip ^= 1;
			for (int s = 0; s < ms; s++)
			{
				dp[s][flip] = 0;
				for (int pres = 0; pres < ms; pres++)
				{
					bool valid = true;
					for (int k = 0; k < n; k++)
					{
						if ((s & (1 << k)) && (pres & (1 << k) || !G[i][k] || ( s & ( 1 << (k+ 1))) || ( k >0 && (s & 1 << ( k - 1))) ))
						{
							valid = false;
						}
					}
					if (valid)
					{
						dp[s][flip] = (dp[s][flip] + dp[pres][flip ^ 1]) % moder;
					}
				}
			}
		}
		ll ans = 0;
		for (int s = 0; s < ms; s++)
		{
			ans = (ans + dp[s][flip]) % moder;
		}
		cout << ans << endl;
	}
}