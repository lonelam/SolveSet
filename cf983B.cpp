
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
int n, m, t;
int a[maxn];
typedef long long ll;
int dp[maxn][maxn];
int main()
{
    while(~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = a[i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                dp[i][j] = max({dp[i][j], dp[i-1][j] , dp[i-1][j+1]});
            }
        }
        int q;
        scanf("%d", &q);
        while(q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", dp[r-l][l-1]);
        }

    }
}
