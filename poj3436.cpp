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
const int maxn = 1000;
const int maxp = 100;
struct edge
{
    int u, v;
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
        queue<int> Q;
        Q.push(S);
        fill (d.begin(), d.end(), n + 1);
        d[S] = 0;
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            if (u == T)break;
            for (int k = 0; k < g[u].size(); k++)
            {
                edge & e = es[g[u][k]];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
                {
                    d[e.v] = d[e.u] + 1;
                    Q.push(e.v);
                }
            }
        }
        return d[T] != n + 1;
    }
    ll dfs(int u, int T, ll flow = -1)
    {
        if ( u == T || flow == 0) return flow;
        for (int & i = pt[u]; i < g[u].size(); i++)
        {
            edge & e = es[g[u][i]];
            edge & oe = es[g[u][i]^1];
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
            fill(pt.begin(), pt.end(), 0);
            while(ll flow = dfs(S, T))
                total += flow;
        }
        return total;
    }
};


int from[maxn][maxp];
int to[maxn][maxp];

int perf[maxn];
int main()
{
    int P, N;
    int si;
    ios::sync_with_stdio(false);
    while(cin >> P >> N)
    {
        int S = N * 2 + 1;
        int T = S + 1;
        int tot = T + 1;
        dinic G(tot);
//        map<int, vector<int> > ustate, vstate;
        for (int i = 0; i < N; i++)
        {
            cin >> perf[i];
        //    int u = 0, v = 0;
            for (int j = 0; j < P; j++)
            {
                cin >> from[i][j];
            }
            for (int j = 0; j < P; j++)
            {
                cin >> to[i][j];
            }

        }
        for (int i = 0; i < N; i++)
        {
            G.addedge(i, i + N, perf[i]);
        }
        for (int i = 0; i < N; i++)
        {
            bool starter = true, finisher = true;
            for (int k = 0; k < P; k++)
            {
                if (from[i][k] == 1)
                {
                    starter = false;
                }
                if (to[i][k] == 0)
                {
                    finisher = false;
                }
            }
            if (starter)
            {
            //    cout << "starter L" << i  + 1<< endl;
                G.addedge(S, i, inf);
            }
            if (finisher)
            {
                G.addedge(i + N, T, inf);
            }
            for (int j = 0; j < N; j++)
            {
                bool ok = true;
                if (i == j) continue;
                for (int k = 0; k < P; k++)
                {
                    if (to[i][k] == 1 && from[j][k] == 0 )
                    {
                        ok = false;
                        break;
                    }
                    else if (to[i][k] == 0 && from[j][k] == 1)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    G.addedge(i + N, j, inf);
    //                cout <<"edge "<< i +1<<" "<< j+1 << endl;
                }
            }

        }
        cout << G.maxflow(S, T);
        vector<int> ans;
        for (int i = 2 * N; i < G.es.size(); i += 2)
        {
            edge & e = G.es[i];
        //    edge & oe = G.es[i ^ 1];
            if (e.u != S && e.v != T &&e.flow )
            {
                ans.push_back(i);
        //        cout << e.u + 1 << " "<< e.v + 1 << " " << e.flow << endl;
            }
    //        if (e.u == S) cout <<  e.v + 1 << " " << e.flow << endl;
        }
        cout << " "<< ans.size() << endl;
        for (int i = 0; i < ans.size() ; i++)
        {
            edge & e = G.es[ans[i]];
        //    edge & oe = G.es[ans[i] ^ 1];
            cout << (e.u - N + 1) << " "<< (e.v + 1) << " " << e.flow << endl;
        }
    }
}
