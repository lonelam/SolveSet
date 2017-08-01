#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
const int maxc = 11;
int a[maxn][maxn][maxc];
int n, m, c, q;
int x,y, s;
int main()
{
  while(scanf("%d%d%d", &n,&q,&c) !=EOF)
  {
    memset(a,0,sizeof(a));
    c++;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &x,&y,&s);
      for (int j = 0; j < c; j++)
      {
        a[x][y][j] += (s + j) % c;
      }
    }
    for (int j = 0; j < c; j++)
    {
      for (int x = 1; x <= 100; x++)
      {
        for (int y = 1; y <= 100; y++)
        {
          a[x][y][j] += a[x-1][y][j] + a[x][y-1][j] - a[x-1][y-1][j];
        }
      }
    }
    for (int i = 0; i < q; i++)
    {
      int x1,y1,x2,y2, t;
      scanf("%d%d%d%d%d", &t, &x1,&y1,&x2,&y2);
      int ans = a[x2][y2][t%c] - a[x2][y1-1][t%c] - a[x1-1][y2][t%c] + a[x1-1][y1-1][t%c];
      printf("%d\n", ans);
    }
  }
}
