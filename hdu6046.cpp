#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
int kase  = 1;
inline unsigned sfr(unsigned h, unsigned x)
{
  return h >> x;
}
int f(ll i, ll j) {
    ll w = i * 1000000ll + j;
    int h = 0;
    for(int k = 0; k < 5; ++k) {
        h += (int) ((w >> (8 * k)) & 255);
        h += (h << 10);
        h ^= sfr(h, 6);
    }
    h += h << 3;
    h ^= sfr(h, 11);
    h += h << 15;
    return sfr(h, 27) & 1;
}
char c[1100][1100];
int a[1100][1100];
ll b[1010][1010];
const int sz = 7, stride = 550;
int en;
struct node
{
  ll h;
  int x, y;
  bool operator < (const node & e) const
  {
    if (h == e.h)
    {
      if (x == e.x)
      {
        return y < e.y;
      }
      return x < e.x;
    }
    return h < e.h;
  }
};
bool check(int top, int left)
{
  for (int i = 0; i < 1000; ++i)
  {
    for (int j = 0; j < 1000; ++j)
    {
      if (f(i + top, j + left) != c[i][j])
      {
        return false;
      }
    }
  }
  en = 1;

}
