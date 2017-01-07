#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 600;
int dp[maxn][maxn];
int a[maxn];
int main()
{
    int n;
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            dp[i + 1][i] = 1;
        }
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i + len <= n; i++)
            {
                dp[i][i + len] = inf;
                for (int k = i + 1; k < i + len; k++)
                {
                    dp[i][i + len] = min(dp[i][k] + dp[k][i + len],dp[i][i + len]);
                }
                if (a[i] == a[i + len - 1])
                {
                    dp[i][i + len] = min(dp[i][i + len], dp[i + 1][i + len - 1]);
                }
            }
        }
        cout << dp[0][n] << endl;
    }
}
