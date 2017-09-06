#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxk = 31;
int cnt[32][2];
int a[maxn];
int p[maxn][3];
int n, q;
int main()
{
  while(~scanf("%d%d",&n, &q))
  {
    int axor = 0;
    int aand = 0xffffffff;
    int aor = 0;
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
      scanf("%d",  a + i);
      for (int j = 0; j < maxk; j++)
      {
        cnt[j][(a[i] >> j) & 1]++;
      }
      axor ^= a[i];
      aand &= a[i];
      aor |= a[i];
    }
    for (int i = 0; i < n; i++)
    {
      p[i][2] = axor ^ a[i];
      p[i][1] = aor;
      for (int j = 0; j < maxk; j++)
      {
        if (cnt[j][1] == 1 && ((a[i] >> j) & 1))
        {
          p[i][1] -= 1 << j;
        }
      }
      p[i][0] = aand;
      for (int j = 0; j < maxk; j++)
      {
        if(cnt[j][0] == 1 && !((a[i] >> j) & 1))
        {
          p[i][0] |= 1 << j;
        }
      }
    }
    while(q--)
    {
      int qi;
      scanf("%d", & qi);
      qi--;
      printf("%d %d %d\n", p[qi][0], p[qi][1], p[qi][2]);
    }
  }
}
