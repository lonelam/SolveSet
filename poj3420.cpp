#include<cstdio>
#include<cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxw = 4;
const int maxs = 1 << maxw;
typedef long long ll;
int w = 4;
int n, m;
struct mat
{
  ll a[maxs][maxs];
  mat(){memset(a,0,sizeof(a));}
  void init()
  {
    memset(a,0,sizeof(a));
    for (int i = 0; i < maxs; i++) a[i][i] = 1;
  }
  mat operator*(const mat & rhs) const
  {
    mat ret;
    for (int k = 0; k < maxs; k++)
    {
      for (int i = 0; i < maxs; i++)
      {
        for (int j = 0; j < maxs; j++)
        {
          ret.a[i][j] = (ret.a[i][j] + a[i][k] * rhs.a[k][j])%m;
        }
      }
    }
    return ret;
  }
};
bool occ[2][4];
mat raw;
void dfs(int S, int cur)
{
  if (cur == 4)
  {
    int T = 0;
    for (int i = 0; i < maxw; i++)
    {
      if (occ[1][i])
      {
        T |= 1 << i;
      }
    }
    raw.a[S][T] += 1;
    return;
  }
  if (occ[0][cur])
  {
    dfs(S, cur + 1);
    return;
  }
  if (cur < maxw - 1 && !occ[0][cur+1])
  {
    occ[0][cur] = occ[0][cur+1] = true;
    dfs(S, cur+1);
    occ[0][cur] = occ[0][cur+1] = false;
  }
  occ[0][cur] = occ[1][cur] = true;
  dfs(S, cur+1);
  occ[0][cur] = occ[1][cur] = false;
}
mat pow_m(mat base, int index)
{
  mat ans;
  ans.init();
  while(index)
  {
    if (index & 1)
    {
      ans = ans * base;
    }
    base = base * base;
    index >>=1;
  }
  return ans;
}
int main()
{
  for (int st = 0; st < maxs; st++)
  {
    memset(occ, 0, sizeof(occ));
    for (int i = 0; i < maxw; i++)
    {
      if (st >> i & 1)
      {
        occ[0][i] = true;
      }
    }
    dfs(st, 0);
  }
  while(scanf("%d%d", &n,&m) !=EOF &&n&&m)
  {
    mat ans = pow_m(raw, n);
    printf("%lld\n", ans.a[0][0]);
  }
}
