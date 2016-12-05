#include<bits/stdc++.h>

using namespace std;

const int maxn = 51;
const int maxp = 11;
const int inf = 0x3f3f3f3f;
int G[maxn * 2][maxn * 2];
int Source[maxn * 2][maxp];
int Dest[maxn * 2][maxp];
int Q[maxn * 2];
struct edge
{
    int from, to, cap, flow;
};

struct Dinic
{
    int n, m, s, t;
    vector<edge> es;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void add_edge(int from, int to, int cap)
    {
        es.push_back({from, to, cap, 0});
        es.push_back({to, from, 0, 0});
        m = es.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool bfs()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for(int i = 0; i < G[x].size();i++)
            {
                edge & e = es[G[x][i]];
                if(!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x, int a)
    {
        if( x == t || a == 0)
        {
            return a;
        }
        int flow = 0, f;
        for(int & i = cur[x]; i < G[x].size();i ++)
        {
            edge & e = es[G[x][i]];
            if(d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                es[G[x][i] ^ 1].flow -= f;

                flow += f;
                a -= f;
                if(a == 0)
                {
                    break;
                }
            }
        }
        return flow;
    }

    int maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while(bfs())
        {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, inf);
        }
        return flow;
    }
    void output(int neck, int flow)
    {
        int cnt = 0;
        for(int i = 0;i < m;i++)
        {
            if(es[i].flow > 0 && es[i].to < neck && es[i].)
            {
                cnt++;
            }
        }
        printf("%d %d\n",flow, cnt);
        for(int i = 0; i < m; i++)
        {
            if(es[i].flow > 0 &&es[i].to < neck)
            {
                printf("%d %d %d\n", es[i].from - neck, es[i].to, es[i].flow);
            }
        }
    }
};

int main()
{
    int p, n;
    while(scanf("%d%d",&p,&n)!=EOF)
    {
        Dinic D;
        int start = 2 * n;
        memset(G, 0, sizeof(G));
        int end = 2 * n + 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",Q + i);
            for(int j = 0; j < p; j++)
            {
                scanf("%d", Source[i] + j);
            }
            for(int j = 0; j < p; j++)
            {
                scanf("%d",Dest[i] + j);
            }
        }
        for(int i = 0; i < n; i++)
        {
            D.add_edge(i, i + n, Q[i]);
         //   G[i][i + n] = Q[i];
         //   printf("debug: edge %d %d\n",i, i + n);
            bool from0 = true, end0 = true;
            for(int j = 0; j < p; j++)
            {
                if(Source[i][j] == 1)
                {
                    from0 = false;
                }
                if(Dest[i][j] == 0)
                {
                    end0 = false;
                }
            }
            if(from0)
            {
                D.add_edge(start, i, inf);
               // G[start][i] = inf;
           //     printf("from to: %d\n",i);
            }
            if(end0)
            {
                D.add_edge(i + n, end, inf);
             //   G[i + n][end] = inf;
             //   printf("end to %d\n",i + n);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                bool isto = true;
                for(int k = 0; k < p; k++)
                {
                    if((Dest[i][k] == 1 && Source[j][k] == 0)||(Dest[i][k] == 0 && Source[j][k] == 1))
                    {
                        isto = false;
                        break;
                    }
                }
                if(isto)
                {
                    D.add_edge(i + n, j, inf);
                 //   G[i + n][j] = inf;
               //     printf("debug:edge %d %d\n", i + n, j);
                }
            }
        }
        D.output(n, D.maxflow(start, end));
    }
}
