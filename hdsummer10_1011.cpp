#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}
template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}
const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write()
{
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s)
{
    while(*s)
    {
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x)
    {
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x)
    {
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}
const int maxn = 100000 + 100;
const int maxm = 350000 + 100;
int n, m;
ll dis[maxn];
ll dis2[maxn];
bool inq[maxn];
struct edge
{
  int v;
  ll w;
} es[maxm];
int tot;
vector<int> G[maxn];
int pre[maxn];
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  tot = 0;
  memset(dis, inf, sizeof(dis));
  memset(dis2, inf, sizeof(dis2));
  memset(inq,0,sizeof(inq));
}
void addedge(int u, int v, ll w)
{
  G[u].push_back(tot);
  es[tot++] = {v, w};
  G[v].push_back(tot);
  es[tot++] = {u, w};
}
ll spfa()
{
  dis[1] = 0;
  queue<int> Q;
  Q.push(1);
  inq[1] = true;
  pre[1] = 1;
  while(!Q.empty())
  {
    int u = Q.front();Q.pop();
    inq[u] = false;
    for (int eno: G[u])
    {
      edge & e = es[eno];
      if (dis[e.v] > dis[u] + e.w)
      {
        dis[e.v] = dis[u] + e.w;
        pre[e.v] = u;
        if (!inq[e.v])
        {
          Q.push(e.v);
          inq[e.v] = true;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    Q.push(i);
    inq[i] = true;
    for (int eno: G[i])
    {
      edge & e = es[eno];
      if (dis2[e.v] > dis[i] + e.w && pre[e.v] != i)
      {
        dis2[e.v] = dis[i] + e.w;
      }
    }
  }
  while(!Q.empty())
  {
    int u = Q.front();
    Q.pop();
    inq[u] = false;
    for (int eno: G[u])
    {
      edge & e = es[eno];
      if (dis2[e.v] > dis2[u] + e.w)
      {
        dis2[e.v] = dis2[u] + e.w;
        if (!inq[e.v])
        {
          inq[e.v] = true;
          Q.push(e.v);
        }
      }
    }
  }
  return dis2[n];
}
int main()
{
  int T;
  while(in(T))
  {
    while(T--)
    {
      in(n);
      in(m);
      init();
      for (int i = 0; i < m; i++)
      {
        static int u,v;
        static ll w;
        in(u);
        in(v);
        in(w);
        addedge(u,v,w);
      }
      printf("%lld\n", spfa());
    }
  }
}
