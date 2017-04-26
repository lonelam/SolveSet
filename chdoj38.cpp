#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
bool G[maxn][maxn];
int fa[maxn], rnk[maxn];
int fnd(int x)
{
    if(fa[x] != x)
    {
        return fa[x] = fnd(fa[x]);
    }
    return x;
}
void join(int a, int b)
{
    if (fnd(a) == fnd(b)) return;
    if (rnk[a] == rnk[b])
    {
        fa[b] = a;
        rnk[a]++;
    }
    else if (rnk[a] < rnk[b])
    {
        fa[a] = b;
    }
    else
    {
        fa[b] = a;
    }
}
bool vis[maxn];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        rnk[i] = 1;
    }
    memset(vis, 0, sizeof(vis));
}
int main()
{
    int T, m, n, u, v;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%d%d", &n,&m);
            init(n);
            memset(G, 0, sizeof(G));
            for (int i = 0; i < m; i++)
            {
                scanf("%d%d", &u, &v);
                G[u][v] = G[v][u] = true;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (!G[i][j])
                    {
                        join(i, j);
                    }
                }
            }
            bool ok = true;
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (fnd(i) != fnd(j))
                    {
                        if (!G[i][j])
                            ok = false;
                    }
                    else if (G[i][j])
                    {
                        ok = false;
                    }
                }
            }
            if (!ok)
            {
                printf("0\n");
            }
            else
            {
                int k = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (!vis[fnd(i)])
                    {
                        vis[fnd(i)] = true;
                        k++;
                    }
                }
                if (k == 1) k = 0;
                printf("%d\n", k);
            }
        }
    }
}
