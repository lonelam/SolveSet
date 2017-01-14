#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 10;
ll dp[maxn * 2][3];
ll a[maxn];
ll v[maxn];

int main()
{
    int T;
    int N, L;
    while(scanf("%d", &T) != EOF)
    {
        int kase = 1;
        while(T--)
        {
            memset(dp, 0, sizeof(dp));
            scanf("%d%d", &N, &L);
            ll mx = 0;
            for (int i = 1; i <= N; i++)
            {
                scanf("%lld%lld", a + i, v + i);
                a[i] *= 2;
                mx = max(mx, v[i]);
            }
            L *= 2;
            for (int i = 1; i <= N; i++)
            {
                int half = a[i] / 2;

                for (int j = L; j >= 1; j--)
                {
                    if (j >= half)
                    {
                        dp[j][2] = max(dp[j][2], dp[j - half][1] + v[i]);
                        dp[j][1] = max(dp[j][1], dp[j - half][0] + v[i]);
                    }
                    if (j >= a[i])
                    {
                        dp[j][2] = max({dp[j - 1][2], dp[j][2], dp[j - a[i]][2] + v[i]});
                        dp[j][1] = max({dp[j - 1][1], dp[j][1], dp[j - a[i]][1] + v[i]});
                        dp[j][0] = max({dp[j - 1][0], dp[j][0], dp[j - a[i]][0] + v[i]});
                    }
                }
            }
            printf("Case #%d: %lld\n",kase++, max({mx, dp[L][0], dp[L][1], dp[L][2]}));
        }
    }
}
