#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T, n, q;
typedef unsigned int uint;
unsigned int a[maxn];
uint inva[maxn];
uint p_m(uint base, uint index = 0xfffffffe)
{
  uint ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret *= base;
    }
    base *= base;
    index >>=1;
  }
  return ret;
}
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &q);
    uint S = 1;
    for (int i = 0; i < n; i++)
    {
      scanf("%u", a + i);
      S *= a[i];
      inva[i] = p_m(a[i]);
      cout << inva[i] << endl;
    }
    for (int i = 0; i < q; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      printf("%u\n", S * inva[tmp-1]);
    }
  }
}
