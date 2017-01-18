#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
//const ll moder = 1e9 + 7;
ll dp[maxn][maxn];
ll sum[maxn];
ll sqsum[maxn];
int K[maxn][maxn];
int main()
{
    int n, m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld",sum + i);
            sqsum[i] = sqsum[i - 1] + sum[i] * sum[i];
            sum[i] += sum[i - 1];
        }
        for (int k = 1; k <= m; k++)
        for (int i = 1; i<= n; i++)
        {
            for (int j = K[i + 1][k - 1]; j < K[i])
        }
    }
}
