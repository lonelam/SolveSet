#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
const int maxm = 12;
int G[maxm][maxn];
int dp[maxm][maxn];
int path[maxm][maxn];
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
		for (int i = 0; i < m; i++)
		{
			dp[i][0] = G[i][0];
		}
		for (int j = 1; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				int pre[3] = { (i - 1 + m) % m, (i + 1) % m, i };
				sort(pre, pre + 3);
				dp[i][j] = inf;
				for (int k = 0; k < 3; k++)
				{
					if (dp[i][j] > dp[pre[k]][j - 1])
					{
						dp[i][j] = dp[pre[k]][j - 1];
						path[i][j] = pre[k];
					}
				}
				dp[i][j] += G[i][j];
			}
		}
		stack<int> ss;
		int pos = m - 1;
		for (int i = n - 1; i > 0; i--)
		{
			ss.push(pos = path[pos][i]);
		}
		while (!ss.empty())
		{
			cout << ss.top() + 1 << ' ';
			ss.pop();
		}
		cout << m << endl;
		cout << dp[m - 1][n - 1] << endl;
	}
}