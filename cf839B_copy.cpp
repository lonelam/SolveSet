
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n, m, c[9], i, j, x, a[11111];
int main()
{
  scanf("%d%d", &n, &m);
  c[2] = n * 2;
  c[4] = n;
  for (int i = 1; i <= m; i++)
  {
    scanf("%d", &x);
    a[x]++;
  }
  for (int i = 10000; i; i--)
  {
    while(a[i]--)
    {
      for (j = 4; j ; j--)
      {
        if (c[j])
        {
          c[j]--;
          int t = min(i, j);
          a[i - t]++;
          if (j - t - 1> 0) c[j - t - 1]++;
          break;
        }
      }
      if (!j)
      {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
}
