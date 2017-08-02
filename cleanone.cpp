

#include <bits/stdc++.h>
using namespace std;
const int maxm=500+100;
const int INF=0x3f3f3f3f;

struct edge
{
    int from,to,c,f,cost;
    edge(int a,int b,int m,int n,int p):from(a),to(b),c(m),f(n),cost(p){}
};

int aabs(int a){
    return a>=0?a:-a;
}

struct MCMF{
    int m,s,t;
    vector<edge>e;
    vector<int>g[maxm];
    int dis[maxm],a[maxm],p[maxm];
    bool vis[maxm];

    void init(int n)
    {
        for(int i=0;i<=n;i++)g[i].clear();
        e.clear();
    }

    int add(int a,int b,int c,int v)
    {
        e.push_back(edge(a,b,c,0,v));
        e.push_back(edge(b,a,0,0,-v));
        m=e.size();
        g[a].push_back(m-2);
        g[b].push_back(m-1);
        return m - 2;
    }
    bool spfa(int& flow,int& cost){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        vis[s]=1;
        dis[s]=0;
        p[s]=0;
        a[s]=INF;
        while(!q.empty()){
            int u=q.front();q.pop();
            vis[u]=0;
            for(int i=0;i<g[u].size();i++){
                edge tmp=e[g[u][i]];
                if(dis[tmp.to]>dis[u]+tmp.cost&&tmp.c>tmp.f){
                    dis[tmp.to]=dis[u]+tmp.cost;
                    p[tmp.to]=g[u][i];
                    a[tmp.to]=min(a[u],tmp.c-tmp.f);
                    if(!vis[tmp.to]){
                        q.push(tmp.to);
                        vis[tmp.to]=1;
                    }
                }
            }
        }
        if(dis[t]==INF)return 0;
        flow+=a[t];
        cost+=dis[t]*a[t];
        int u=t;
        while(u!=s){
            e[p[u]].f+=a[t];
            e[p[u]^1].f-=a[t];
            u=e[p[u]].from;
        }
        return 1;
    }

    int MF(int s,int t){
        this->s=s;this->t=t;
        int flow=0,cost=0;
        while(spfa(flow,cost));
        return cost;
    }

} mcmf;
int main()
{
    int n, T, m;
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d%d", &n, &m);
            int superS = (n + 1) << 1;
            int superT = (n + 1) << 1 | 1;
            mcmf.init(superT);
            for (int i = 1; i <= n; i++)
            {
                mcmf.add(i << 1 | 1, i << 1, 1, 0);
                mcmf.add(superS, i << 1, 1, 0);
                mcmf.add(i << 1 | 1, superT, 1, 0);
            }
            for (int i = 0; i < m; i++)
            {
                static int u, v, w;
                scanf("%d%d%d", &u, &v, &w);
                mcmf.add(u << 1, v << 1 | 1, 1, w);
            }
            int ans = mcmf.MF(superS, superT);
            printf("%d\n", ans);
        }
    }
}
