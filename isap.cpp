#include<bits/stdc++.h>

using namespace std;
const int maxn = 100;
struct edge
{
    int from,to,cap,flow;
};
struct isap
{
    int n, m, s, t;
    vector<edge> es;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    int p[maxn];
    int num[maxn];
    int augment()
    {
        int x = t, a = inf;
        while(x != s)
        {
            edge & e = es[p[x]];
            a = min(a, e.cap - e.flow);
            x = es[p[x]].from;
        }
        x = t;
        while(x != s)
        {
            es[p[x]].flow += a;
            es[p[x]^1].flow -= a;
            x = es[p[x]].from;
        }
        return a;
    }
    int maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        bfs();
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++)
        {
            num[d[i]] ++;
        }
        int x = s;
        memset(cur, 0, sizeof(cur));
        while(d[s] < n)
        {
            if(x == t)
            {
                flow += augment();
                x = s;
            }
            int ok = 0;
            for(int i = cur[x]; i < G[x].size(); i++)
            {
                edge & e = es[G[x][i]];
                if(e.cap > e.flow && d[x] == d[e.to] + 1)
                {
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i;
                    x = e.to;
                    break;
                }
            }
            if(!ok)
            {
                int m = n - 1;
                for(int i = 0; i < G[x].size(); i++)
                {
                    edge & e = es[G[x][i]];
                    if(e.cap > e.flow)
                    {
                        m = min(m, d[e.to]);
                    }
                }
                if(-- num[d[x]] == 0)
                {
                    break;
                }
                num[d[x] = m + 1] ++;
                cur[x] = 0;
                if(x != s)
                {
                    x = es[p[x]].from;
                }
            }
        }
        return flow;
    }
};
