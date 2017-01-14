#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 100;

ll C[maxn];
ll sum[maxn];
ll dp[maxn];
ld getg(int j, int k)
{
    ld deno = dp[j] + sum[j] * sum[j] - dp[k] - sum[k] * sum[k];
    ld nomi = 2 * (sum[j] - sum[k]);
    if (nomi == 0) return inf;
    return deno / nomi;
}
int n;
ll M;
int main()
{
    while(scanf("%d%lld", &n,&M) !=EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", C + i);
        }
        deque<int > Q;
        Q.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + C[i];
            while(Q.size() > 1 && (sum[i] && getg(Q[1], Q[0]) < sum[i]))
            {
                Q.pop_front();
            }
            dp[i] = dp[Q.front()] + (sum[i] - sum[Q.front()]) * (sum[i] - sum[Q.front()]) + M;
            while(Q.size() > 1 && (C[Q[Q.size() - 1]] == 0 || getg(i, Q[Q.size() - 1]) <= getg(i, Q[Q.size() - 2])))
            {
                Q.pop_back();
            }
            Q.push_back(i);
        }
        printf("%lld\n", dp[n]);
    }
}
