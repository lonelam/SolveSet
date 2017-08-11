#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
const int maxg = maxn * maxn;
pair<int,int> head[maxg];
pair<int,int> pre[maxn][maxn];
int G[maxn][maxn];
int n, m;
ll sum;
int main()
{
  int T;
  freopen("C:\\hdsummer_data\\r2\\data\\1008.in","r",stdin);
  scanf("%d", &T);
  while(T-- && scanf("%d%d", &n, &m) != EOF)
  {
    sum = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        scanf("%d", G[i] + j);
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int lone = -1, rone = m;
        for (int s = j - 1; s > lone; s--)
        {
          if (G[i][s] == G[i][j])
          {
            lone = s;
            break;
          }
        }
        sum += (ll)(j - lone) * (rone - j) * (n - i);
        for (int k = i - 1; k >= 0; k--)
        {
          for (int s = j; s < rone; s++)
          {
            if (G[k][s] == G[i][j])
            {
              rone = s;
              break;
            }
          }
          for (int s = j; s > lone; s--)
          {
            if (G[k][s] == G[i][j])
            {
              lone = s;
              break;
            }
          }
          sum += (ll)(j - lone) * (rone - j) * (n - i);
        }
      }
    }
    printf("%.9Lf\n", ((ld)sum / ((ld)((n *n + n)/2) * (ld)((m * m + m) / 2))));
  }
}
