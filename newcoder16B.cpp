#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n;
int A[maxn];
int main()
{
  while(~scanf("%d", &n))
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%d",  A + i);
    }
    ll vmx = -1LL-A[1] * (ll)A[1];
    ll vmA = A[1];
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
      if (-i * (ll)i  - A[i] * (ll)A[i] >= vmx)
      {
        vmx = -i * (ll)i - A[i] * (ll) A[i];
        vmA = A[i];
      }
      if (A[i] >= vmA)
      {
        ans = max(ans, i * (ll) i + A[i] * (ll)A[i] + vmx);
      }
    }
    vmx = -1LL + A[1] * (ll) A[1];
    vmA = A[1];
    for (int i = 1; i <= n; i++)
    {
      if (-i * (ll)i  + A[i] * (ll)A[i] > vmx)
      {
        vmx = -i * (ll)i + A[i] * (ll) A[i];
        vmA = A[i];
      }
      if (A[i] <= vmA)
      {
        ans = max(ans, i * (ll) i - A[i] * (ll)A[i] + vmx);
      }
    }
    printf("%lld\n", ans);

  }
}
