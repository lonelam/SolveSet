#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll n;
bool check(ll k)
{
  ll base = k;
  ll ans = 1;
  while(k)
  {
    if (k & 1)
    {
      ans *= base;
      if (ans > n)
      {
        return false;
      }
    }
    base *= base;
    k >>= 1;
  }
  return true;
}
int main()
{
  long long N;
  while(cin >> N)
  {
    n = N;
    long long cnt = 0;
    for (long long i = 1; i <= N; i++)
    {
      if(check(i))
      {
        cnt++;
      }
      else
      {
        break;
      }
    }
    cout << cnt << endl;
  }
}
