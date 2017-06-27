
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;
int ptot;
bool nprime[maxn];
int primes[maxn];
void init()
{
  nprime[1] = true;
  for (int i = 2;i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[ptot++] = i;
    }
    for (int j = 0; j < ptot && primes[j] * i < maxn; j++)
    {
      nprime[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}
int count(ll x)
{
  ll ret = 1;
  for (int j = 0; primes[j] * primes[j] <= x; j++)
  {
    int cnt = 1;
    while(x % primes[j] == 0)
    {
      cnt++;
      x/= primes[j];
    }
    ret *= cnt;
  }
  if (x != 1) ret *= 2;
  return ret;
}
int ans[maxn];
int disc[maxn];
int main()
{
  init();
  ll dn = 1;
  ll up = 2;
  int mx = 0;
  int tot = 0;
  for (int i = 0; i < 50000; i++)
  {
    int cnt = count(dn);
    if (cnt > mx)
    {
      disc[tot] = cnt;
      mx = cnt;
      ans[tot++] = dn;
    }
    dn += up++;
  }
  //cout << "done"<< endl;
  int T;
  cin >> T;
  int n;
  while(T--)
  {
    cin >> n;
    int p = upper_bound(disc, disc + tot, n) - disc;
    cout << ans[p] << endl;
  }
}
