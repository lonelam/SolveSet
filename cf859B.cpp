#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;

int n;
int main()
{
  scanf("%d", &n);
  int ans = 2 * (n + 1);
  for (int i = 2; i * i <= n; i++)
  {
    ans = min(ans, 2 * (i + (n + i - 1) / i));
  }
  printf("%d\n", ans);
}
