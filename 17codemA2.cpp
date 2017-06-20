
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 55;
char a[maxn];
char b[maxn];
int n, m;
bool valid[maxn][maxn][maxn][maxn];

int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%s", a);
      scanf("%s", b);
      n = strlen(a);
      m = strlen(b);
      memset(valid, 0, sizeof(valid));
      int ans = 1;
      for (int i = 0; i <= n; i++)
      {
        for (int j = 0; j <= m; j++)
        {
          valid[i][i + 1][j][j] = true;
          valid[i][i][j][j + 1] = true;
          valid[i][i][j][j] = true;
        }
      }
      for (int alen = 1; alen <= n; alen++)
      {
        for (int i = 0; i + alen <= n; i++)
        {
          for (int blen = 1; blen <= m; blen++)
          {
            for (int j = 0; j + blen <= m; j++)
            {
              if (alen > 1 && a[i] == a[i + alen - 1] && valid[i + 1][i + alen - 1][j][j + blen])
              {
                valid[i][i + alen][j][j + blen] = true;
              }
              else if (a[i] == b[j + blen - 1] && valid[i + 1][i + alen][j][j + blen - 1])
              {
                valid[i][i + alen][j][j + blen] = true;
              }
              else if (a[i + alen - 1] == b[j] && valid[i][i + alen - 1][j][j + blen])
            }
          }
        }
      }
      printf("%d\n", ans);
    }
  }
}
