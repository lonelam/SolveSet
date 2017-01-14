#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;

ll sum[maxn];
ll sqsum[maxn];
ll SI[maxn];
ll dp[maxn][maxn];
ld getg(int j, int k, int t)
{
    ld numi = 2 * dp[j][t - 1] - 2 * dp[k][t - 1] + sqsum[j] - sqsum[k] + sum[j] * sum[j] - sum[k] * sum[k];
    ld deno = 2 * (sum[j] - sum[k]);
    return numi / deno;
}
int main()
{
    int n, m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if (n == 0 && m == 0)
        {
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", SI + i);
            sum[i] = sum[i - 1] + SI[i];
            sqsum[i] = sqsum[i - 1] + SI[i] * SI[i];
            dp[i][0] = (sum[i] * sum[i] - sqsum[i]) / 2;
        //    cout << dp[i][0]<<" ";
        }
        for (int t = 1; t <= m; t++)
        {
            deque<int> Q;

            for (int i = 1; i <= n; i++)
            {
                while(Q.size() > 1 && getg(Q[1], Q[0], t) < sum[i])
                {
                    Q.pop_front();
                }
                if (Q.empty())
                {
                    dp[i][t] = 0;
                }
                else
                {
                    const int j = Q.front();
                    dp[i][t] = dp[j][t - 1] + ((sum[i] - sum[j])*(sum[i] - sum[j]) - (sqsum[i] - sqsum[j])) / 2;
                }

                while (Q.size() > 1 && getg(Q[Q.size() - 1], Q[Q.size() - 2], t) > getg(i, Q[Q.size() - 1], t))
                {
                    Q.pop_back();
                }
                Q.push_back(i);
            }
        }
        printf("%lld\n", dp[n][m]);
    }
}
