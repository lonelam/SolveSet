#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 6000;
struct edge
{
    int from, to, cap, flow, cost;
    edge(int u, int v, int c, int p):from(u), to(v), cap(c), flow(0), cost(p) {}
};
struct MCMF
{
    int m,s,t;
    vector<edge> es;
    vector<int> G[maxn];
    int dis[maxn], a[maxn], p[maxn];
    bool vis[maxn];
    int fl;
    void init(int n)
    {
        for (int i = 0; i <= n; i++) G[i].clear();
        es.clear();
        m = 0;
    }
    void add(int u, int v, int c, int p)
    {
        G[u].push_back(m);
        G[v].push_back(m + 1);
        es.push_back(edge(u,v,c,p));
        es.push_back(edge(v,u,0,-p));
        m = es.size();
    }
    bool spfa(int & flow, int & cost)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        vis[s] = 1;
        dis[s] = 0;
        p[s] = 0;
        a[s] = inf;
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            vis[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                edge & e = es[G[u][i]];
                if (dis[e.to] > dis[u] + e.cost && e.cap > e.flow)
                {
                    dis[e.to] = dis[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!vis[e.to])
                    {
                        Q.push(e.to);
                        vis[e.to] = 1;
                    }
                }
            }
        }
        if (dis[t] == inf) return 0;
        flow += a[t];
        cost += dis[t] * a[t];
        int u = t;
        while(u != s)
        {
            es[p[u]].flow += a[t];
            es[p[u] ^ 1].flow -= a[t];
            u = es[p[u]].from;
        }
        return 1;
    }
    int mincost(int s, int t)
    {
        this-> s = s;
        this-> t = t;
        int flow = 0, cost = 0;
        while(spfa(flow, cost));
        fl = flow;
        return cost;
    }
} MF;
int n,m,k;
int transgrid[60][60][60];
int main()
{
    ios::sync_with_stdio(false);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if (n==0 && m ==0 && k==0)
        {
            break;
        }
        int S = (n + m) * k;
        int T = S + 1;
        int tot = T + 1;
        MF.init(tot);
        int fneed = 0;
        int prop;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> prop;
                scanf("%d",&prop);
                fneed += prop;
                MF.add(S, i * k + j, prop, 0);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> prop;
                MF.add((i + n) * k + j, T, prop, 0);
            }
        }
        int tranfee;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for(int h = 0; h < m; h++)
                {
                    cin >> tranfee;
                    MF.add(j * k + i, (h + n) * k + i, inf, tranfee);
                }
            }
        }
        int ans = MF.mincost(S, T);
        if (MF.fl < fneed) ans = -1;
        cout << ans << endl;
    }
}
