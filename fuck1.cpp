#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll dp[200][2];
int main()
{
    dp[0][1] = 1;
    for (int i = 1; i < 100; i ++)
    {
        if (i & 1) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }
    }
    int n;
    while(cin >> n)
    {
        cout << dp[n][0 ] + dp[n][1] <<endl
    }
}
