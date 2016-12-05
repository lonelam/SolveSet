#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1000;

int dp[maxn][maxn];
int main()
{
	memset(dp, 0, sizeof(dp));
	string sa, sb;
	while (cin >> sa >> sb)
	{
		int na = sa.size(), nb = sb.size();

		for (int i = 1; i <= na; i++)
		{
			char ci = sa[i-1];
			for (int j = 1; j <= nb; j++)
			{
				char cj = sb[j-1];
				if (ci == cj)
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[na][nb] << endl;
	}
}