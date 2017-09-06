
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int f[maxn][maxn][2], n, x, k;
char g[maxn][maxn][2];
void gao(int x, int y)
{
  if (x == 1 && y == 1) return;
  if (g[x][y][k])
  {
    gao(x-1, y), putchar('D');
  }
  else
  {
    gao(x, y - 1), putchar('R');
  }
}
int main()
{
  scanf("%d", &n);
  memset(f, 0, sizeof(f));
  for (int i = 2; i <= n; i++)
  {
    f[0][i][0] = f[0][i][1] = f[i][0][0] = f[i][0][1] = inf;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &k);
      if (!k)
      {
        x = i;
      }
      else
      {
        while(k % 2 == 0)
        {
          ++f[i][j][0];
          k/=2;
        }
        while(k % 5 == 0)
        {
          ++f[i][j][1];
          k /= 5;
        }
      }
      for (int k = 0; k < 2; k++)
      {
        if ((g[i][j][k] = f[i-1][j][k] < f[i][j-1][k]))
        {
          f[i][j][k] += f[i-1][j][k];
        }
        else
        {
          f[i][j][k] += f[i][j-1][k];
        }
      }
    }
  }
  k = f[n][n][1] < f[n][n][0];
  if (x && f[n][n][k] > 1)
  {
    puts("1");
    for (int i = 2; i <= x; i++)
    {
      putchar('D');
    }
    for (int i = 2; i <= n; i++)
    {
      putchar('R');
    }
    for (int i = x + 1; i <= n; i++)
    {
      putchar('D');
    }
    puts("");
  }
  else
  {
    printf("%d\n", f[n][n][k]);
    gao(n,n);
    puts("");
  }
}
