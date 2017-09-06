#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000000 + 10;
int primes[maxn], ptot;
int mu[maxn];
bool nprime[maxn];
void init()
{
  nprime[1] = true;
  mu[1] = 1;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[ptot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < ptot && i * primes[j] < maxn; j++)
    {
      nprime[i * primes[j]] = true;
      if (i % primes[j] == 0)
      {
        mu[i * primes[j]] = 0;
        break;
      }
      mu[i * primes[j]] = -mu[i];
    }
  }
}
ll calc(ll x)
{
  ll ret = 0;
  for (ll i = 1; i * i <= x; i++)
  {
    ret += mu[i] * (x/(i*i));
  }
  return ret;
}
int main()
{
  init();
  int T;
  while(cin >> T)
  {
    ll k, x;
    while(T--)
    {
      cin >> k;
      ll L = 0, R = k * 10;
      while(L + 1 < R)
      {
        const ll mid = L + (R - L + 1) / 2;
        if (calc(mid) < k)
        {
          L = mid;
        }
        else
        {
          R = mid;
        }
      }
      cout << R << endl;
    }
  }
}
