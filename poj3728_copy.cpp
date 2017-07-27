

#include<cstdio>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define swap(a,b) (a^=b,b^=a,a^=b)
using namespace std;
const int mm=333333;
const int mn=55555;
int s[mm],t[mm],d[mm],p[mm],ans[mm];
int h[mn]={0},q[mn]={0},g[mn]={0},f[mn],mx[mn],mi[mn],up[mn]={0},dw[mn]={0};
bool vis[mn]={0};
int i,j,k,n,m,e;
inline void add(int u,int v,int c,int h[])
{
    s[e]=u,t[e]=v,d[e]=c,p[e]=h[u],h[u]=e++;
    s[e]=v,t[e]=u,d[e]=-c,p[e]=h[v],h[v]=e++;
}
int find(int x)
{
    if(f[x]==x)return x;
    int y=f[x];
    f[x]=find(f[x]);
    up[x]=max(mx[y]-mi[x],max(up[x],up[y]));
    dw[x]=max(mx[x]-mi[y],max(dw[x],dw[y]));
    mx[x]=max(mx[x],mx[y]);
    mi[x]=min(mi[x],mi[y]);
    return f[x];
}
void tarjan(int u)
{
    int i,v,x,y;
    vis[f[u]=u]=1;
    for(i=q[u];i;i=p[i])
        if(vis[v=t[i]])
            v=find(v),t[e]=i,p[e]=g[v],g[v]=e++;
    for(i=h[u];i;i=p[i])
        if(!vis[v=t[i]])tarjan(v),f[v]=u;
    for(i=g[u];i;i=p[i])
    {
        v=t[i],x=s[v],y=t[v],find(x);
        if(d[v]<0)swap(x,y),v=-d[v];
        else v=d[v];
        ans[v]=max(mx[y]-mi[x],max(up[x],dw[y]));
    }
}
inline void get(int &a)
{
    char c;
    while((c=getchar())<'0'||c>'9');
    for(a=0;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
}
void out(int x)
{
    if(x>9)out(x/10);
    putchar(x%10+'0');
}
int main()
{
    for(get(n),i=1; i<=n; ++i)get(mx[i]),mi[i]=mx[i];
    for(e=k=1; k<n; ++k)get(i),get(j),add(i,j,0,h);
    for(get(m),k=1; k<=m; ++k)get(i),get(j),add(i,j,k,q);
    tarjan(1);
    for(i=1; i<=m; ++i)out(ans[i]),puts("");
    return 0;
}
