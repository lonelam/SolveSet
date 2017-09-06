#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll moder = 1e9 + 7;
struct mat
{
  ll a[16][16];
  mat(){memset(a,0,sizeof(a));}
  void init()
  {
    for (int i = 0; i < 16; i++)
    {
      a[i][i] = 1;
    }
  }
  mat operator*(const mat & rhs) const
  {
    mat ret;
    for (int k = 0; k < 16; k++)
    {
      for (int i = 0; i < 16; i++)
      {
        for (int j = 0; j < 16; j++)
        {
          ret.a[i][j] = (ret.a[i][j] + a[i][k] * rhs.a[k][j]) % moder;
        }
      }
    }
    return ret;
  }
}base;
void dfs(int init, int cur, int nex)
{
  if (cur == 15)
  {
    base.a[init][nex]++;
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    if (!(cur >> i & 1))
    {
      dfs(init, cur | (1 << i), nex | (1 << i));
      if (i < 3 && !(cur >> (i+1) & 1))
      {
        dfs(init, cur | (1 << i) | (1 << (i + 1)), nex);
      }
      break;
    }
  }
  return;
}
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
  for (int i = 0; i < 16; i++)
  {
    dfs(i, i, 0);
  }
  ll n;
  while(~scanf("%lld", &n))
  {
    mat ans = p_m(base, n);
    printf("%lld\n", ans.a[0][0]);
  }
}
