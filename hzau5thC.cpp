#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

int ans[maxn];
int dp[maxn][7];
vector<int> G[maxn];
void dfs(int x, int p)
{
    dp[x][0] = 1;
    for (int i = 0; i < G[x].size(); i++)
    {
        if (G[x][i] != p)
        {
            dfs(G[x][i], x);
            for (int k = 1; k <= 6; k++)
            {
                dp[x][k] += dp[G[x][i]][k - 1];
            }
        }
    }
}
void dfs2(int x, int p, int acc[7])
{
    for (int k = 1; k <= 6; k++)
    {
        ans[x] += acc[k] + dp[x][k];
    }
    for (int i = 0; i < G[x].size(); i++)
    {
        if (G[x][i] != p)
        {
            int tt[7] = {1};
            for (int k = 1; k <= 6; k++)
            {
                tt[k] = acc[k - 1] + (dp[x][k - 1] - (k > 1 ? dp[G[x][i]][k - 2]: 1));
            }
            dfs2(G[x][i], x, tt);
        }
    }
}
int main()
{
    int T;
    int kase = 1;
    int n;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            printf("Case #%d:\n", kase++);
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                G[i].clear();
            }
            memset(ans, 0, sizeof(ans));
            memset(dp, 0, sizeof(dp));
            int u,v;
            for (int i = 1; i < n; i++)
            {
                scanf("%d%d", &u, &v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
            int down[7] = {1};
            dfs(1, -1);
            dfs2(1, -1, down);
            for (int i = 1; i <= n; i++)
            {
                printf("%d\n", ans[i]);
            }
        }
    }
}
