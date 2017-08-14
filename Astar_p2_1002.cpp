#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxk = 20;

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
struct edge
{
  int v, w;
} es[maxn * 2];
int tot;
vector<int> G[maxn];
ll dis[maxn];
int fa[maxn][maxk];
int pos[maxn];
int depth[maxn];
int n, m;
void init()
{
  for (int i = 1; i <= n; i++)
  {
    G[i].clear();
  }
  tot = 0;
}
void addedge(int u, int v, int w)
{
  G[u].push_back(tot);
  es[tot++] = {v, w};
  G[v].push_back(tot);
  es[tot++] = {u, w};
}
int lca(int x, int y)
{
  if (depth[x] > depth[y]) swap(x, y);
  for (int k = maxk - 1; k >= 0; k--)
  {
    if (depth[fa[y][k]] >= depth[x])
    {
      y = fa[y][k];
    }
  }
  if (x == y) return x;
  for (int k = maxk -1 ; k>= 0; k--)
  {
    if (fa[x][k] != fa[y][k])
    {
      x = fa[x][k];
      y = fa[y][k];
    }
  }
  return fa[x][0];
}
void dfs(int cur, int parent)
{
  fa[cur][0] = parent;
  for (int k = 1; k < maxk; k++)
  {
    fa[cur][k] = fa[fa[cur][k - 1]][k - 1];
  }
  for (int eno: G[cur])
  {
    edge & e = es[eno];
    if (e.v != parent)
    {
      dis[e.v] = e.w + dis[cur];
      depth[e.v] = 1 + depth[cur];
      dfs(e.v, cur);
    }
  }
}
int Q;
ll dist(int u, int v)
{
  int _lca = lca(u, v);
  return dis[u] + dis[v] - 2 * dis[_lca];
}
vector<int> fac[maxn];
struct query
{
  int x, y, id;
  bool operator<(const query & rhs)
  {
    if (x != rhs.x) return x < rhs.x;
    else if (y != rhs.y) return y < rhs.y;
    return id < rhs.id;
  }
} qs[maxn];
ll ans[maxn];
void solve()
{
  // scanf("%d%d", &n, &m);
  in(n);in(m);
  init();
  for (int i = 1; i < n; i++)
  {
    static int u, v, w;
    // scanf("%d%d%d", &u, &v, &w);
    in(u);in(v);in(w);
    addedge(u, v, w);
  }
  dfs(1, 1);
  for (int i = 1; i <= m; i++)
  {
    static int gg;
    in(gg);
    // scanf("%d", &gg);
    fac[i].clear();
    for (int j = 0; j < gg; j++)
    {
      static int tmp;
      in(tmp);
      // scanf("%d", &tmp);
      fac[i].push_back(tmp);
    }
  }
  // scanf("%d", &Q);
  in(Q);
  for (int i = 0; i < Q; i++)
  {
    int a, b;
    // scanf("%d%d", &a, &b);
    in(a);
    in(b);
    qs[i] = {a, b, i};
    // printf("%lld\n", dist(pos[a], pos[b]));
  }
  sort(qs, qs + Q);
  for (int i = 0; i < Q; i++)
  {
    if (i && qs[i].y == qs[i - 1].y && qs[i].x == qs[i - 1].x) {ans[qs[i].id] = ans[qs[i - 1].id];continue;}
    ll tans = 0x3f3f3f3f3f3f3f3f;
    // cout << qs[i].x << " "<< qs[i].y << endl;
    for (int j : fac[qs[i].x])
    {
      for (int k : fac[qs[i].y])
      {
        tans = min(tans, dist(j, k));
        // cout << dist(j, k)<<endl;
      }
    }
    ans[qs[i].id] = tans;
  }
  for (int i = 0; i < Q; i++)
  {
    printf("%lld\n", ans[i]);
  }
}
int main()
{
  // freopen("data.in", "r", stdin);
  int T;
  while(in(T))
  {
    while(T--)
    {
      solve();
    }
  }
}
