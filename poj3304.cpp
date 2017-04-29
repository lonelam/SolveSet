#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;

const double eps = 1e-8;
int sgn(double x)
{
  if (fabs(x) < eps) return 0;
  if (x < 0) return -1;
  else return 1;
}
struct point
{
  double x, y;
  point() {}
  point(double _x, double _y) : x(_x), y(_y) {}
  point operator-(const point & b) const
  {
    return point(x - b.x, y - b.y);
  }
  double operator^(const point & b) const
  {
    return x * b.y - y * b.x;
  }
};
struct line
{
  point s, e;
  line() {}
  line(point _s, point _e)
  {
    s = _s, e = _e;
  }
};
bool line_inter_seg(line l1, line l2)
{
  return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}

int n;
line ls[maxn];
point ps[maxn * 2];
int main()
{
  int T;
  while(scanf("%d", &T)!= EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        scanf("%lf%lf%lf%lf", &ls[i].s.x, &ls[i].s.y, &ls[i].e.x, &ls[i].e.y);
        ps[i << 1] = ls[i].s;
        ps[i << 1 | 1] = ls[i].e;
      }
      bool fnd = false;
      for (int i = 0; !fnd && i < n * 2; i++)
      {
        for (int j = 0; j < n * 2 ; j++)
        {
          line horizon(ps[i], ps[j]);
          if (ps[i].x == ps[j].x && ps[i].y == ps[j].y) continue;
  //        cout << ps[i].x << " "<< ps[i].y <<" "<< ps[j].x <<" "<< ps[j].y << endl;
          bool ok = true;
          for (int k = 0; k < n; k++)
          {
            if (!line_inter_seg(horizon, ls[k]))
            {
              ok = false;
              break;
            }
          }
          if (ok)
          {
            fnd = true;
            break;
          }
        }
      }
      if (fnd)
      {
        printf("Yes!\n");
      }
      else
      {
        printf("No!\n");
      }
    }
  }
}
