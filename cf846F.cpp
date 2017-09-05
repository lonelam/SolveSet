#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;
int a[maxn];
int last[maxn];
int n;
ll tot;
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", a + i);
  }
  // memset(last, -1, sizeof(last));
  for (int i = 1; i <= n; i++)
  {
    tot += (ll)(i - last[a[i]]) * (ll)(n - i + 1LL) * 2LL - 1LL;
    last[a[i]] = i;
  }
  ld ans = (ld)tot / (ld)((ld)n * (ld)n);
  printf("%.6Lf\n", ans);
}
