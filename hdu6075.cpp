
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int main()
{
  int T;
  int n;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      int cnt = 0;
      for (int i = 0; i < n; i++)
      {
        static int tmp;
        scanf("%d", &tmp);
        if (tmp & 1)
        {
          cnt++;
        }
      }
      if (cnt * 2 >= n)
      {
        printf("2 1\n");
      }
      else
      {
        printf("2 0\n");
      }
    }
  }
}
