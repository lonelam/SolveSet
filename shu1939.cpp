#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int T;
ll n, m, k;
ll inv_fact[maxn];
int main()
{
  while(cin >> T)
  {
    while(T--)
    {
      cin >> n >> m >> k;
      inv_fact[n] = 1;
      for (ll i = 2; i <= n; i++)
      {
        inv_fact[n] *= n;
        inv_fact[n] %= k;
      }

    }
  }
}
