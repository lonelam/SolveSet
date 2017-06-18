#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
int n;
ld c[maxn], d[maxn];
ld u, v;
int main()
{
  while(scanf("%d%llf%llf", &n, &v, &u) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%llf", c + i);
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%llf", d + i);
    }
    ld ans = 0;
    for (int i = 0; i < n; i++)
    {
      ld tmp = 0;
      for (int j = 0; j < n; j++)
      {
        tmp += (u * n) / (c[i] - j * d[i] - v);
      }
      ans += tmp / n;
    }
    printf("%.3llf\n", ans);
  }
}
/*

10 37.618 0.422
72.865 126.767 202.680 106.102 99.516 134.418 167.952 173.646 120.210 136.571
2.941 3.664 7.363 4.161 0.246 8.046 5.521 7.473 7.178 5.649

*/
