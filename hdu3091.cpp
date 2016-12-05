#include<bits/stdc++.h>

using namespace std;
const int maxn = 18;
typedef long long ll;
const int maxs = 1 << maxn;
int N;
vector<int> G[maxn];
ll dp[maxs][maxn];
int main()
{
    int m;
    int u, v;
    while(scanf("%d%d",&N, &m)!=EOF)
    {
        int ms = 1 << N;
        memset(G, 0, sizeof(G));
        for(int i = 0;  i< m; i++)
        {
            scanf("%d%d",&u, &v);
            G[u - 1].push_back(v - 1);
            G[v - 1].push_back(u - 1);
        }
        memset(dp, 0, sizeof(dp));

        dp[1][0] = 1;
        dp[0][0] = 1;
        for(int s = 0; s < ms; s++)
        {
            for(int i = 0; i < N; i++)
            {
                if(s & (1 << i))
                {
                    int pre = s ^ (1 << i);

                    for(int j : G[i])
                    {
                        if( pre & (1 << j))
                        {
                            dp[s][i] += dp[pre][j];
                        }
                    }
                }
            }
        }
        ll ans = 0;
        ms--;
        for(int i : G[0])
        {
            ans += dp[ms][i];
        }
        printf("%I64d\n", ans);
    }
}
