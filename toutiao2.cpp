#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
typedef pair<int,int> pii;
int n;
int a[maxn];
int c[maxn];
int inline lsb(int x)
{
  return x & (-x);
}
void add(int x, int tar)
{
  while(x <= n)
  {
    c[x] += tar;
    x += lsb(x);
  }
}
int query(int x)
{
  int ret = 0;
  while(x)
  {
    ret += c[x];
    x -= lsb(x);
  }
  return ret;
}
int main()
{
  vector<pii> ms;
  scanf(
    "%d", &n
  );
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a + i);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    while(!ms.empty() && ms.back().first >= a[i])
    {
      ms.pop_back();
    }
    ms.push_back({a[i], i + 1});
    add(i + 1, a[i]);
    for (pii xx: ms)
    {
      ans = max(ans, (query(n) - query(xx.second)) * (ll)xx.first);
    }
  }
  printf("%lld\n", ans);
}
