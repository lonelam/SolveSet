#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll eps = 5;
const ll m = 100000;
__int128 abs(__int128 x)
{
  return x < 0 ? -x : x;
}
__int128 sum(__int128 x1,__int128 y1,__int128 x2,__int128 y2,__int128 x3,__int128 y3,__int128 x,__int128 y)
{
  return abs((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) - (x2 - x) * (x2 - x) - (y2 - y) * (y2 - y)) +
         abs((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) - (x3 - x) * (x3 - x) - (y3 - y) * (y3 - y)) +
         abs((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) - (x3 - x) * (x3 - x) - (y3 - y) * (y3 - y));
}
void cir(__int128 x1,__int128 y1,__int128 x2,__int128 y2,__int128 x3,__int128 y3,__int128 & x,__int128 & y)
{
  x = (x1 + x2 + x3) / 3;
  y = (y1 + y2 + y3) / 3;
  __int128 pre = sum(x1,y1,x2,y2,x3,y3,x,y);
  __int128 tmp;

  for (__int128 step = max({abs(x1 - x2), abs(x1 - x3), abs(x2 - x3), abs(y1 - y2), abs(y1 - y3), abs(y2 - y3)}); step > 0; step >>= 1)
  {
    bool flg = true;
    while(flg)
    {
      cout << (ll) (x) << " "<< (ll) (y) << " "<< (ll)sum(x1,y1,x2,y2,x3,y3,x,y) << endl;
      flg = false;
      if ((tmp = sum(x1,y1,x2,y2,x3,y3,x + step,y)) < pre)
      {
        flg = true;
        pre = tmp;
        x += step;
      }
      if ((tmp = sum(x1, y1, x2, y2, x3, y3, x - step, y)) < pre)
      {
        flg = true;
        pre = tmp;
        x -= step;
      }
      if ((tmp = sum(x1,y1,x2,y2,x3,y3,x,y + step)) < pre)
      {
        flg = true;
        pre = tmp;
        y += step;
      }
      if ((tmp = sum(x1, y1, x2, y2, x3, y3, x, y - step)) < pre)
      {
        flg = true;
        pre = tmp;
        y -= step;
      }
    }
  }
  // assert(abs(sum(x1,y1,x2,y2,x3,y3,x,y)) < eps);
  cout << (ll) (x) << " "<< (ll) (y) << " "<< (ll)sum(x1,y1,x2,y2,x3,y3,x,y) << endl;
}
__int128 dis2(__int128 x0, __int128 y0, __int128 x1, __int128 y1)
{
  return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}
int main()
{
  ll x1,y1,x2,y2,x3,y3,x,y;
  __int128 cx, cy;
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3,&x,&y);
    x1 *= m;
    y1 *= m;
    x2 *= m;
    y2 *= m;
    x3 *= m;
    y3 *= m;
    x *= m;
    y *= m;
    cir(x1, y1, x2, y2, x3, y3, cx, cy);
    if (abs(dis2(cx, cy, x, y) - dis2(cx, cy, x1, y1)) > eps && dis2(cx, cy, x, y) > dis2(cx, cy, x1, y1))
    {
      printf("Accepted\n");
    }
    else
    {
      printf("Rejected\n");
    }
  }
}
