#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxt = 275;
const int maxn = 55;
const int maxm = 55;
const int inf = 0x3f3f3f3f;
int ds1[maxm][maxn];
int ds2[maxm][maxn];
int dt[maxn];
int dp[maxt][maxn];
int main()
{
	int n, T, M1, M2;
	memset(ds1, inf, sizeof(ds1));
	memset(ds2, inf, sizeof(ds2));
	int kase = 1;
	while (cin >> n && n)
	{
		memset(dp, inf, sizeof(dp));
		dp[0][1] = 0;
		cin >> T;
		for (int i = 1; i < n; i++)
		{
			cin >> dt[i];
		}
		cin >> M1;
		for (int i = 1; i <= M1; i++)
		{
			cin >> ds1[i][1];
			for (int j = 1; j < n; j++)
			{
				ds1[i][j + 1] = ds1[i][j] + dt[j];
			}
		}
		cin >> M2;
		for (int i = 1; i <= M2; i++)
		{
			cin >> ds2[i][n];
			for (int j = n - 1; j > 0; j--)
			{
				ds2[i][j] = ds2[i][j + 1] + dt[j];
			}
		}
		for (int i = 1; i <= T; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
				for (int k = 1; k <= M1; k++)
				{
					if (ds1[k][j] == i)
					{
						if(i - dt[j - 1] >= 0)
						dp[i][j] = min(dp[i][j], dp[i - dt[j - 1]][j - 1]);
						break;
					}
				}
				for (int k = 1; k <= M2; k++)
				{
					if (ds2[k][j] == i)
					{
						if(i - dt[j] >= 0)
						dp[i][j] = min(dp[i][j], dp[i - dt[j]][j + 1]);
						break;
					}
				}
			}
		}
		cout << "Case Number " << kase++ << ": ";
		if (dp[T][n] == inf)
		{
			cout << "impossible";
		}
		else
		{
			cout << dp[T][n];
		}
		cout << endl;
	//	cout << dp[T][n] << endl;
	}
}
