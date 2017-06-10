#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 5;
ll dp[maxn][maxn][maxn][maxn];
const ll moder = 1e9 + 7;
int d[maxn];
int n;
int main()
{
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        memset(dp, 0, sizeof(dp));
        //dp[0][0][0][0] = 1;
        if (d[0] == 2)
        {
            dp[1][0][1][0] = 1;
        }
        else if (d[0] == 3)
        {
            dp[1][0][0][1] = 1;
        }
        for (int i = 2; i <= n; i++)
        {
            if (d[i - 1] == 2)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        for (int s = 0; s < n; s++)
                        {
                            //use 2 degree
                            dp[i][j][k][s] = (dp[i - 1][j][k + 1][s] + dp[i - 1][j + 2][k][s]) % moder;
                            if (j) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k][s + 1]) % moder;
                            if (k) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j + 1][k - 1][s + 1]) % moder;
                            //use 1 degree
                            if (j && k) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k - 1][s + 1]) % moder;
                            dp[i][j][k][s] = (dp[i - 1][j - 1][k][s + 1] + dp[i - 1][j + 1][k - 1][s + 1]) % moder;
                            //if (j && k) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k - 1][s + 1] ) % moder;
                            //if (j) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k][s + 1]) % moder;
                            if ()
                        }
                    }
                }
            }
            else if (d[i - 1] == 3)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        dp[i][j][k] = (dp[i - 1][j + 3][k] + dp[i - 1][j + 1][k + 1] + dp[i - 1][j - 1][k + 1] + dp[i - 1][j + 1][k - 1] + dp[i - 1][j + 1][k] +) % moder;
                    }
                }
            }
        }
        cout << dp[n][0][0] << endl;
    }
}
