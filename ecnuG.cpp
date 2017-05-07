#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 +100;

int n;

int a[maxn];
int disc[maxn];
int cnt[maxn];
inline int lsb(int x)
{
  return x & ( - x);
}
void add(int x)
{
  while(x <= n)
  {
    cnt[x]++;
    x += lsb(x);
  }
}
int query(int x)
{
  int ret = 0;
  while(x)
  {
    ret += cnt[x];
    x -= lsb(x);
  }
  return ret;
}
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    memset(cnt, 0, sizeof(cnt));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
      disc[i] = a[i];
    }
    sort(disc, disc + n);
    for (int i = 0; i < n; i++)
    {
      a[i] = lower_bound(disc, disc + n, a[i]) - disc + 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
      ans += query(a[i] - 1);
      add(a[i]);
    }
    printf("%lld", ans);
  }
}
