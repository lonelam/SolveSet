#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m;
int x[maxn], y[maxn];
int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", x + i);
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d", y + i);
    }
    ll xx = 0, yy = 0;
    int xi = 0, yi = 0;
    int cnt = 0;
    while(xi < n || yi <m)
    {
      if (xx <= yy)
      {
        xx += x[xi++];
      }
      else
      {
        yy += y[yi++];
      }
      if (xx == yy)
      {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
