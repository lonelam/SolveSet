#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 11;
const int maxs = 1 << maxn;
typedef long long ll;
ll G[maxn][maxn];
ll dp[maxs][maxn];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n;
int ms;
bool vis[maxn];
void init()
{

    memset(vis, 0, sizeof(vis));
    memset(dp, inf, sizeof(dp));
    memset(G, inf, sizeof(G));
    ms = 1 << n;
}
ll spfa()
{
    queue<int> q;
    for(int i = 0; i < n; i++){
            q.push(i);
    vis[i] = true;
    dp[0][i] = 0;
    dp[1 << i][i] = 0;
    }
    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        vis[c] = false;
        for(int s = 0; s < ms; s++)
        {
            if(s >> c & 1)
            {
                for(int to = 0; to < n; to++)
                {
                    if(dp[s | (1 << to)][to] > dp[s][c] + G[c][to])
                    {
                        dp[s | (1 << to)][to] = dp[s][c] + G[c][to];
                        if(!vis[to])
                        {
                            vis[to] = true;
                            q.push(to);
                        //    printf("dbug: %d\n", dp[s | (1 << to)][to]);
                        }
                    }
                }
            }
        }
        //printf("debug\n");
    }
    ll ans = inf;
    for(int i = 0; i < n; i++)
    {
        ans = min(ans, dp[ms - 1][i]);
    }
    return ans == inf? -1 : ans;
}
int main()
{
    int m;
    int u, v;
    ll w;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        init();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%I64d",&u,&v,&w);
            u--;v--;
            G[v][u] = G[u][v] = min(G[u][v], w);

        }

        printf("%I64d\n", spfa());
    }
}


