
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
#define Point pair<double, double>
#define x first
#define y second
#define LINE 0
#define CIRCLE 1
const double eps = 1e-9;
struct Line
{
  Point p1, p2;
};
struct Circle
{
  Point O;
  double r;
};
struct Object
{
  bool type;
  Circle c;
  Line l;
};
Circle ci[3];
inline double dist(Point A, Point B)
{
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
void getObject(Circle c1, Circle c2, Object & ans)
{
  if (abs(c1.r - c2.r) < eps)
  {
    ans.type = LINE;
    double xm = (c1.O.x + c2.O.x) / 2, ym = (c1.O.y + c2.O.y) / 2;
    ans.l.p1 = {xm, ym};
    double dx = c2.O.x - c1.O.x, dy = c2.O.y - c1.O.y;
    //rotate 90 degree
    swap(dx, dy);
    dx = -dx;
    ans.l.p2 = {xm + dx, ym + dy};
  }
  else
  {
    if (c1.r < c2.r) swap(c1, c2);
    double rat = c1.r / c2.r;
    Point A = {c1.O.x * (1 / (1 + rat)) + c2.O.x * (rat / (1 + rat)), c1.O.y * (1 / (1 + rat)) + c2.O.y * (rat / (1 + rat))};
    Point B = {-c1.O.x * (1 / (rat - 1)) + c2.O.x * (rat / (rat - 1)), -c1.O.y * (1 / (rat - 1)) + c2.O.y *(rat / (rat - 1))};
    ans.type = CIRCLE;
    ans.c.O = {(A.x + B.x) / 2, (A.y + B.y) / 2};
    ans.c.r = dist(A, B) / 2;
  }
}
void intersectObjects(Object o1, Object o2, vector<Point> & ans)
{
  if (o1.type == LINE && o2.type == LINE)
  {
    ans.push_back(insersectionL2L(o1.l, o2.l));
    return;
  }
}
int main()
{
  for (int i = 0; i < 3; i++)
  {
    scanf("%lf%lf%lf", &ci[i].O.x, &ci[i].O.y, &ci[i].r);
  }
  Object o1, o2;
  getObject(ci[0], ci[1], o1);
  getObject(ci[0], ci[2], o2);
  vector<Point> posSol;
  intersectObjects(o1, o2, posSol);
  if (!posSol.size()) return 0;
  double dsol = inf;
  Point sol;
}
