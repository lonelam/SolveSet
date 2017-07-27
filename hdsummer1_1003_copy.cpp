#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
int n, kase;
vector<int> G[maxn], c[maxn];
//s 为子树大小
int L[maxn], R[maxn], s[maxn], f[maxn];
void dfs(int x, int fa, int && ncnt)
{
  //L is its dfsn
  L[x] = ++ncnt;
  s[x] = 1, f[x] = fa;
  for (auto & y: G[x])
  {
    if (y != fa)
    {
      dfs(y, x, move(ncnt));
      s[x] += s[y];
    }
  }
  //用L, R表示子树所在区间
  R[x] = ncnt;
}
//按dfs序排序
bool cmp(const int & x, const int & y)
{
  return L[x] < L[y];
}
void work()
{
  for (int i = 0; i <= n; i++)
  {
    c[i].clear();
    G[i].clear();
  }
  //读入colors, 用颜色索引点

  for (int i = 1; i <= n; i++)
  {
    int x;
    scanf("%d", &x);
    c[x].push_back(i);
  }
  //读图
  for (int i = 1; i < n; i++)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  //给树加了个根结点
  G[0].push_back(1);

  dfs(0, 0, 0);
  //n种颜色，都有可能在每一条路径上
  ll res = (ll)n * n * (n - 1) / 2;
  for (int i = 1; i <= n; i++)
  {
    if (c[i].empty())
    {
      //这种颜色不存在
      res -= (ll) n * (n - 1) / 2;
      continue;
    }
    cout << "color:  " << i << endl;
    //L[0] = 0;
    //0在每一个颜色内
    c[i].push_back(0);
    //对颜色为i的结点排序
    sort(c[i].begin(), c[i].end(), cmp);
    //按dfs序遍历结点

    for (auto & x: c[i])
    {
      //遍历子结点
      cout << "***" << x << endl;
      for (auto & y: G[x])
      {
        if (y == f[x])
        {
          continue;
        }
        int size = s[y];
        int k = L[y];
        //
        while(1)
        {
          L[n + 1] = k;
          //二分找出dfs序比k大的第一个颜色为i的结点
          auto it = lower_bound(c[i].begin(), c[i].end(), n + 1, cmp);
          //找不到或找到后发现这个结点不在y的子树中
          if (it == c[i].end() || L[*it] > R[y])
          {
            break;
          }

          size -= s[*it];
          k = R[*it] + 1;
        }
        cout << (ll) size * (size - 1) /2 << endl;
        //这个子树里被与x颜色相同的点所包围的这个联通块内的路径都是不包括这个颜色的
        res -= (ll) size *(size - 1) / 2;
      }
    }
  }
  printf("Case #%d: %lld\n", ++kase, res);
}
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    work();
  }
  return 0;
}
/*

5
2 2 2 2 1
1 2
2 3
2 5
3 4

*/
