#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MS(a) memset(a,0,sizeof(a))
#define MP make_pair
#define PB push_back
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//////////////////////////////////////////////////////////////////////////
const int maxn = 1e5+10;

int n,m,tot;
vector<int> g[maxn];
int low[maxn],dfn[maxn],vis[maxn],ins[maxn],r[maxn],w[maxn];
stack<int> s;

void tarjan(int u){
    vis[u] = ins[u] = 1;
    dfn[u] = low[u] = ++tot;
    s.push(u);
    for(int i=0; i<(int)g[u].size(); i++){
        int v = g[u][i];
        if(!vis[v]){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(ins[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
    int sum = 0;
    if(dfn[u] == low[u]){
        int t;
        do{
            t = s.top();
            s.pop();
            ins[t] = 0;
            sum += w[t];
            r[t] = u;
        }while(u != t);
        w[u] = sum;
    }
}

void upd(){
    for(int i=1; i<=n; i++){
        if(i != r[i]){
            for(int j=0; j<(int)g[i].size(); j++){
                int v = g[i][j];
                if(v != r[i]) g[r[i]].push_back(v);
            }
        }
    }
}

int ans,sum;
void dfs(int u){
    sum += w[u];
    for(int i=0; i<(int)g[u].size(); i++){
        int v = g[u][i];
        if(u == r[v]) continue;
        dfs(v);
    }
    ans = max(ans,sum);
    sum -= w[u];
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        scanf("%d",&w[i]);
    for(int i=0; i<m; i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    for(int i=1; i<=n; i++)
        if(!dfn[i]) tarjan(1);
    upd();
    dfs(1);

    cout << ans << endl;

    return 0;
}
