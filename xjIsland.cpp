#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 100;
const int maxm = 100000 + 100;
vector<int> G[maxn];
int n, m;
int dfn[maxn];
int low[maxn];
int stk[maxn];
int top;
int dfs_clock;
int an;
int be[maxn];
int flg[maxn];
void dfs(int x)
{
  dfn[x] = low[x] = dfs_clock++;
  stk[++top] = x;
  flg[x] = 1;
  for (int v: G[x])
  {
    if (dfn[v] == -1)
    {
      dfs(v);
      low[x] = min(low[x], low[v]);
    }
    else if (flg[v] == 1)
    {
      low[x] = min(low[x], dfn[v]);
    }
  }
  if (dfn[x] == low[x])
  {
    while(stk[top] != x)
    {
      flg[stk[top]] = 0;
      be[stk[top]] = an;
      top--;
    }
    flg[x] = 0;
    be[x] = an++;
    top--;
  }
}
void init()
{
  for (int i = 0; i < n; i++)
  {
    G[i].clear();
  }
}
int outd[maxn];
int ind[maxn];
int cnt[maxn];
void SC()
{
  memset(low,0,sizeof(low));
  memset(outd,0,sizeof(outd));
  memset(ind,0,sizeof(ind));
  memset(dfn,-1,sizeof(dfn));
  memset(flg, 0, sizeof(flg));
  memset(be,0,sizeof(be));
  memset(cnt,0,sizeof(cnt));
  top = 0;
  an = 0;
  dfs_clock = 0;
  for (int i = 0; i < n; i++)
  {
    if (dfn[i] == -1)
    {
      dfs(i);
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int v: G[i])
    {
      if (be[i] != be[v])
      {
        ind[be[v]]++;
        outd[be[i]]++;
      }
    }
  }
  int cnt1=0,cnt2=0;
  for (int i = 0; i < an; i++)
  {
    if (ind[i] == 0)
    {
      cnt1++;
    }
    if (outd[i] == 0)
    {
      cnt2++;
    }
  }
  printf("%d\n", max(cnt1, cnt2));
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; i++)
    {
      static int u,v;
      scanf("%d%d", &u, &v);
      u--,v--;
      G[u].push_back(v);
    }
    SC();
  }
}
