#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000;
const ll moder = 1e9 + 7;
struct mat
{
  ll a[2][2];
  mat(){memset(a,0,sizeof(a));}
  mat operator*(mat & rhs)
  {
    mat ret;
    for (int k = 0; k < 2; k++)
    {
      for (int i = 0; i < 2; i++)
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
ll N, M;
mat p_m(mat base, ll index)
{
  mat ret;
  ret.a[0][0] = ret.a[1][1] = 1;
  while(index)
  {
    if (index & 1)
    {
      ret =ret * base;
    }
    index >>= 1;
    base = base * base;
  }
  return ret;
}
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%lld%lld", &N, &M);
      mat A;
      A.a[0][0] = A.a[1][0] = 1;
      A.a[0][1] = 2;
      mat B = p_m(A, N);
      if (N & 1)
      {
        B.a[0][1] += moder - 2;
        B.a[0][1] %= moder;
        B.a[1][1] += 1;
        B.a[1][1] %= moder;
        B.a[1][0] += moder - 1;
        B.a[1][0] %= moder;
      }
      else
      {
        B.a[0][0] += moder - 1;
        B.a[0][0] %= moder;
        B.a[1][1] += moder - 1;
        B.a[1][1] %= moder;
      }
      mat ans = p_m(B, M -  1);
      printf("%lld\n", (ans.a[1][0] + ans.a[1][1])% moder);
    }
  }
}
