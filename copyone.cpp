#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5+7;
int fa[maxn];
vector<int> E[maxn];
long long p,e;
int vis[maxn];
void dfs(int x){
    p++;
    vis[x]=1;
    for(int i=0;i<E[x].size();i++){
        e++;
        if(vis[E[x][i]])continue;
        dfs(E[x][i]);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        p = 0;
        e = 0;
        if(vis[i])continue;
        dfs(i);
        if(e!=p*(p-1)){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
