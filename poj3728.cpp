#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;
const int maxk = 20;
int price[maxn];
vector<int> G[maxn];
int dpup[maxn];
int dpdown[maxn];
int fa[maxk][maxn];
void dfs(int cur, int p)
{
  fa[0][cur] = p;
  for (int k = 1; k < maxk; k++)
  {
    fa[k][cur] = fa[k-1][fa[k-1][cur]];
  }
  dpup[cur] = dpup[p];
  dpdown[cur] = dpdown[cur];
  if (price[cur] > price[p])
  {
    dpdown[cur] += price[cur] - price[p];
  }
  else
  {
    dpup[cur] += price[p] - price[cur];
  }
  for (int i = 0; i < G[cur].size(); i++)
  {
    int v = G[cur][i];
    if (v != p)
    {
      dfs(v, cur);
    }
  }
}
