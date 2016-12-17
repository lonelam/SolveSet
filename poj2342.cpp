#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 6010;

int dp[maxn][2];
vector<int> g[maxn];
int w[maxn];

int get_dp(int x, int s, int fa)
{
    if (dp[x][s] != -1)
    {
        return dp[x][s];
    }
    dp[x][s] = 0;
    if (s)
    {
        dp[x][s] = w[x];
        for (int i = 0; i < g[x].size(); i++)
        {
            if (g[x][i] != fa)
            {
                dp[x][s] += get_dp(g[x][i], 0, x);
            }
        }
    }
    else
    {
        for (int i = 0; i < g[x].size(); i++)
        {
            if (g[x][i] != fa)
            {
                dp[x][s] += max(get_dp(g[x][i], 0, x), get_dp(g[x][i], 1, x));
            }
        }
    }
    return dp[x][s];
}

int main()
{
    int n;
    while(cin >> n)
    {
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            cin >> w[i];
        }
        int u, v;
        while (cin >> u >> v && u||v) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout <<  max(get_dp(1, 0, -1), get_dp(1, 1, -1))<<endl;

    }
}
