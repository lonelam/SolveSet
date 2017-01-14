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
const int maxn = 200 + 5;

struct edge
{
    int from, to, cap, flow, cost;
    edge (int a, int b, int m, int p):from(a), to(b), cap(m), flow(0), cost(p) {}
};

int aabs(int a)
{
    return a >= 0 ? a : -a;
}
struct MCMF
{
    int m, s, t;
    vector<edge> e;
    vector<int> g[maxn * maxn];
    int dis[maxn * maxn], a[maxn * maxn], p[maxn * maxn];
    bool vis[maxn * maxn];
    void init(int n)
    {
        for (int i = 0; i <= n; i++) g[i].clear();
        e.clear();
        m = 0;
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
    }
    void add(int a, int b, int c, int v)
    {
        g[a].push_back(m);
        g[b].push_back(m + 1);
        e.push_back(edge(a,b,c,v));
        e.push_back(edge(b,a,0,-v));
        m = e.size();
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
            int u = Q.front(); Q.pop();
            vis[u] = 0;
            for (int i = 0; i < g[u].size(); i++)
            {
                edge & tmp = e[g[u][i]];
                if (dis[tmp.to] > dis[u] + tmp.cost && tmp.cap > tmp.flow)
                {
                    dis[tmp.to] = dis[u] + tmp.cost;
                    p[tmp.to] = g[u][i];
                    a[tmp.to] = min(a[u], tmp.cap - tmp.flow);
                    if (!vis[tmp.to])
                    {
                        Q.push(tmp.to);
                        vis[tmp.to] = 1;
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
            e[p[u]].flow+=a[t];
            e[p[u]^1].flow -= a[t];
            u = e[p[u]].from;
        }
        return 1;
    }
    int mincost(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0, cost = 0;
        while(spfa(flow, cost));
        return cost;
    }
};
char grid[maxn][maxn];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main()
{
    int n, m;
    ios::sync_with_stdio(false);
    while(cin >> n >> m)
    {
        MCMF MF;
        if (n == 0 && m == 0)
        {
            break;
        }
        int S = n * m + 1;
        int T = S + 1;
        int tot = T + 1;
        MF.init(tot);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
            for(int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'm')
                {
                    MF.add(S, i * m + j + 1, 1, 0);
        //            cout <<"m ";
                }
                else if (grid[i][j] == 'H')
                {
                    MF.add(i * m + j+1, T, 1, 0);
                //    cout <<"eiwgo";
                }
                for (int d = 0; d < 4; d++)
                {
                    int tx = i + dx[d];
                    int ty = j + dy[d];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m)
                    {
                        MF.add(i * m + j+1, tx * m + ty+1, inf,1);
                        //cout <<"addege";
                    }
                }
            }
        }
        cout << MF.mincost(S, T) << endl;
    }
}
/*

2 2
.m
H.
5 5
HH..m
.....
.....
.....
mm..H
7 8
...H....
...H....
...H....
mmmHmmmm
...H....
...H....
...H....
0 0


5 5
HH..m
.....
.....
.....
mm..H
7 8
...H....
...H....
...H....
mmmHmmmm
...H....
...H....
...H....
0 0
*/
