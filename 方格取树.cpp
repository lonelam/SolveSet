#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = INT_MAX;
const int maxn = 100000;



struct edge
{
    int u,v;
    ll cap, flow;
    edge() {}
    edge(int u, int v, ll cap) : u(u), v(v), cap(cap), flow(0) {}
};

struct dinic
{
    int n;
    vector<edge> es;
    vector<vector<int> > g;
    vector<int> d, pt;
    ll cnt;
    dinic(int n) :n(n), es(0), g(n), d(n), pt(n) {}
    void addedge(int u, int v, ll cap)
    {
        if (u != v)
        {
            es.push_back(edge(u, v, cap));
            g[u].push_back(es.size() - 1);
            es.push_back(edge(v, u, 0));
            g[v].push_back(es.size() - 1);
        }
    }
    bool bfs(int S, int T)
    {
        queue<int> q;
        q.push(S);
        fill (d.begin(), d.end(), n + 1);
        d[S] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == T) break;
            for (int k = 0; k < g[u].size(); k++)
            {
                edge & e = es[g[u][k]];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
                {
                    d[e.v] = d[e.u] + 1;
                    q.push(e.v);
                }
            }
        }
        return d[T] != n + 1;
    }
    ll dfs(int u, int T, ll flow = -1)
    {
        if (u == T || flow == 0) return flow;
        for (int & i = pt[u]; i < g[u].size(); i++)
        {
            edge & e = es[g[u][i]];
            edge & oe = es[g[u][i] ^ 1];
            if (d[e.v] == d[e.u] + 1)
            {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (ll pushed = dfs(e.v, T, amt))
                {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    bool vis[maxn];
    void dfs2(int u, int T)
    {
        if (u == T || vis[u]) return;
        vis[u] = true;
        for (int i = 0; i < g[u].size(); i++)
        {
            edge & e = es[g[u][i]];

    //        edge & oe = es[g[u][i] ^ 1];
            if (e.flow == e.cap)
            {
                cnt++;
            }
            else
            {
                dfs2(e.v, T);
            }
        }
    }
    ll maxflow(int S, int T)
    {
        ll total = 0;
        while(bfs(S, T))
        {
            fill (pt.begin(), pt.end(), 0);
            while(ll flow = dfs(S, T))
                total += flow;
        }
        cnt = 0;
        memset(vis, 0,sizeof(vis));
//        dfs2(S, T);
        return total;
    }
};


int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        int tot = m * n + 2;
        int S = tot - 1;
        int T = tot - 2;
        dinic G(tot);

        ll cost;
        ll sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cost;
                sum += cost;
                if ((i + j) & 1)
                {
                    G.addedge(S,  i * n + j, cost);
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            if (dx * dy != 0 || dx == 0 && dy == 0)
                            {
                                continue;
                            }
                            int tx = i + dx, ty = j + dy;
                            if (tx >= 0 && tx < m && ty >= 0 && ty < n && !((tx + ty)&1))
                            {

                                    G.addedge(i * n + j, tx * n + ty, inf);
                                //    G.addedge( tx * n + ty,i * n + j, inf);
                            }
                        }
                    }
                }
                else
                {
                    G.addedge( i * n + j, T, cost);
                }
            }
        }
        ll mf = G.maxflow(S,T);
        cout << sum - mf << endl;
    //    cout << G.es.size() << endl;
    }
}
