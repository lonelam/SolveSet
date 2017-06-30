#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int q;
int main()
{
  int q;
  scanf("%d", &q);
  while(q--)
  {
    int n;
    scanf("%d", &n);
    int x = (-1.0 + sqrt(1 + (ld)8 * (ld)n)) / 2;
    printf("%lld\n", n-x + x*(x-1) / 2);
  }
}
