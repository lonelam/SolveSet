#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n;
int x[maxn], y[maxn];
int main()
{
  while(~scanf("%d", &n))
  {
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", x + i, y + i);
      if (x[i] > 0)
      {
        cnt[0]++;
      }
      else
      {
        cnt[1]++;
      }
    }
    if (cnt[0] <= 1 || cnt[1] <= 1)
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
  }
}
