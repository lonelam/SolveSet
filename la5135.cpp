#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int maxn = 50010;
struct arc {
    int to,next;
    arc(int x = 0,int y = -1) {
        to = x;
        next = y;
    }
} e[1000010];
int head[maxn],dfn[maxn],low[maxn],idx,tot,cn;
bool cut[maxn];
void add(int u,int v) {
    e[tot] = arc(v,head[u]);
    head[u] = tot++;
    e[tot] = arc(u,head[v]);
    head[v] = tot++;
}
void tarjan(int u,int fa) {
    dfn[u] = low[u] = ++idx;
    int son = 0;
    for(int i = head[u]; ~i; i = e[i].next) {
        if(e[i].to == fa) continue;
        if(!dfn[e[i].to]) {
            tarjan(e[i].to,u);
            son++;
            low[u] = min(low[u],low[e[i].to]);
            if(fa != -1 && low[e[i].to] >= dfn[u] || fa == -1 && son > 1) {
                cut[u] = true;
                cn++;
            }
        } else low[u] = min(low[u],dfn[e[i].to]);
    }
}
bool vis[maxn];
int cnt,n,m,cao;
bool fk[maxn];
void dfs(int u,int fa) {
    vis[u] = true;
    cnt++;
    for(int i = head[u]; ~i; i = e[i].next) {
        if(e[i].to == fa) continue;
        if(cut[e[i].to]) {
            if(!fk[e[i].to]) {
                cao++;
                fk[e[i].to] = true;
            }
            continue;
        }
        if(vis[e[i].to]) continue;
        dfs(e[i].to,fa);
    }
}
int main() {
    int u,v,cs = 1;
    while(scanf("%d",&m),m) {
        memset(head,-1,sizeof head);
        for(int i = tot = n = idx = cn = 0; i < m; ++i) {
            scanf("%d%d",&u,&v);
            add(u,v);
            n = max(n,max(u,v));
        }
        memset(dfn,0,sizeof dfn);
        memset(cut,false,sizeof cut);
        for(int i = 1; i <= n; ++i)
            if(!dfn[i]) tarjan(i,-1);
        LL ret = 1;
        if(!cn) printf("Case %d: %d %I64d\n",cs++,2,(LL)n*(n-1)/2);
        else {
            memset(vis,false,sizeof vis);
            int ri = 0;
            for(int i = 1; i <= n; ++i) {
                if(cut[i] || vis[i]) continue;
                cnt = cao = 0;
                memset(fk,false,sizeof fk);
                dfs(i,-1);
                if(cao < 2 && cnt) {ri++; ret *= cnt;}
            }
            printf("Case %d: %d %I64d\n",cs++,ri,ret);
        }
    }
    return 0;
}
