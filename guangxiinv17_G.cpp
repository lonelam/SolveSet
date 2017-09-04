#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int cnt[maxn];
int main()
{
  int n;
  while(~scanf("%d", &n))
  {
    memset(cnt,0,sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
      int a;
      scanf("%d", &a);
      cnt[a]++;
    }
    int ans = 0;
    int pre = 0;
    for (int i = 0; i < maxn; i++)
    {
      if (cnt[i] && pre == 2)
      {
        cnt[i]--;
        cnt[i-1]--;
        cnt[i-2]--;
        pre = 0;
        ans++;
      }
      if (cnt[i] & 1)
      {
        pre++;
      }
      else
      {
        pre = 0;
      }
    }
    for (int i = 0; i < maxn; i++)
    {
      if (cnt[i] && pre == 2)
      {
        cnt[i]--;
        cnt[i-1]--;
        cnt[i-2]--;
        pre = 0;
        ans++;
      }
      if (cnt[i] & 1)
      {
        pre++;
      }
      else
      {
        pre = 0;
      }
    }
    for (int i = 0; i < maxn; i++)
    {
      ans += cnt[i] / 2;
    }
    printf("%d\n", ans);
  }
}
