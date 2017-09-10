#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll moder = 998244353;
struct mat
{
  ll a[2][2];
  mat(){memset(a,0,sizeof a);}
  void init()
  {
    a[0][0] = a[1][1] = 1;
  }
  mat operator*(const mat & rhs) const
  {
    mat ret;
    for (int k = 0; k < 2; k++)
    {
      for (int i =  0; i < 2; i++)
      {
        for (int j = 0; j < 2; j++)
        {
          ret.a[i][j] += a[i][k] * rhs.a[k][j] % moder;
          ret.a[i][j] %= moder;
        }
      }
    }
    return ret;
  }
};
mat p_m(mat base, ll index)
{
  mat ret;
  ret.init();
  while(index)
  {
    if (index & 1)
    {
      ret = ret * base;
    }
    index >>= 1;
    base = base * base;
  }
  return ret;
}
int main()
{
  mat base;
  base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
  ll n;
  while(~scanf("%lld", &n))
  {
    n++;
    mat ans = p_m(base, 2LL * n);
    ll Fib = (ans.a[0][0] + moder - 1) % moder;
    printf("%lld\n", Fib);
  }
}
