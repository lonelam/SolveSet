#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
int n, t;
int d[2002], s[2002];
const ld eps = 1e-10;
ld calc(ld c)
{
  ld ct = 0;
  for (int i = 0; i < n; i++)
  {
    ld spd = s[i] + c;
    if (spd <= eps)
    {
      return t + 1;
    }
    ct += d[i] / spd;
  }
  return ct;
}
int main()
{

  while(scanf("%d%d", &n, &t) != EOF)
  {
    ld L = 0, R = 1e10;
    for (int i = 0; i < n;i ++)
    {
      scanf("%d%d", d + i, s + i);
    }
    L = -s[0] * 1.0L;
    for (int i = 0; i < n; i++)
    {
      L = min(L, -(ld)s[i]);
    }
    for (int k = 0; k < 500; k++)
    {
      const ld mid = L + (R - L) / 2.0;
      if (calc(mid) >= (ld)t)
      {
        L = mid;
      }
      else
      {
        R = mid;
      }
    }
    printf("%llf\n", L);
//    cout << L << endl;
  }
}
/*

4 10
5 3
2 2
3 6
3 1

3 3
1000 -1
1 -1
1 -1000


*/
