#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  int n, T;
  int a,b,c, ab, bc,ac,abc;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      int ans = 0;
      for (int i = 0; i < n; i++)
      {
        scanf("%d%d%d%d%d%d%d", &a, &b, &c, &ab, &bc, &ac, &abc);
        ab -= abc;
        bc -= abc;
        ac -= abc;
        a -= ab + ac + abc;
        b -= ab + bc + abc;
        c -= bc + ac + abc;
        if (ab >= 0 && a >= 0 && b >= 0 && c >= 0 && ac >= 0 && bc >= 0  && abc >= 0 )
        {
          ans = max(a + b + c +  ac + bc + ab + abc, ans);
        }
      }
      printf("%d\n", ans);
    }
  }
}
