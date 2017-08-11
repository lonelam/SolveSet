#include<iostream>
#include<cstdio>
#include<set>
#define N 100010
#define ll long long
using namespace std;
int x,y,deep[N],fa[N][20],point[N],next[N*2],d[N],cnt,t,pos[N],n,q,vis[N];
ll ans,dis[N],v;
set<int>s;
struct use{int st,en;ll v;}e[N*2];
void add(int x,int y,ll v){
  next[++cnt]=point[x];point[x]=cnt;
  e[cnt].st=x;e[cnt].en=y;e[cnt].v=v;
}
void dfs(int x){
   d[x]=++t;pos[t]=x;
   for (int i=1;(1<<i)<=deep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
   for (int i=point[x];i;i=next[i])
   	 if (e[i].en!=fa[x][0]){
   	   fa[e[i].en][0]=x;deep[e[i].en]=deep[x]+1;
   	   dis[e[i].en]=dis[x]+e[i].v;dfs(e[i].en);
   	 }
}
int lca(int x,int y){
  if (deep[x]<deep[y]) swap(x,y);int c=deep[x]-deep[y];
  for (int i=0;i<=18;i++)if (c&(1<<i)) x=fa[x][i];
  for (int i=18;~i;i--)if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
  if (x!=y) return fa[x][0];else return x;
}
ll cal(int x,int y){int f=lca(x,y);return dis[x]+dis[y]-2*dis[f];}
int main(){
  scanf("%d%d",&n,&q);
  for (int i=1;i<n;i++){scanf("%d%d%lld",&x,&y,&v);add(x,y,v);add(y,x,v);}
  dfs(1);s.insert(-1);s.insert(999999);
  for (int i=1;i<=q;i++){
    scanf("%d",&x);int p,l,r;ll temp(0);
    if (!vis[x]){s.insert(d[x]);p=1;}else{s.erase(d[x]);p=-1;}
    vis[x]=!vis[x];
    l=*--s.lower_bound(d[x]);r=*s.upper_bound(d[x]);
	if (l!=-1) ans+=cal(pos[l],x)*p;if (r!=999999) ans+=cal(pos[r],x)*p;
	if (l!=-1&&r!=999999) ans-=cal(pos[l],pos[r])*p;
	if (s.size()!=2) temp=cal(pos[*++s.begin()],pos[*--s.lower_bound(999999)]);
    printf("%lld\n",ans+temp);
  }
}
