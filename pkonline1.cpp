#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
int n, m, q;
int p[maxn];
int vis[maxn];
int ans;
int a, b;
    int j = 0, f = 0;
struct cmp
{
  cmp(){}
  bool operator()(const int lhs,const int rhs)const
  {
    return p[lhs] < p[rhs];
  }
};
    multiset<int, cmp> dm;
void check()
{
  int t;
    if (*dm.begin() == f)
    {
      t = p[*dm.begin()] + p[*(++dm.begin())];
      if (ans > t)
      {
        ans = t;
        a = f;
        b = *(++dm.begin());
      }
    }
    else
    {
      t = p[f] + p[*dm.begin()];
      if (ans > t)
      {
        ans = t;
        a = f;
        b = *(dm.begin());
      }
    }

}
int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    dm.clear();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
      scanf("%d", p + i);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
      static int bi;
      scanf("%d", &bi);
      vis[bi] = 1;
    }
    f = j = 0;
    while(vis[f]) f++;
    for (int i = 0; i < m; i++)
    {
      while (vis[j])
      {
        j++;
      }
      dm.insert(j);
      j++;
    }
    if (*dm.begin() == f)
    {
      ans = p[*dm.begin()] + p[*(++dm.begin())];
      a = f;
      b = *(++dm.begin());
    }
    else
    {
      ans = p[f] + p[*dm.begin()];
      a = *dm.begin();
      b = *(++dm.begin());
    }
    while(j < n)
    {
      while(vis[f])
      {
        f++;
      }
      dm.erase(dm.find(f++));
      while(vis[f])f++;
      while(vis[j] && j < n) j++;
      if (j == n) break;
      dm.insert(j++);
      while(vis[j] && j < n) j++;
      check();
      // if (ans > p[*dm.begin()] + p[*(++dm.begin())])
      // {
      //   ans = p[*dm.begin()] + p[*(++dm.begin())];
      //   a = *dm.begin();
      //   b = *(++dm.begin());
      // }
    }
    if (a > b) swap(a,b);
    printf("%d %d\n", a, b);
    // printf("%d\n", ans);
  }
}
