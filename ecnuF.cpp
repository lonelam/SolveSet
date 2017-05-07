#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll n;
int main()
{
  while(scanf("%lld", &n) != EOF)
  {
    ll mask = 5;
    ll ans = 0;
    while(mask <= n)
    {
      ans += n / mask;
      mask *= 5;
    }
    printf("%lld\n", ans);
  }
}
