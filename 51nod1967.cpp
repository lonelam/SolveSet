#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxm = 400000 + 100;
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
struct edge
{
  int u, v;
  int inv;
} es[maxm];
int tot;
vector<int> G[maxn];
void inline addedge(int u, int v)
{
  G[u].push_back(tot);
  G[v].push_back(tot);
  es[tot++] = {u, v, -1};
}
int st[maxn];
void dfs(int cur)
{
  for (int & i = st[cur]; i < G[cur].size();)
  {
    edge & e = es[G[cur][i++]];
    if (e.inv == -1)
    {
      if (e.u == cur)
      {
        e.inv = 0;
        dfs(e.v);
      }
      else
      {
        e.inv = 1;
        dfs(e.u);
      }
    }
  }
}
int main()
{
  int n, m;
  in(n);
  in(m);
    int x, y;
    tot = 0;
    for (int i = 0; i < m; i++)
    {
      in(x);
      in(y);
      addedge(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
      if ((G[i].size())&1)
      {
        addedge(0, i);
      }
      else cnt++;
    }
    for (int i = 0; i <= n; i++)
    {
      if (st[i] != G[i].size())
      {
        dfs(i);
      }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < m; i++)
    {
      printf("%d", es[i].inv);
    }
    printf("\n");
}
