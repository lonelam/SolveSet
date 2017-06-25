#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
bool access[maxn][maxn];
int hi[2][maxn];
int ti[maxn][maxn];
int ci[maxn];
ld dp[2][maxn][500];
int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d%d", ci + i, hi[0] + i, hi[1] + i);
  //  hi[i] += hh;
  }
  for (int i = 0; i < m; i++)
  {
    int x,y,t;
    scanf("%d%d%d",  &x, &y, &t);
    x--;y--;
    access[x][y] = access[y][x] = true;
    ti[x][y] = ti[y][x] = t;
  }
  for (int p = 0; p < 2; p++)
  for (int j = 0; j <= k; j++)
  {
    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int s = 0; s < n; s++)
      {
        if (access[i][s] && ti[i][s] + ci[s] <= j)
        {
          cnt++;
          dp[p][i][j] += dp[p][s][j - ti[i][s] - ci[s]] + (ld)hi[p][s];
        }
      }
      if (cnt) dp[p][i][j] /= (ld)cnt;
      //cout << dp[p][i][j] << endl;
    }
  }
  ld ans[2] = {0,0};
  for (int p = 0; p < 2; p++)
  {
    for (int i = 0; i < n; i++)
    {
      if (k >= ci[i])
      {
        ans[p] += (ld)hi[p][i];
        ans[p] += dp[p][i][k - ci[i]];
      }
    }
    ans[p] /= ld(n);
  }
    printf("%.5llf %.5llf\n", ans[0], ans[1]);
}
