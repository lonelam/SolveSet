#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
bool nprime[maxn];
int primes[maxn];
ll presum[maxn];
int ptot = 0;
void init()
{
  nprime[1] = true;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[ptot++] = i;
    }
      for (int j = 0; j < ptot && i * primes[j] < maxn; j++)
      {
        nprime[i * primes[j]] = true;
        if (i % primes[j] == 0)
        {
          break;
        }
      }
  }
  presum[0] = primes[0];
  for (int i = 1; i < ptot; i++)
  {
    presum[i] = presum[i- 1] + primes[i];
  }
}
int main()
{
  int T, n;
  init();
//  for (int i = 0; i < 100; i++) cout << primes[i] << endl;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      int tar = upper_bound(primes, primes + ptot, n) - primes;
      tar--;
      printf("%lld\n", presum[tar]);
    }
  }
}
