#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int deg[maxn];
int main()
{
  // freopen("data.in", "w", stdout);
  int n = 24;
  // int m = 0;
// 12500
  printf("%d %d\n", 109, 491);
  int p = 2 * n + 1;
  for (int i = 1; i <= n; i++)
  {
    printf("%d %d\n", i, i + n);
    deg[i] = 1;
    // m++;
  }
    for (int j = 2; j <= n; j++)
    {
      for (int k = 1; k <= n / j; k++)
      {
        p++;
        int s = j;
        // cout << p << " :"<< j << endl;
        for (int o = 1; o <= n && s; o++)
        {
          if (deg[o] < j)
          {
            deg[o]++;
            s--;
            printf("%d %d\n", p, o);
            // m++;
          }
        }
        assert(!s);
      }
    }
  printf("%d\n", n);
  for (int i = 1; i <= n; i++)
  {
    printf("%d\n", i);
  }
  // cout << m << endl;
  // cout << p << endl;

  // cout << m << endl;
}
