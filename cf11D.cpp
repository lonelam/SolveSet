#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 19;
const int maxp = 1 << maxn;
int dp[maxp];
bool g[maxn][maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    int u,v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u][v] = g[v][u] = true;
    }
    for (int i = 0; i < n; i++)
    {
        dp[1 << i] = 1;
    }
    int mp = 1 << n;

    for (int p = 0; p < mp; p++)
    {
        for (int j = 0; )
    }
}
