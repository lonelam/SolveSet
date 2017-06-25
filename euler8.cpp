#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
char num[maxn];
int digit[maxn];
int T, n, k;
int main()
{
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d", &n, &k);
      scanf("%s", num);
      for (int i = 0; i < n; i++)
      {
        digit[i] = num[i] - '0';
      }
      int ans = 0;
      for (int i = 0; i + k <= n; i++)
      {
      int prod = 1;
        for (int j = 0; j < k; j++)
        {
          prod *= digit[i + j];
        }
        ans = max(ans, prod);
      }
      printf("%d\n", ans);
    }
  }
}
