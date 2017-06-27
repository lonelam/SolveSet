#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
char num[maxn];
int n;
int cnt(ll x)
{
  int ret = 0;
  while(x)
  {
    x /= 10;
    ret++;
  }
  return ret;
}
int main()
{
  scanf("%d", &n);
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ll raw;
    scanf("%s", num);
    num[14] = '\0';
    sscanf(num, "%lld", &raw);
    ans += raw;
  }
  while(cnt(ans) > 10)
  {
    ans /= 10;
  }
  printf("%lld\n",ans);
}
