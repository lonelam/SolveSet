#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;
const int maxk = 10 + 5;
int T;
ld raw_mat[maxn][maxn];
ld p[maxn][maxn][maxn];
int k;
int n, m;
int t[maxn];
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        scanf("%llf", &raw_mat[i][j]);
      }
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%d", t + i);
    }
    memset(p, 0, sizeof(p));
    p[0][0][0] = 1;
    for (int i = 1; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        for (int k = 0; k < n; k++)
        {
          for (int s = max(0, j-2); s <= j+2; s++)
          {
            for (int r = max(0, k-2); r <= k+2; r++)
            {
              if (t[s] == t[r])
              {
                p[i][s][r] += p[i-1][j][k] * raw_mat[j][s] * raw_mat[k][r];
              }
            }
          }
        }
      }
    }
    ld Q = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (t[i] == t[j])
        {
          Q += p[m-1][i][j];
        }
      }
    }
    printf("%.10Lf\n", Q);
  }
}
