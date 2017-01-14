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
const int maxn  = 1000  + 200;
const int maxm = 200000 + 1000;

struct edge
{
    int from, to, c, f, cost;
    edge (int a, int b, int m, int n, int p) : from(a), to(b), c(m), f(n), cost(p) {}
};
struct eg
{
    int from,to, flow, cap;
};

int aabs(int a)
{
    return a >= 0 ? a : -a;
}

struct isap
{
    int n,m,s,t;
    vector<int> G[maxn];
    vector<eg> es;
    bool vis[maxn];
    int num[maxn];
    int cur[maxn];
    int dis[maxn];
    int p[maxn];
    isap (int n_) :n(n_){}
    void add_edge(int u, int v,int cap)
    {
        es.push_back({u,v,0,cap});
        es.push_back({v,u,0,0});
        m = es.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }
    void bfs()
    {
        deque<int> q;
        for (int i = 0; i < n; i++)
        {
            dis[i] = n;
        }
        memset(vis, 0, sizeof(vis));
        q.push_back(t);
        dis[t] = 0;
        vis[t] = true;
        while(!q.empty())
        {
            int pos = q.front();
            q.pop_front();
            for (int i = 0; i <(int)G[pos].size(); i++)
            {
                eg & e = es[G[pos][i] ^ 1];
                if (e.cap > e.flow && !vis[e.from])
                {
                    dis[e.from] = dis[pos] + 1;
                    vis[e.from] = true;
                    q.push_back(e.from);
                }
            }
        }
    }
    int aug()
    {
        int x = t;
        int a = inf;
        while(x != s)
        {
            eg & e = es[p[x]];
            a = min(a,e.cap - e.flow);
            x = e.from;
        }
        x = t;
        while(x != s)
        {
            es[p[x]].flow += a;
            es[p[x] ^ 1].flow -= a;
            x = es[p[x]].from;
        }
        return a;
    }
    int maxflow(int s, int t)
    {
        int flow = 0;
        this->s = s;
        this->t = t;
        bfs();
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++)
        {
            num[dis[i]] ++;
        }
        int x = s;
        memset(cur, 0, sizeof(cur));
        while(dis[s] < n)
        {
            if (x == t)
            {
                flow += aug();
                x = s;
            }
            int ok = 0;
            for (int i = cur[x]; i <(int) G[x].size(); i++)
            {
                eg & e  = es[G[x][i]];
                if (e.cap > e.flow && dis[x] == dis[e.to] + 1)
                {
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i;
                    x = e.to;
                    break;

                }
            }
            if (!ok)
            {
                int m = n - 1;
                for (int i = 0; i < (int)G[x].size(); i++)
                {
                    eg & e = es[G[x][i]];
                    if (e.cap > e.flow)
                    {
                        m = min(m, dis[e.to]);
                    }
                }
                if (--num[dis[x]] == 0)
                {
                    break;
                }
                num[dis[x] = m + 1] ++;
                cur[x] = 0;
                if (x != s)
                {
                    x = es[p[x]].from;
                }
            }
        }
        return flow;
    }
};

vector<int> G[maxn];
vector<int> rG[maxn];
vector<edge> es;
int diss[maxn];
int dist[maxn];
bool inq[maxn];
void spfa(int s, int t, int dis[])
{
    memset(dis,inf, sizeof(int) * maxn);
    memset(inq, 0, sizeof(inq));
    queue<int> Q;
    dis[s] = 0;
    inq[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for (int i = 0; i <(int) G[u].size(); i++)
        {
            edge & ee = es[G[u][i]];
            if (dis[ee.to] > dis[u] + ee.cost)
            {
                dis[ee.to] = dis[u] + ee.cost;
                if (!inq[ee.to])
                {
                    Q.push(ee.to);
                    inq[ee.to] = true;
                }
            }
        }
    }
}


void spfa2(int s, int t, int dis[])
{
    memset(dis,inf, sizeof(int) * maxn);
    memset(inq, 0, sizeof(inq));
    queue<int> Q;
    dis[s] = 0;
    inq[s] = true;
    Q.push(s);

    while(!Q.empty())
    {

        int u = Q.front();
    //    cout << u << endl;
        Q.pop();
        inq[u] = false;
        for (int i = 0; i < (int)rG[u].size(); i++)
        {
            edge & ee = es[rG[u][i]];
//            cout << ee.from <<" "<< ee.to <<"  "<< ee.cost<<endl;
            if (dis[ee.from] > dis[u] + ee.cost)
            {
        //        cout << ee.cost << endl;
                dis[ee.from] = dis[u] + ee.cost;
                if (!inq[ee.from])
                {
                    inq[ee.from] = true;
                    Q.push(ee.from);
                }
            }
        }
    }
}
void add_edge(int from, int to, int ww)
{
    rG[to].push_back(es.size());
    G[from].push_back(es.size());
    es.push_back(edge(from, to, 1,0, ww));
}
/*
int main()
{
    int T;
    int u,v,w;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            int n, m;
            scanf("%d%d", &n, &m);
            MC.init(n);
            for (int i = 0; i < m; i++)
            {
                scanf("%d%d%d", &u,&v,&w);
                MC.add(u, v, 1, w);
            }
            int s,t;
        //    cout <<"debug";
            scanf("%d%d",&s, &t);
            MC.add(0, s, 1, 0);
        //    cout <<"weiog";
            int dis = MC.MF(0, t);
        //    cout <<"ewg";
            MC.MF(s, t);
            int l = 1, r = MC.mxflow + 1;
            while(l + 1 < r)
            {
        //        cout <<"weg";
                const int mid = l + (r - l) / 2;
                MC.e[MC.g[0][0]].c = mid;
                int mcc = MC.MF(0, t);
                int mcf = MC.mxflow;
                if (mcc == dis * mid)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            printf("%d\n", l);
        }
    }
}*/

int main()
{
    int T;
    int u,v,w;

        int n, m;
    while(scanf("%d", &n)!=EOF)
    {

        //    scanf("%d%d", &n, &m);
        isap MF(n + 1);
        for (int i = 0; i <= n; i++)
        {
            G[i].clear();
            rG[i].clear();
        }
            es.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &w);
                if (i != j && w != -1)
                {
                    add_edge(i, j, w);
                }
            }
        }



            int s,t;
        //    cout <<"debug";
            scanf("%d%d",&s, &t);
            //MC.add(0, s, 1, 0);
        //    cout <<"weiog";
            spfa(s, t, diss);
            spfa2(t, s, dist);
            int path = diss[t];
        //    cout << path;
            for (int i  = 0; i <(int) es.size(); i++)
            {
                edge & ee = es[i];
                if (diss[ee.from] + dist[ee.to] + ee.cost == path)
                {
                    MF.add_edge(ee.from, ee.to, 1);
                }
            }
            //int dis = MC.MF(0, t);
        //    cout <<"ewg";

/*            int l = 1, r = MC.mxflow + 1;
            while(l + 1 < r)
            {
        //        cout <<"weg";
                const int mid = l + (r - l) / 2;
                MC.e[MC.g[0][0]].c = mid;
                int mcc = MC.MF(0, t);
                int mcf = MC.mxflow;
                if (mcc == dis * mid)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }*/
            int ans = MF.maxflow(s, t);
            if (ans != inf)
            printf("%d\n",  ans );
            else printf("inf\n");
        }
}
