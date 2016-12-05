#include<bits/stdc++.h>

using namespace std;

const int maxn = 8;
const int maxm = 31;


struct edge
{
    int u, v, w;

};
edge es[maxm * maxm];
int t[maxn];
const int maxstate = 1 << maxn;
int dp[maxstate][maxm];
vector<int> G[maxm];
const int inf = 0x3f3f3f3f;
bool vis[maxm];
struct path
{
    int to, weight, to_state;
    bool operator < (path & b)
    {
        return weight > b.weight;
    }
};
int solve(int a, int b, int n)
{
    priority_queue<path> q;
    q.push({a, 0, 0});
    while(!q.empty())
    {
        path cur = q.top();
        q.pop();
        int pos = cur.to;
        int cost = cur.weight;
        int ticket = cur.to_state;
        for(int i = 0; i < n; i++)
        {
            if(!(ticket & (1 << i)))
            {
                for(int j = 0; j < G[pos].size(); j ++)
                {
                    edge & route = es[G[pos][j]];

                }
            }
        }
    }
}
int main()
{
    int n,m,p,a,b;
    int x, y, dis;

    while(scanf("%d%d%d%d%d", &n, &m, &p, &a, &b)!=EOF)
    {
        memset(G, 0, sizeof(G));
        memset(dp, inf, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", t + i);
        }
        for(int i = 0; i < p; i++)
        {
            scanf("%d%d%d", &x, &y, &dis);
            es[i << 1] = {x, y, dis};
            es[(i <<1 ) + 1] = {y, x, dis};
            G[x].push_back(i << 1);
            G[y].push_back((i << 1) + 1);
        }
        int ans = solve(a, b, n);

    }
}

