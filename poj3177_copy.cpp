#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN=5005;

int n,m,num,ans,cnt,top;
int stak[MAXN],low[MAXN],dfn[MAXN],color[MAXN],deg[MAXN];//biocks[i]表示删掉i点后，能形成的连通块数
vector<int> g[MAXN];
bool isIn[MAXN],vis[MAXN][MAXN];

void Tarjan(int u,int p) {//求无向图的边双连通分量的Tarjan与求有向图的强连通分量的Tarjan好像...
    stak[++top]=u;
    isIn[u]=true;
    dfn[u]=low[u]=++num;
    int v;
    for(int i=0;i<g[u].size();++i) {
        v=g[u][i];
        if(v!=p) {
            if(dfn[v]==0) {
                Tarjan(v,u);
                low[u]=min(low[u],low[v]);
            }
            else if(isIn[v]&&dfn[v]<low[u])
                low[u]=dfn[v];
        }
    }

    if(dfn[u]==low[u]) {
        ++cnt;
        do {
            v=stak[top--];
            isIn[v]=false;
            color[v]=cnt;//一个边双连通分量缩成一个点
        } while(v!=u);
    }
}

int solve() {
    cnt=num=top=0;//cnt表示边双连通分量的个数
    memset(dfn,0,sizeof(dfn));
    memset(isIn,false,sizeof(isIn));
    for(int i=1;i<=n;++i) {
        if(dfn[i]==0)
            Tarjan(i,0);
    }

    memset(deg,0,sizeof(deg));
    for(int i=1;i<=n;++i) {
        for(int j=0;j<g[i].size();++j)
            if(color[i]!=color[g[i][j]])//若这两个点不再同一个双连通分量中
                ++deg[color[i]];//由于是无向图，所以只对起点的度+1即可
    }
    int ans=0;
    for(int i=1;i<=cnt;++i)
        if(deg[i]==1)
            ++ans;
    return (ans+1)>>1;
}

int main() {
    int s,e;
    while(scanf("%d%d",&n,&m)==2) {
        for(int i=1;i<=n;++i) {
            g[i].clear();
            for(int j=i;j<=n;++j)
                vis[i][j]=vis[j][i]=false;
        }

        while(m-->0) {
            scanf("%d%d",&s,&e);
            if(!vis[s][e]) {//去掉重边
                vis[s][e]=vis[e][s]=true;
                g[s].push_back(e);
                g[e].push_back(s);
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}
