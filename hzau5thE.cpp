#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
int n;
int w[maxn];
int k;
int dp[maxn << 1];
int path[maxn];
int ans = -1;
void dfs(int x, int end, int len, int sum)
{
    if (x > n) return;
    while (sum + w[x] > k && end != x)
    {
        len--;
        end = path[end];
        sum -= w[end];
    }
    len++;
    ans = max(len, ans);
    sum += w[x];
    int tx = x << 1;
    path[x] = tx;
    dfs(tx, end, len, sum);
    path[x] |= 1;
    dfs(tx | 1, end, len, sum);
}
int main()
{
    int T;
    while(scanf("%d", &T) !=EOF)
    {
        while(T--)
        {
            scanf("%d%d", &n, &k);
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", w + i);
            }
            path[0] = 1;
            ans = -1;
            dfs(1, 0, 0, 0);
            if (ans == 0) ans = -1;
            printf("%d\n", ans);
        }
    }
}
