
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000010;
const ll moder = 998244353LL;
ll PrimeList[maxn];
int PrimeNum;
bool nprime[maxn];
void init()
{
  nprime[1] = true;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      PrimeList[PrimeNum++] = i;
    }
    for (int j = 0; PrimeList[j] * i < maxn && j < PrimeNum; j++)
    {
      nprime[PrimeList[j] * i] = true;;
      if (i % PrimeList[j] == 0)
      {
        break;
      }
    }
  }
}
bool IsNotPrime[maxn]; // IsNotPrime[i] = 1表示i + L这个数是素数.
ll ans[maxn];
ll tmp[maxn];
ll k;
int d;

void SegmentPrime(ll L, ll U)
{ // 求区间[L, U]中的素数.
     ll i, j;
     ll SU = sqrt((ld)U);
      d = U - L + 1;
     for (i = 0; i < d; i++)
     {
       IsNotPrime[i] = false; // 一开始全是素数.
       tmp[i] = i + L;
       ans[i] = 1LL;
     }
     for (i = (L % 2 != 0); i < d; i += 2)
     {
       IsNotPrime[i] = 1; // 把偶数的直接去掉.
       ll cnt = 0;
       while(tmp[i] % 2LL == 0LL)
       {
         tmp[i] /= 2LL;
         cnt++;
       }
       ans[i] = (ans[i] * (k * cnt+1LL)) % moder;
     }
     for (int ss = 1; PrimeList[ss] <= SU; ss++)
    //  for (i = 3LL; i <= SU; i += 2LL)
     {
       i = PrimeList[ss];
           if (i > L && IsNotPrime[i - L]) continue; // IsNotPrime[i - L] == 1说明i不是素数.
           j = (L/ i) * i; // j为i的倍数，且最接近L的数.
           if (j < L) j += i;
           if (j == i) j += i; // i为素数，j = i说明j也是素数，所以直接 + i.
          j = j - L;
          for (; j < d; j += i)
          {
            IsNotPrime[j] = true; // 说明j不是素数(IsNotPrime[j - L] = 1).
            ll cnt = 0;
            while(tmp[j] % i == 0LL)
            {
              tmp[j] /= i;
              cnt++;
            }
            ans[j] = ((ll) ans[j] * (k * cnt + 1LL)) % moder;
          }
     }
    //  if (L <= 1) IsNotPrime[1 - L] = 1;
    //  if (L <= 2) IsNotPrime[2 - L] = 0;
    //  PrimeNum = 0;
     for (i = 0; i < d; i++)
     {
      //  if (!IsNotPrime[i]) PrimeList[PrimeNum++] = i + L;
       if (tmp[i] != 1)
       {
         ans[i] = ((ll) ans[i] * (k + 1LL)) % moder;
       }
     }
}
int main()
{
  int T;
init();
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      ll acc = 0;
      ll l, r;
      scanf("%lld%lld%lld", &l, &r, &k);
      //  k %=  moder;
      SegmentPrime(l, r);
      for (int i = 0; i < d; i++)
      {
        acc += ans[i];
        acc %= moder;
      }
      printf("%lld\n", acc);
    }
  }
}
/*
10
100000000000 100000500000 500000
90000000000 90001000000 500000
90000000000 90001000000 500000
90000000000 90001000000 500000
90000000000 90001000000 500000
90000000000 90001000000 500000
90000000000 90001000000 500000
90000000000 90001000000 500000
90000000000 90001000000 500000
90000000000 90001000000 500000
*/
