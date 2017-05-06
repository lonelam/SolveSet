#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;
int a[20];
int color[maxn];
int main()
{
  int T, n;
  int kase = 1;
  while(scanf("%d",&T)!=EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      int tot = 0;
      for (int i = 0; i < n; i++)
      {
        scanf("%d", a + i);
        tot += a[i];
      }
      sort(a, a + n);
      reverse(a, a + n);
      int ans = 0;
      int tar = tot / 2;
      if (a[0]  - tar <= (tar + 1) / 2)
      {
        ans = tar;
      }
      else
      {
        ans = ((tot - a[0]) * 2 + 1);
      }
      printf("Case #%d: %d\n", kase++, ans);
    }
  }
}
