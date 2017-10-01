#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
char buf[maxn];
int main()
{
  int T;
  while(~scanf("%d", &T))
  {
    while(T--)
    {
      int n;
      int cnt = 0;
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        scanf("%s", buf);
      if (strlen(buf) > 6 && string(buf, buf + 6) == string("bnu16-"))
      {
        cnt++;
      }
    }
      printf("%d\n", cnt);
    }
  }
}
