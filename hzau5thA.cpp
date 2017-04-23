#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

int a[maxn];
int dp[maxn];
int main()
{
    int T, n, k;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%d%d", &n, &k);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", a + i);
            }
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= n; i++)
            {
                dp[i] = max(dp[i - 1], (i - k > 0 ? dp[i - k - 1] : 0) + a[i - 1]);
            }
            printf("%d\n", dp[n]);
        }
    }
}
