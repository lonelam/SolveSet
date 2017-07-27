#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 80000 + 100;
char a[maxn], b[maxn];
int main()
{
  int n,y,x;
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d%d", &n, &x, &y);
      scanf("%s%s", a, b);
      if (x < y) swap(x, y);
      int cnt = 0;
      for (int i = 0; i < n; i++)
      {
        if (a[i] == b[i]) cnt++;
      }
      int p = n - cnt;
      bool ans = true;
      if (abs(x - y) > p)
      {
        ans = false;
      }
      if (x > p && y < x - p)
      {
        ans = false;
      }
      if (cnt * 2 + p < x + y)
      {
        ans = false;
      }
      if (ans)
      {
        printf("Not lying\n");
      }
      else
      {
        printf("Lying\n");
      }
    }
  }
}
