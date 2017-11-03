
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
struct node
{
  int x, y;
};
vector<node> E[maxn];
int inq[maxn], dis[maxn];
int flg = 0;
void solve(int x)
{
  if (flg)
  {
    return;
  }
  inq[x] = 1;
  for (int i = 0; i < E[x].size(); i++)
  {
    node v = E[x][i];
    if (dis[v.x] > dis[x] + v.y)
    {
      dis[v.x] = dis[x] + v.y;
      if (inq[v.x])
      {
        flg = 1;
        return;
      }
      else
      {
        solve(v.x);
      }
    }
  }
  inq[x] = 0;
}
int n, m;
int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    memset(dis, inf, sizeof(dis));
    for (int i = 1; i <= m; i++)
    {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      int e;
      if (a == 1)
      {
        scanf("%d", &e);
        E[b].push_back((node){c, -e});
      }
      else if (a == 2)
      {
        scanf("%d", &e);
        E[c].push_back((node){b, e});
      }
      else if (a == 3)
      {
        E[b].push_back((node) {c, 0});
      }
    }
    for (int i = 1; i <= n; i++)
    {
      dis[i] = 0;
      solve(i);
    }
    if (flg) printf("No\n");
    else printf("Yes\n");
  }
}
