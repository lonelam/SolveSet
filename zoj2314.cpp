#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
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
    ll maxflow(int S, int T)
    {
        ll total = 0;
        while(bfs(S, T))
        {
            fill (pt.begin(), pt.end(), 0);
            while(ll flow = dfs(S, T))
                total += flow;
        }
        return total;
    }
};

ll fl[maxn];
int main()
{
    int T;
    ios::sync_with_stdio(false);
    while(cin >> T)
    {
        while(T--)
        {
            int m, n;
            cin >> n >> m;
            int u, v;
            int lb, ub;
            int S = 0;
            int T = n + 1;
            int tot = n + 2;
            dinic G(tot);
            for (int i = 0; i < m; i++)
            {
                cin >> u >> v >> lb >> ub;
                G.addedge(u, v, ub - lb);
                G.addedge(S, v, lb);
                G.addedge(u, T, lb);
            }
            ll mf = G.maxflow(S, T);
            bool ok = true;
            for (int i = 0; i < m; i++)
            {
                edge & e = G.es[i * 6 + 2];
                edge & oe = G.es[i * 6 + 4];
                if (e.flow != e.cap || oe.flow != oe.cap)
                {
                    ok = false;
                    break;
                }
                fl[i] = G.es[i * 6].flow  + e.flow;
            }
            if (!ok)
            {
                cout <<"NO\n";
            }
            else
            {
                cout <<"YES\n";
                for (int i = 0; i < m; i++)
                {
                    cout << fl[i] << endl;
                }
            }

        }
    }
}
