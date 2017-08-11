#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
const ll moder = 998244353;
typedef pair<int,int> pii;
int T;
int n;
struct edge
{
  int to, w;
} es[maxn * 4];

int tot;
set<int> uG[maxn];
set<int> vG[maxn];
int visu[maxn];
int visv[maxn];
ll ans;
void addedge(int u, int v, int w)
{
  es[tot] = {v, w};
  uG[u].insert(tot++);
  es[tot] = {u, w};
  vG[v].insert(tot++);
}
void rdfs(int v)
{
  if (vG[v].size() == 0)
  {
    ans = 0;
  }
  else if (vG[v].size() == 1)
  {
    visv[v] = 1;
    for (int eno : vG[v])
    {
      edge & e = es[eno];
      visu[e.to] = 1;
      uG[e.to].erase(eno ^ 1);
      for (int reno: uG[e.to])
      {
        edge & e2 = es[reno];
        vG[e2.to].erase(reno ^ 1);
        rdfs(e2.to);
      }
      ans = (ans * e.w) % moder;
    }
  }
}
int main()
{
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      ans = 1;
      tot = 0;
      for (int i = 1; i <= n; i++)
      {
        uG[i].clear();
        vG[i].clear();
      }
      for (int i = 1; i <= n; i++)
      {
        static int v1, v2, w1, w2;
        scanf("%d%d%d%d", &v1, &w1, &v2, &w2);
        addedge(i, v1, w1);
        addedge(i, v2, w2);
      }
      memset(visv,0,sizeof(visv));
      memset(visu,0,sizeof(visu));
      for (int i = 1; i <= n; i++)
      {
        if (!visv[i])
        {
          rdfs(i);
        }
      }
      for (int i = 1; i <= n; i++)
      {
        if (!visu[i])
        {
          ll sum = 0;
          int u = i, v = es[*uG[i].begin()].to;
          ll tmp = 1;
          while(!visu[u])
          {
            visu[u] = 1;
            for (int eno : uG[u])
            {
              edge & e = es[eno];
              if (e.to == v)
              {
                tmp *= e.w;
                tmp %= moder;
                for (int reno: vG[v])
                {
                  if (reno != (eno ^ 1))
                  {
                    edge & re = es[reno];
                    u = re.to;
                    if (es[*uG[u].begin()].to == v)
                    {
                      v = es[*uG[u].rbegin()].to;
                    }
                    else
                    {
                      v = es[*uG[u].begin()].to;
                    }
                    break;
                  }
                }
                break;
              }
            }
          }
          sum += tmp;
          tmp = 1;
          u = i;
          v = es[*uG[i].rbegin()].to;
          while(visu[u] != 2)
          {
            visu[u] = 2;
            for (int eno : uG[u])
            {
              edge & e = es[eno];
              if (e.to == v)
              {
                tmp *= e.w;
                tmp %= moder;
                for (int reno: vG[v])
                {
                  if (reno != (eno ^ 1))
                  {
                    edge & re = es[reno];
                    u = re.to;
                    if (es[*uG[u].begin()].to == v)
                    {
                      v = es[*uG[u].rbegin()].to;
                    }
                    else
                    {
                      v = es[*uG[u].begin()].to;
                    }
                    break;
                  }
                }
                break;
              }
            }
          }
          sum += tmp;
          sum %= moder;
          ans *= sum;
          ans %= moder;
        }
      }
      printf("%lld\n", ans);
    }
  }
}
