#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll moder = 1e9 + 7;
int n;
int a[maxn];
vector<int> G[maxn];
ll f[maxn][2];
int s[maxn];
void add(int a, int b)
{
  G[a].push_back(b);
  G[b].push_back(a);
}
void solve(int p, int fa)
{
  s[p] = a[p];
  for (int q: G[p])
  {
    if (q == fa) continue;
    solve(q, p);
    s[p] |= s[q];
  }
  f[p][0] = f[p][1] = 0;
  if (s[p] == 0)
  {
    f[p][0] = 1;
    return;
  }
  ll t0 = 1, t1 = 0;
  for (int q: G[p])
  {
    if (q == fa) continue;
    if (s[q] == 0) continue;
    ll g0 = (t0 * (f[q][0] + f[q][1])) % moder;
    ll g1 = ((t1 * (f[q][0] + f[q][1])) + t0 * f[q][1] )% moder;
    t0 = g0;
    t1 = g1;
  }
  if (a[p] == 0)
  {
    f[p][0] = t0;
    f[p][1] = t1;
  }
  else
  {
    f[p][0] = 0;
    f[p][1] = t0;
  }
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++)
  {
    int p;
    scanf("%d", &p) ;
    add(p, i + 1);
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a + i);
  }
  int sa = 0;
  for (int i = 0; i < n; i++)
  {
    sa += a[i];
  }
  if (sa == 0)
  {
    printf("0\n");
    return 0;
  }
  solve(0, -1);
  printf("%lld\n", f[0][1]);
  return 0;
}
