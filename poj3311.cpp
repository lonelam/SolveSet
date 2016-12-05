#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 11;
const int maxs = 1 << maxn;

int G[maxn][maxn];
int dp[maxs][maxn];
const int inf = 0x3f3f3f3f;
int n;
int ms;
bool vis[maxn];
void init()
{
    n++;
    memset(vis, 0, sizeof(vis));
    memset(dp, inf, sizeof(dp));
    ms = 1 << n;
}
int spfa()
{
    queue<int> q;
    q.push(0);
    vis[0] = true;
    dp[0][0] = 0;
    dp[1][0] = 0;
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
    return dp[ms - 1][0];
}
int main()
{
    while(scanf("%d", &n)!=EOF && n)
    {
        init();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", G[i] + j);
            }
        }
        printf("%d\n", spfa());
    }
}
