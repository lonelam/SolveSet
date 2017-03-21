#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 150000 + 100;

int fa[maxn];
vector<int> g[maxn];
ll p, e;
int vis[maxn];
void dfs(int x)
{
    p++;
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); i++)
    {
        e++;
        if (vis[g[x][i]]) continue;
        dfs(g[x][i]);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        p = 0;
        e = 0;
        if (vis[i]) continue;

        dfs(i);
        if (e != p * (p - 1))
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
