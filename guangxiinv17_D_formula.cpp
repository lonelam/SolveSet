
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
  ll a[4][4];
  mat(){memset(a,0,sizeof(a));}
  void init()
  {
    for (int i = 0; i < 4; i++)
    {
      a[i][i] = 1;
    }
  }
  mat operator*(const mat & rhs) const
  {
    mat ret;
    for (int k = 0; k < 4; k++)
    {
      for (int i = 0; i < 4; i++)
      {
        for (int j = 0; j < 4; j++)
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
ll table[5] = {1, 1, 5, 11, 36};
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
  base.a[0][0] = base.a[0][2] = base.a[1][0] = base.a[2][1] = base.a[3][2] = 1;
  base.a[0][1] = 5;
  base.a[0][3] = moder-1;
  ll n;
  while(~scanf("%lld", &n))
  {
    if (n <= 4)
    {
      printf("%lld\n", table[n]);
      continue;
    }
    mat ans = p_m(base, n - 4);
    printf("%lld\n", (ans.a[0][3] * 1 + ans.a[0][2] * 5 + ans.a[0][1] * 11 + ans.a[0][0] * 36)% moder);
  }
}
