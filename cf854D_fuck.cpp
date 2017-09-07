#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
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
ll inc[maxn], outc[maxn];
vector<int> G[maxn];
int n, m, k;
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  int bday, eday;
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d%d", &fs[i].d, &fs[i].f, &fs[i].t, &fs[i].c);
    G[fs[i].d].push_back(i);
  }
  for (int i = 1; i < maxn; i++)
  {
    inc[i] = outc[i] = indis[i] = outdis[i] = LLONG_MAX;
  }
  set<int> in, out;
  ll cost = LLONG_MAX;
  for (int i = 1; i < maxn; i++)
  {
    for (int p: G[i])
    {
      if (fs[p].t == 0)
      {
        if (indis[fs[p].f] > fs[p].c)
        {
          if (in.find(fs[p].f) == in.end())
          {
            in.insert(fs[p].f);
            indis[fs[p].f] = fs[p].c;
            if (in.size() == n)
            {
              cost = 0;
              for (int j = 1; j <= n; j++)
              {
                cost += indis[j];
              }
            }
          }
          else if (in.size() == n)
          {
            cost -= indis[fs[p].f];
            cost += fs[p].c;
            indis[fs[p].f] = fs[p].c;
          }
          else
          {
            indis[fs[p].f] = fs[p].c;
          }
        }
      }
    }
      inc[i] = cost;
  }
  cost = LLONG_MAX;
  for (int i = maxn-1; i >0; i--)
  {
    for (int p: G[i])
    {
      if (fs[p].f == 0)
      {
        if (outdis[fs[p].t] > fs[p].c)
        {
          if (out.find(fs[p].t) == out.end())
          {
            out.insert(fs[p].t);
            outdis[fs[p].t] = fs[p].c;
            if (out.size() == n)
            {
              cost = 0;
              for (int j = 1; j <= n; j++)
              {
                cost += outdis[j];
              }
            }
          }
          else if (out.size() == n)
          {
            cost -= outdis[fs[p].t];
            cost += fs[p].c;
            outdis[fs[p].t] = fs[p].c;
          }
          else
          {
            outdis[fs[p].t] = fs[p].c;
          }
        }
      }
    }
        outc[i] = cost;
  }
  ll ans = LLONG_MAX;
  for (int i = 1; i + k + 1< maxn; i++)
  {
    if (inc[i] != LLONG_MAX && outc[i + k + 1] != LLONG_MAX)
    {
      ans = min(ans, inc[i] + outc[i + k + 1]);
    }
  }
  if (ans == LLONG_MAX)
  {
    ans = -1;
  }
  printf("%lld\n", ans);
}
