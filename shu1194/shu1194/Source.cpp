#include<iostream>
using namespace std;
bool vis[100];
int pp[100];
int n;
int dp[100] = { 0, 1,1,2,4 };
int dfs(int cur, int p)
{
	if (cur == n)
	{
		return 1;
	}
	int sum = 0;
	for (int dd = -2; dd <= 2; dd++)
	{
		if (p + dd > 0 && p + dd <= n&& !vis[p + dd])
		{
			vis[ p + dd] = true;
			sum += dfs(cur + 1, p + dd);
			vis[p + dd] = false;
		}
	}
	return sum;
}

int main()
{
	
	for (int i = 3; i <= 55; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 3] + 1;
		
	}
	while (cin >> n)
		cout << dp[n] << endl;
}