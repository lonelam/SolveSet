#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1500 + 10;
int a[maxn];
int main()
{
  int n, m;
  while(~scanf("%d", &n))
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (a[i] > a[j])
        {
          cnt++;
        }
      }
    }
    cnt &= 1;
    int l, r;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d", &l, &r);
      const int len = (r - l + 1);
      int pn = (len * (len - 1)) / 2;
      if (pn & 1)
      {
        cnt ^= 1;
      }
      if (cnt)
      {
        printf("odd\n");
      }
      else
      {
        printf("even\n");
      }
    }
  }
}
