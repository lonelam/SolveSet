#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
bool nprime[maxn];
int primes[maxn], tot = 1;
void init()
{
  nprime[1] = true;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    for (int j = i + i; j < maxn; j+= i)
    {
      nprime[j] = true;
    }
  }
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[tot++] = i;
    }
  }
}
int main()
{
  init();
  int n;
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      printf("%d\n", primes[n]);
    }
  }
}
