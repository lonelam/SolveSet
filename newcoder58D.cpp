#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n, m;
char s[maxn];
int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    scanf("%s", s);
    for (int i = 0; i < m; i++)
    {
      int l, r;
      char u[2], v[2];
      scanf("%d%d", &l, &r);
      scanf("%s%s", u, v);
      for (int i = l - 1; i < r; i++)
      {
        if (s[i] == u[0])
        {
          s[i] = v[0];
        }
      }
    }
    printf("%s\n", s);
  }
}
