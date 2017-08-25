#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define p(a) ((a) * (a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int f;
double s, dx, dy, x[3], y[3], r[3], t[3];
double F(double dx, double dy)
{
  double ret = 0;
  for (int i = 0; i < 3; i++)
  {
    t[i] = sqrt(p(dx - x[i]) + p(dy - y[i])) / r[i];
  }
  for (int i = 0; i < 3; i++)
  {
    ret += p(t[i] - t[(i+1) % 3]);
  }
  return ret;
}
int main()
{
  for (int i = 0; i < 3; i++)
  {
    scanf("%lf%lf%lf", x + i, y + i, r + i);
  }
  for (int i = 0; i < 3; i++)
  {
    dx += x[i] / 3;
    dy += y[i] / 3;
  }
  for (s = 1; s > 1e-6; f = 0)
  {
    if (F(dx, dy) > F(dx + s, dy)) dx += s, f = 1;
    else if (F(dx, dy) > F(dx - s, dy)) dx -= s, f = 1;
    else if (F(dx, dy) > F(dx, dy + s))
    {
      dy += s, f = 1;
    }
    else if (F(dx, dy) > F(dx, dy - s))
    {
      dy -= s, f = 1;
    }
    if (!f) s *= 0.7;
  }
  if (F(dx, dy) < 1e-5) printf("%.5lf %.5lf\n", dx, dy);
}
