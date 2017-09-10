//#define _TEST _TEST
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
/************************************************
Code By willinglive    Blog:http://willinglive.cf
************************************************/
#define rep(i,l,r) for(int i=(l),___t=(r);i<=___t;i++)
#define per(i,r,l) for(int i=(r),___t=(l);i>=___t;i--)
#define MS(arr,x) memset(arr,x,sizeof(arr))
#define LL long long
#define INE(i,u,e) for(int i=head[u];~i;i=e[i].next)
#define MP make_pair
typedef pair<int,int>pii;
inline const int read()
{int r=0,k=1;char c=getchar();for(;c<'0'||c>'9';c=getchar())if(c=='-')k=-1;
for(;c>='0'&&c<='9';c=getchar())r=r*10+c-'0';return k*r;}
/////////////////////////////////////////////////
const int N=30010;
const int M=100010;
int n,m;
int out[N],in[N],top;
struct Option{int c,a,b;}opt[40010]; int all;
/////////////////////////////////////////////////
inline void MIN(int &a,int b){if(a>b)a=b;}
namespace UFS
{///////////////////////////////////
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unio(int x,int y){fa[find(y)]=find(x);}
}///////////////////////////////////
namespace BIT
{///////////////////////////////////
int c[N*2];
int query(int o){int s=0;for(;o<=n<<1;o+=o&-o)s+=c[o];return s;}
void add(int o,int x){for(;o;o-=o&-o)c[o]+=x;}
}///////////////////////////////////
namespace Graph
{///////////////////////////////////
struct Edge{int v,next; bool del;}e[2*M];
int head[N],k;
map<pii,bool>edge;
void adde(int u,int v){e[k].v=v;e[k].next=head[u];head[u]=k++;}
int dfn[N],low[N],dfsclock;
int fa[N];
void buildgraph()
{
	for(map<pii,bool>::iterator it=edge.begin();it!=edge.end();it++)
	    if(it->second)
	    {
	    	int u=it->first.first,v=it->first.second;
	    	adde(u,v); adde(v,u);
	    }
}
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++dfsclock;
	INE(i,u,e)
	{
		int v=e[i].v; if(v==fa) continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			MIN(low[u],low[v]);
			if(low[v]<=dfn[u]) UFS::unio(u,v);
		}
		else MIN(low[u],dfn[v]);
	}
}
void contract(int x,int y)
{
	int f;
	for(;x!=y;x=f)
	{
		BIT::add(out[x],1); BIT::add(in[x]-1,-1);
		f=UFS::find(fa[x]);
		fa[x]=fa[y];
		UFS::unio(y,x);
	}
}
}///////////////////////////////////
namespace Tree
{///////////////////////////////////
struct Edge{int v,next; bool del;}e[2*M];
int head[N],k;
void adde(int u,int v){e[k].v=v;e[k].next=head[u];head[u]=k++;}
int dep[N];
int fa[N][16];
void buildtree()
{
	static bool vis[N]={0};
	rep(u,1,n)
	{
		int fu=UFS::find(u); if(vis[fu]) continue; vis[fu]=1;
		for(int i=Graph::head[u];~i;i=Graph::e[i].next)
		{
			int fv=UFS::find(Graph::e[i].v); if(fu==fv) continue;
			adde(fu,fv); adde(fv,fu);
		}
	}
}
void copytree()
{
	memcpy(Graph::e,e,sizeof(e));
	memcpy(Graph::head,head,sizeof(head));
	Graph::k=k;
	rep(i,1,n)
	{
		int rt=UFS::find(i);
		Graph::fa[i]=fa[rt][0];
	}
}
void dfs(int u,int d)
{
	in[u]=++top;
	dep[u]=d;
	INE(i,u,e)
	{
		int v=e[i].v; if(dep[v]) continue;
		fa[v][0]=u; rep(i,1,15) fa[v][i]=fa[fa[v][i-1]][i-1];
		dfs(v,d+1);
	}
	out[u]=++top;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	rep(i,0,15) if(d&(1<<i)) x=fa[x][i];
	if(x==y) return x;
	per(i,15,0) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int getdep(int u)
{
	return dep[u]-BIT::query(in[u]);
}
}///////////////////////////////////
/////////////////////////////////////////////////
void input()
{
	MS(Graph::head,-1); MS(Tree::head,-1);
	using namespace Graph;
    n=read(); m=read();
    int u,v;
    rep(i,1,m)
    {
    	u=read(); v=read();
    	if(u>v) swap(u,v);
    	edge[MP(u,v)]=1;
    }
    int c,a,b;
    int q = read();
    all = 1;
    while(q--)
    {
      c = read();
    	a=read(); b=read();
    	if(a>b) swap(a,b);
    	all++; opt[all].c=c; opt[all].a=a; opt[all].b=b;
    	if(!c) edge[MP(a,b)]=0;
    }
}
int kase = 1;
void solve()
{
  printf("Case #%d:\n", kase++);
  	rep(i,1,n) UFS::fa[i]=i;
	using namespace Graph;
	buildgraph();
    tarjan(1,-1);
    using namespace Tree;
    buildtree();
    dfs(1,1);
    copytree();
  	using namespace UFS;
  	static int ans[100010];
    int anstot = 0;
  	rep(i,1,all)
  	{
  		int a=find(opt[i].a),b=find(opt[i].b);
  		int x=find(lca(a,b));
  		if(opt[i].c==1)
  		{
  			contract(a,x);
  			contract(b,x);
  		}
  		else
  		{
  			ans[anstot]=getdep(a)+getdep(b)-2*getdep(x);
        anstot++;
  		}
  	}
    for (int i = 0; i < anstot; i++)

  	 printf("%d\n",ans[i]);
}
/////////////////////////////////////////////////
int main()
{
    #ifndef _TEST
    // freopen("lane.in","r",stdin); freopen("std.out","w",stdout);
    #endif
    int T;
    T = read();
    while(T--)
    input(),solve();
    return 0;
}
