#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 5000000 + 100;

bool nprime[maxn];
void init()
{
  nprime[1] = true;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      for (int j = i + i; j < maxn; j+= i)
      {
        nprime[j] = true;
      }
    }
  }
}
bool isprime(ll x)
{
  for (ll i = 2; i * i <= x; i++)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int T;
  init();
  while(cin >> T)
  {
    ll n;
    while(T--)
    {
      cin >> n;
      ll ans = 0;
      for (ll i = 1; i * i <= n; i++)
      {
        if (n % i) continue;
        if (!nprime[i])
        {
          ans = max(ans, i);
        }
        if (isprime(n / i))
        {
          ans = max(ans, n / i);
        }
      }
      cout << ans << endl;
    }
  }
}
