#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 10;
int dp[maxn][maxn];
int K[maxn][maxn];
int mftime[maxn];
int sum[maxn];
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", mftime + i);
            dp[i][i] = 0;
            K[i][i] = i;
            sum[i] = sum[i - 1] + mftime[i];
        }
        for (int i = 1; i <= n; i++)
        {
            mftime[i+n] = mftime[i];
            dp[i+n][i+n] = 0;
            K[i+n][i+n] = i+n;
            sum[i+n] = sum[i+n-1]+mftime[i + n];
        }
        n *= 2;
        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i + len - 1<= n; i++)
            {
                const int j = i + len - 1;
                dp[i][j] = inf;
                for (int k = K[i][j - 1]; k <= K[i + 1][j]; k++)
                {
                    if (dp[i][j] > dp[i][k] + dp[k+ 1][j] + sum[j] - sum[i - 1])
                    {
                        K[i][j] = k;
                        dp[i][j] = dp[i][k] + dp[k+ 1][j] + sum[j] - sum[i - 1];
                    }
            //        cout <<"dp"<<i <<" "<<j<<" = "<< dp[i][j] <<"  K = "<< K[i][j]<< endl;
                }
            }
        }
        int ans = inf;
        n/=2;
        for (int i = 1; i +n - 1 <= 2 * n; i++)
        {
            ans = min(ans, dp[i][i + n - 1]);
        }
        printf("%d\n", ans);
    }
}
