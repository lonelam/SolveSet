#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n;
int k[maxn];
int main()
{
  scanf("%d", &n);
  if (n == 2)
  {
    printf("3\n2 1 2\n");
  }
  else
  {
    printf("%d\n", n + (n / 2));
    for (int i = 2; i <= n; i += 2)
    {
      printf("%d%c", i, ' ');
    }
    for (int i = 1; i <= n; i += 2)
    {
      printf("%d%c", i, ' ');
    }
    for (int i = 2; i <= n; i += 2)
    {
      printf("%d%c", i, ' ');
    }
  }
}
