#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;

vector<int> G[maxn];
bool vis[maxn];
ll ans, k, n;

int dp[maxn][5];
void dfs1(int x, int p)
{
    for (int i = 0; i < G[x].size(); i++)
    {
        if (G[x][i] != p)
        {
            dfs1(G[x][i], x);
            for (int j = 0; j < k; j++)
            {
                dp[x][j] += dp[G[x][i]][(j + k-1) % k];
            }
            dp[x][1]++;
        }
    }
}

void dfs2(int x, int p, int drip[5])
{
    //dp[x][0]++;
    for (int i = 0; i < k; i++)
    {
        ans += drip[i % k] * (dp[x][(k+1-i)%k]);
    }
    //dp[x][0]--;
    ans +=  dp[x][1%k];
    for (int i = 0; i < G[x].size(); i ++)
    {
        if (G[x][i] != p)
        {
            int tmp[5];
            dp[x][1%k]--;
            for (int j = 0; j < k; j++)
            {
                tmp[j] = drip[(j + k-1) % k] + dp[x][(j + k-1) % k] - dp[G[x][i]][(j+k-2)%k];
            }
            dp[x][1%k]++;
            tmp[1%k]++;
            dfs2(G[x][i], x, tmp);
        }
    }
}

int main()
{
    while(cin >> n >> k)
    {
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++)
        {
            int a,b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(dp,0,sizeof(dp));
        dfs1(1, -1);
        ans = 0;
        int dr[5] = {0,0,0,0,0};
        dfs2(1,-1,dr);
        cout << ans << endl;
    }
}
