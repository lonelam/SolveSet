#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 +19;
vector<int> G[maxn];
int T, n, m;
int a[maxn];
int b[maxn];
int d[maxn];
void dfs1(int u, int fa)
{
    for (int v: G[u])
    {
        if (v != fa)
        {
            dfs1(v, u);
            a[u] += a[v];
        }
    }
}
int ans;
void dfs2(int u, int fa)
{
    for (int v: G[u])
    {
        if (v != fa)
        {
            dfs2(v, u);
            if (!a[v]) continue;
            ans = max(ans, d[u] + d[v] + 1);
            d[u] = max(d[u], d[v] + 1);
        }
    }
    if (b[u]) ans = max(ans, d[u]);
}
int main()
{
    scanf("%d", &T);
    {
        while(T--)
        {
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; i++) G[i].clear(), a[i] = 0, d[i] = 0, b[i] = 0;
            for (int i = 0; i < m; i++)
            {
                static int tmp;
                scanf("%d", &tmp);
                a[tmp]++;
                b[tmp]++;
            }
            for (int i = 1; i < n; i++)
            {
                static int u, v;
                scanf("%d%d", &u, &v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
            ans = 0;
            dfs1(1, -1);
            dfs2(1, -1);
            printf("%d.00\n", ans / 2);
        }
    }
}
