#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
bool dp[maxn];
int f[maxn];
int a, b, h, w, n;
int main()
{
  while(scanf("%d%d%d%d%d",&a, &b, &h, &w, &n) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", f + i);
    }
    if (a <= h && b <= w || a <= w && b <= h)
    {
      printf("0\n");
      continue;
    }
    sort(f, f + n);
    reverse(f, f + n);
    int ha = (a + h - 1)/ h;
    int hb = (b + h - 1)/ h;
    int ans = -1;
    ll tot = 1;
    memset(dp, 0, sizeof(dp));
    dp[1] = true;
    for (int i = 0; i < n && ans == -1; i++)
    {
      for (int j = maxn - 1; j >= f[i]; j--)
      {
        if (j % f[i] == 0 && dp[j / f[i]])
        {
          dp[j] = true;
        }
      }
      tot *= f[i];
      int upa = -1;
      for (int j = ha; j < maxn; j++)
      {
        if (dp[j])
        {
          upa = j;
          break;
        }
      }
      if (upa !=  -1)
      {
        ll ta = tot / upa;
        if (w * ta >= (ll)b)
        {
          ans = i + 1;
          break;
        }
      }
      int upb = -1;
      for (int j = hb; j < maxn; j++)
      {
        if (dp[j])
        {
          upb = j;
          break;
        }
      }
      if (upb != -1)
      {
        ll tb = tot / upb;
        if (w * tb >= (ll)a)
        {
          ans = i + 1;
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
}
