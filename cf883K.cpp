#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
int n;
int a[maxn];
int s[maxn];
int g[maxn];
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", s + i, g + i);
    a[i] = s[i] + g[i];
  }
  for (int i = 0; i < n - 1; i++)
  {
    a[i+1] = min(a[i+1], a[i]+1);
  }
  for (int i = n-1; i > 0; i--)
  {
    a[i-1] = min(a[i-1], a[i]+ 1);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] < s[i])
    {
      printf("-1\n");
      return 0;
    }
    ans += a[i] - s[i];
  }
  printf("%lld\n", ans);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  
}
