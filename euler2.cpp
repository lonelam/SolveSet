#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll sum[maxn];
ll disc[maxn];
ll fib[maxn];
int tot;
void init()
{
  disc[0] = 0;
  sum[0] = 0;
  tot = 1;
  ll pre = 2;
  ll cur = 1;
  for (; pre <=(ll) 4e16;)
  {
    if (!(pre & 1))
    {
      disc[tot] = pre;
      sum[tot] = sum[tot - 1] + pre;
      tot++;
    }
    cur = pre + cur;
    swap(cur, pre);
  }
}
int main()
{
  int T;
  scanf("%d", &T);
  init();
  while(T--)
  {
    ll N;
    scanf("%lld", &N);
    printf("%lld\n", sum[upper_bound(disc, disc + tot, N) - disc - 1]);
  }
}
