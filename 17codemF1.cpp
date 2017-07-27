#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 50;
ld dp[maxn];
int main()
{
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i < maxn; i++)
  {
    ld apos, bpos;
    if (i > 50)
    {
      apos = 0;
      bpos = 1;
    }
    else
    {
      apos = (ld)(i+1LL) / (ld)(1LL << i);
      bpos = 1 - apos;
    }
    dp[i] = apos * i + bpos * dp[i - 2];
  }
  int n;
  while(scanf("%d", &n)!= EOF)
  {
    printf("%llf\n", dp[n]);
  }
}
