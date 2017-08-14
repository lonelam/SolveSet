#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;
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
        mu[i * primes[j]] = -mu[i];
        break;
      }
    }
  }
}
