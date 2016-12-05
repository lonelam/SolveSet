#include<bits/stdc++.h>

using namespace std;
struct edge
{
    int from, to, cap, flow, cost;

};
struct mcmf
{
    int n, m, s, t;
    vector<edge> es;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];
    void init(int n)
    {
        this-> n = n;
        for(int i = 0; i < n; i++)
        {
            G[i].clear();
        }
        m = 0;
        es.clear();
    }
    void addedge(int from, int to, int cap, int cost)
    {
        es.push_back({from, to, cap, 0, cost});
        es.push_back({to, from, 0, 0, -cost});
        m = es.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    //spfa
    bool bf(int s, int t, int & flow, int & cost)
    {
        for(int i = 0; i < n; i++)
        {
            d[i] = inf;

        }
        memset(inq, 0, sizeof(inq));
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = inf;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for(int i = 0; i < G[u].size(); i++)
            {
                edge & e = es[G[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if(!inq[e.to])
                    {

                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if(d[t] == inf)
        {
            return false;
        }
        int x = t;
        while(x != s)
        {

        }
    }
};
