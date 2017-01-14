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
ll cost[maxn];
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

int main()
{
    int n, m;
    int S, D;
    while(cin >> n >> m)
    {
        cin >> S >> D;
        S--;
        D--;
        for (int i = 0; i < n; i++)
        {
            cin >> cost[i];
        }
        int tot = 2 * n + 1;
        dinic DC(tot);
        int u, v;
        for (int i = 0; i < n; i++)
        {
            DC.addedge(i, i + n, cost[i]);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            DC.addedge(u + n - 1, v - 1, inf);
            DC.addedge (v + n - 1, u - 1, inf);
        }
        cout << DC.maxflow(S, D + n) << endl;

    }
}
