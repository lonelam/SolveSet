#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef pair<int,int> pii;
// int d[maxn], f[maxn], t[maxn], c[maxn];
struct fly
{
  int d,f,t,c;
  bool operator<(const fly & rhs) const
  {
    return d < rhs.d;
  }
} fs[maxn];
ll indis[maxn], outdis[maxn];
bool inq[maxn];
map<int,vector<pii> > G;
int n, m, k;
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  int bday, eday;
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d%d", &fs[i].d, &fs[i].f, &fs[i].t, &fs[i].c);
    if (fs[i].f == 0)
    {
      eday = fs[i].d;
    }
    if (fs[i].t == 0)
    {
      bday = fs[i].d;
    }
  }
  sort(fs, fs + m);
  int t;
  ll outcost = 0, incost = 0;
  for (t = 0; t < m; t++)
  {
    if (fs[t].d == eday)
    {
      break;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    indis[i] = outdis[i] = LLONG_MAX;
  }
  indis[0] = outdis[0] = 0;
  for (; t < m; t++)
  {
    if (t==0 || fs[t].d != fs[t-1].d)
    {
      queue<int> Q;
      for (auto p : G)
      {
        Q.push(p.first);
        inq[p.first] = true;
      }
      while(!Q.empty())
      {
        int cur = Q.front();
        Q.pop();
        inq[cur] = false;
        if (outdis[cur] != LLONG_MAX)
        for (pii p: G[cur])
        {
          if (outdis[p.first] > outdis[cur] + (ll)p.second)
          {
            outdis[p.first] =  outdis[cur] + (ll)p.second;
            inq[p.first] = true;
            Q.push(p.first);
          }
        }
      }
      G.clear();
    }
      // outdis[fs[t].t] = min(outdis[fs[t].t], outdis[fs[t].f] + (ll)fs[t].c);
    // if (t==m || fs[t].d != fs[t-1].d)
    // {
    //   G.clear();
    // }
    // if (t < m)
    // {
      G[fs[t].f].push_back({fs[t].t, fs[t].c});
    // }
  }
    {
      queue<int> Q;
      for (auto p : G)
      {
        Q.push(p.first);
        inq[p.first] = true;
      }
      while(!Q.empty())
      {
        int cur = Q.front();
        Q.pop();
        inq[cur] = false;
        if (outdis[cur] != LLONG_MAX)
        for (pii p: G[cur])
        {
          if (outdis[p.first] > outdis[cur] + (ll)p.second)
          {
            outdis[p.first] =  outdis[cur] + (ll)p.second;
            inq[p.first] = true;
            Q.push(p.first);
          }
        }
      }
      G.clear();
    }
  for (t = m - 1; t >= 0; t--)
  {
    if (fs[t].d == bday)
    {
      break;
    }
  }
  for (;t >= 0; t--)
  {
    if (t == m-1 || fs[t].d != fs[t+1].d)
    {
      queue<int> Q;
      for (auto p : G)
      {
        Q.push(p.first);
        inq[p.first] = true;
      }
      while(!Q.empty())
      {
        int cur = Q.front();
        Q.pop();
        inq[cur] = false;
        if (indis[cur] != LLONG_MAX)
        for (pii p: G[cur])
        {
          if (indis[p.first] > indis[cur] + (ll)p.second)
          {
            indis[p.first] =  indis[cur] + (ll)p.second;
            inq[p.first] = true;
            Q.push(p.first);
          }
        }
      }
      G.clear();
    }
    G[fs[t].t].push_back({fs[t].f, fs[t].c});
  }
    {
      queue<int> Q;
      for (auto p : G)
      {
        Q.push(p.first);
        inq[p.first] = true;
      }
      while(!Q.empty())
      {
        int cur = Q.front();
        Q.pop();
        inq[cur] = false;
        if (indis[cur] != LLONG_MAX)
        for (pii p: G[cur])
        {
          if (indis[p.first] > indis[cur] + (ll)p.second)
          {
            indis[p.first] =  indis[cur] + (ll)p.second;
            inq[p.first] = true;
            Q.push(p.first);
          }
        }
      }
      G.clear();
    }
  for (int i = 1; i <= n; i++)
  {
    if (outdis[i] == LLONG_MAX || indis[i] == LLONG_MAX)
    {
      outcost = LLONG_MAX;
      incost = LLONG_MAX;
      break;
    }
    else
    {
      outcost += outdis[i];
      incost += indis[i];
    }
  }
  if (eday - bday - 1 < k || outcost == LLONG_MAX || incost == LLONG_MAX)
  {
    printf("-1\n");
  }
  else
  {
    printf("%lld\n", outcost + incost);
  }
}
