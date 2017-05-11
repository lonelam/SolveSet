#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1 << 18;
#define _USE_MATH_DEFINES
const ld pi = M_PIl;
int blen, bmax, halflen;
int n;
void init()
{
  blen = 0;
  bmax = 1;
  while(bmax < n)
  {
    blen++;
    bmax <<= 1;
  }
}
inline int bit_rev(int x)
{
  int ans = 0;
  for (int i = 0; i < blen / 2; i++)
  {
    ans |= (1 << i & x)  (blen / 2 - i);
  }
}
