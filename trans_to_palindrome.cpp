#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxm = 1000 + 5;
int fa[maxn], rnk[maxn];
int fnd(int x)
{
  if (x < 0) return x;
  int fx = fa[x];
  if (fx == x )
  {
    return x;
  }
  return fa[x] = fnd(fx);
}
void join(int lhs, int rhs)
{
  int fl = fnd(lhs), fr = fnd(rhs);
  if (fl == fr)
  {
    return;
  }
  if (rnk[fl] == rnk[fr])
  {
    fa[fr] = fl;
    rnk[fl]++;
    return;
  }

  if (rnk[fl] < rnk[fr])
  {
    fa[fl] = fr;
    return;
  }
  fa[fr] = fl;
  return;
}
int n;
void init()
{
  memset(rnk, 0, sizeof(rnk));
  for (int i = 0; i <= n; i++)
  {
    fa[i] = i;
  }
}
int s[maxm];
int dp[maxm][maxm];
int k, m;
int main()
{
  while(scanf("%d%d%d", &n, &k, &m) != EOF)
  {
    init();
    int x, y;
    while(k--)
    {
      scanf("%d%d", &x, &y);
      join(x, y);
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d", s + i);
    }
    for (int i = 0; i <= m; i++)
    {
      dp[i][i] = 0;
      dp[i][i + 1] = 1;
    }
    for (int len = 2; len <= m; len++)
    {
      for (int i = 0; i + len <= m; i++)
      {
        if (fnd(s[i]) == fnd(s[i + len - 1]))
        {
          dp[i][i + len] = dp[i + 1][i + len - 1] + 2;
        }
        else dp[i][i + len] = max(dp[i][i + len - 1], dp[i+ 1][i + len]);
      }
    }
    int ans = dp[0][m];
    printf("%d\n", ans);
  }
}
