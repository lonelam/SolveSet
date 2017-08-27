
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long U;
const int inf = 0x3f3f3f3f;
const int maxn = 45;
int n, k, x, i, j, ans;
bool flag;
double res;
U g[maxn];
inline int ctz(U s)
{
  return s ? __builtin_ctzll(s): 64;
}
void BornKerbosch(U cur, U allow, U forbid)
{
  if (!allow && !forbid)
  {
    ans = max(ans, __builtin_popcountll(cur));
    return;
  }
  if (!allow) return;
  int pivot = ctz(allow);
  U z = allow & ~g[pivot];
  for (int u = ctz(z); u < n; u += ctz(z>>(u + 1)) + 1)
  {
    BornKerbosch(cur | (1ULL << u), allow & g[u], forbid & g[u]);
    allow ^= 1ULL << u, forbid |= 1ULL << u;
  }
}
int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    g[i] = (1ULL << n) - 1 - (1ULL << i);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &x);
      if (!x && i != j)
      {
        g[i] ^= 1ULL << j;
      }
    }
  }
  BornKerbosch(0, (1ULL << n) - 1, 0);
  if (ans > 1) res = 1.0 * (ans - 1) / 2.0 / ans;
  printf("%.10f", res * k * k);
}
