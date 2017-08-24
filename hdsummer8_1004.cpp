#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll n, L;
ll d[maxn];
ll v[maxn];
struct seg1
{
  int mmax[maxn << 2];
  int mmin[maxn << 2];
  bool cmp(int x, int y)
  {
    return d[x] * v[y] < d[y] * v[x];
  }
}
int mmax[maxn << 2];
int mmin[maxn << 2];
bool cmp(int x, int y)
{
  d[x]*
}
void pushup(int x)
{
  mmax[x] = max(mmax[x << 1], mmax[x << 1 | 1]);
  mmin[x] = min(mmin[x << 1], mmin[x << 1 | 1]);
}
void build(int L = 0, int R = n, int o = 1)
{
  if (L + 1 == R)
  {
    mmax[o] = mmin[o] = 0;
    return;
  }
}
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d", &n, &L);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", d + i);
      }
      for (int i = 0; i < n; i++)
      {
        scanf("%d", v + i);
      }
      for (int i = 0; i + 1 < n; i++)
      {
        v[i] -= v[n-1];
      }
      v[n-1] = 0;
      for (int i = 0; i + 1 < n; i++)
      {
        d[i] = (L + d[i] - d[n-1]) % L;
      }
      d[n-1] = 0;
    }
  }
}
