#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 105;

int dist[maxn][maxn];
int n,m, K;
int S[maxn], D[maxn];
int dp[maxn][2];
int main()
{
    freopen("MM.in", "r", stdin);
    freopen("MM.out", "w", stdout);
    S[0] = 1;
    D[0] = 1;
    dp[0][0] = 0;
    dp[0][1] = inf;
    int T;
    int kase = 1;
    //ios::sync_with_stdio(false);
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            //cin >> n >> m;
            scanf("%d%d%d",&n,&m,&K);
            int u,v,w;
            memset(dist, inf, sizeof(dist));
            for (int i = 0; i <= n; i++) dist[i][i] = 0;

            for (int i = 0;  i< m; i++)
            {
    //            cin >> u >> v >> w;
                scanf("%d%d%d",&u,&v,&w);
                dist[u][v] = min(w,dist[u][v]);
                dist[v][u] = dist[u][v];
            //    cout << "debug:L"<<u<< "  "<<v <<"  "<< w <<" "<<dist[u][v] << endl;
            }


            for (int k = 1; k <= n; k++)
            {
                for (int i = 1; i <= n; i++)

                {

                    for (int j = 1; j <= n; j++)
                    {
                        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                    }
                }
            }
            /*for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << (dist[i][j]== inf ? -1:dist[i][j])<<" ";
                }
                cout << endl;
            }*/
            for (int i = 1; i <= K; i++)
            {
                scanf("%d%d",S+i,D+i);
            //    cin >> S[i] >> D[i];
            }

            for (int i = 1; i <= K; i++)
            {
                dp[i][0] = min({inf,dp[i - 1][0] + dist[D[i - 1]][S[i]] + dist[S[i]][D[i]], dp[i - 1][1] + dist[D[i - 1]][D[i]]});
                dp[i][1] = min({inf,dp[i - 1][0] + dist[D[i - 1]][S[i]] +dist[S[i]][S[i + 1]] + dist[S[i + 1]][D[i]], dp[i - 1][1] + dist[D[i - 1]][S[i + 1]]+ dist[S[i + 1]][D[i]]});
            }
            printf("Case #%d: %d\n", kase++, dp[K][0]==inf?-1:dp[K][0]);
            //cout << dp[n][0] << endl;
        }
    }
}
/*

1
7 8 10
7 5 9
1 2 14
3 7 7
2 5 8
4 3 10
1 4 3
7 3 5
4 2 16
3 2
5 1
7 3
5 3
1 7
3 2
1 5
4 7
7 2
5 1


*/
