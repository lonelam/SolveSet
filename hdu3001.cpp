#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 11;
const int maxs = 1 << maxn;

ll dp[maxs][maxn];

const ll inf = 0x3f3f3f3f3f3f3f3f;
struct edge
{
    int to, w;
};

edge es[maxn * maxn * 2];

vector<int> G[maxn];

bool vis[maxn];
int main()
{
    int m, n;
    int u, v, w;
    while(scanf("%d%d",&n, &m)!=EOF)
    {
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            G[i].clear();
        }
        for(int i = 0; i < m; i++)
        {

            scanf("%d%d%d",&u,&v,&w);
            u--;
            v--;
            G[u].push_back(i << 1);
            es[ i << 1] = {v, w};
            G[v].push_back((i << 1) + 1);
            es[(i << 1) + 1] = {u, w};
           // printf("debug:%d %d %d\n", es[i << 1].to, es[i << 1].w, es[(i << 1) + 1].to);

        }
        int ms = 1 << n;
        //spfa
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            q.push(i);
            dp[1 << i][i] = 0;
            dp[0][i] = 0;
            vis[i] = true;
        }
        while(!q.empty())
        {
            int c = q.front();
            q.pop();

            //printf("debug:\n");
            for(int s = 0; s < ms; s++)
            {
                if(s >> c & 1)
                {
                   // printf("debugGsize:%d\n", G[c].size());
                    for(int x = 0; x < G[c].size(); x++)
                    {
                        int t = es[G[c][x]].to;
                        int wt = es[G[c][x]].w;

                        if(dp[s| (1 << t)][t] > dp[s][c] + wt)
                        {
                            dp[s | (1 << t) ][t] = dp[s][c] + wt;
                            //printf("debug : %d\n", dp[s | (1<<t)][t]);
                            if(!vis[t])
                            {
                                q.push(t);
                                vis[t] = true;
                            }
                        }
                    }
                }
            }
            vis[c] = false;
        }
        ll ans = inf;
        ms--;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, dp[ms][i]);
        }
        printf("%I64d\n", ans == inf ? (ll)-1: ans);
    }
}
