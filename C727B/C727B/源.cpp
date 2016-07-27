#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 102;
int dp[maxn][maxn];
int main()
{
	int t, n,tcur;
	memset(dp, 0, sizeof(dp));
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= i; j++)
				{
					cin >> dp[i][j];
				}
			}
			for (int i = n - 1; i > 0; i--)
			{
				for (int j = 1; j <= i; j++)
				{
					dp[i][j] = dp[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
				}
			}
			cout << dp[1][1] << endl;
		}
	}
}