#define _CRT_SECURE_NO_WARNINGS
//#define emplace push
//#define emplace_back push_back
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
typedef double ll;
const int maxn = 1005;
struct edge
{
    int u, v;
    ll cap, flow;
    edge() {}
    edge(int u, int v, ll cap):u(u), v(v), cap(cap), flow(0){}
};
bool vis[maxn];
struct dinic
{
    int n;
    vector<edge> es;
    vector<vector<int> > g;
    vector<int> d, pt;
    dinic(int n) : n(n), es(0), g(n), d(n), pt(n) {}
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
                if (e.flow - 1e-4 < e.cap && d[e.v] > d[e.u] + 1)
                {
                    d[e.v] = d[e.u] + 1;
                    q.push(e.v);
                }
            }
        }
        return d[T] != n + 1;
    }
    vector<int> search(int S, int T)
    {
        memset(vis, 0, sizeof(vis));
        queue<int> que;
        que.push(S);
        vis[S] = true;
        vector<int> ans;
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            for (int i = 0; i < g[cur].size(); i++)
            {
                edge & e = es[g[cur][i]];
                if (e.flow < e.cap && !vis[e.v])
                {
                    vis[e.v] = true;
                    que.push(e.v);
                    if (e.v != T)
                        ans.push_back(e.v);
                }
            }
        }
        return ans;
    }
    ll dfs(int u, int T, ll flow = -1)
    {
        if (u == T || flow == 0) return flow;
        for (int & i = pt[u]; i < g[u].size();++i)
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
        while(bfs(S,T))
        {
            fill(pt.begin(), pt.end(), 0);
            while(ll flow = dfs(S, T))
                total += flow;
        }
        return total;
    }
};
const double eps = 1e-8;
vector<int> G[maxn];
int dv[maxn];
int main()
{
    int n, m, u, v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            dv[u]++;
            dv[v]++;
        }
        if (m == 0 && n)
        {
            cout << "1\n1\n";
            continue;
        }
        double l = 0, r = n - 1, U = m;
        int S = 0, T = n + 1;
        vector<int> ans;
        while(true)
        {
            const double mid = (r + l) / 2;
            dinic mf(T + 1);
            for (int i= 1; i <= n; i++)
            {
                for (int k = 0; k < G[i].size(); k++)
                {
                    mf.addedge(i, G[i][k], 1);
                }
                mf.addedge(S, i, U);
                mf.addedge(i, T, U + 2 * mid - dv[i]);
            }
            double c = mf.maxflow(S, T);
            double hg = n * U - c;
            if (hg <= 0)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
            if (r - l < eps)
            {
                ans = mf.search(S, T);
                break;
            }
        }
        cout << ans.size()<<endl;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
    }
}
