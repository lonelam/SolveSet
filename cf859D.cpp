#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
double win[maxn][maxn], e[maxn][maxn], prob[maxn][maxn];
int pp, n, m;
void dfs(int p, int l, int r)
{
  if (l + 1 == r) win[p][1] = 1, e[p][1] = 0;
  else
  {
    int md = (l + r) >> 1;
    dfs(p + p, 1, md);
    dfs(p + p + 1, md, r);
    for (int i = 1; i <= md; i++)
    {
      for (int j = md; j <= r; j++)
      {
        win[p][i] += win[p+p][i] * win[p+p+1][j] * prob[1][j];
      }
    }
    for (int i = 1; i <= md; i++)
    {
      for (int j = md; j <= r; j++)
      {
        e[p][i] = max(e[p][i], win[p][i]*(r-l)/2 + e[p+p][i] + e[p + p + 1][j]);
      }
    }
    for (int i = 1; i <= md; i++)
    {
      for (int j = 1; j <= md; j++)
      {
        win[p+p+1][i] += win[p+p+1][i] * win[p+p][j] * prob[i][j];
      }
    }
  }
}
