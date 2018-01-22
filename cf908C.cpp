#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n, r;
int x[maxn];
ld y[maxn];
set<pair<ld, int> > cs;
int main()
{
  while(~scanf("%d%d", &n, &r))
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", x + i);
      pair<ld,int> cls = {0, -1};
      for (pair<ld,int> cc: cs)
      {
        if (abs(cc.second - x[i]) <= r * 2)
        {
          cls = cc;
          break;
        }
      }
      if (cls.second == -1)
      {
        y[i] = r;
      }
      else
      {
        y[i] = -cls.first + sqrt((ld)(4 * r * r - (x[i] - cls.second) * (x[i] - cls.second)));
      }
      cs.insert({-y[i], x[i]});
    }
    for (int i = 0; i < n; i++)
    {
      printf("%.10Lf%c", y[i], i==(n-1)?'\n':' ');
    }
  }
}
