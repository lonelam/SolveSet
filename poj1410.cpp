#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

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

const ld eps = 1e-8;
const ld PI = acos(-1.0);
int sgn(double x)
{
  if (fabs(x) < eps) return 0;
  if (x < 0) return -1;
  else return 1;
}
struct point
{
  ld x, y;
  point() {}
  point(ld _x, ld _y): x(_x), y(_y) {}
  //get vector
  point operator-(const point & b) const
  {
    return point(x - b.x, y - b.y);
  }
  //Cross product
  ld operator ^(const point &b) const
  {
    return x * b.y - y * b.x;
  }
  // point product
  ld operator *(const point & b) const
  {
    return x * b.x + y * b.y;
  }
  //rotate point by origin in B degree
  void transXY(ld B)
  {
    ld tx = x, ty = y;
    x = tx * cos(B) - ty * sin(B);
    y = tx * sin(B) + ty * cos(B);
  }
};
struct line
{
  point s, e;
  line() {}
  line(point _s, point _e): s(_s), e(_e){}
  // get the interset point of two LINES
  // 0 means  coincide
  // 1 means parade
  // 2 means intersection and second is inter point
  pair<int,point> operator & (const line & b) const
  {
    point res = s;
    if (sgn((s - e) ^ (b.s - b.e)) == 0)
    {
      if (sgn((s - e) ^ (b.s - b.e)) == 0)
      {
        return make_pair(0, res);
      }
      else
      {
        return make_pair(1, res);
      }
    }
    ld t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
    res.x += (e.x - s.x) * t;
    res.y += (e.y - s.y) * t;
    return make_pair(2, res);
  }
};

ld dist(point a, point b)
{
  return sqrt((a - b) * (a - b));
}


// if endpoints are not included, just all the equal signs
bool inter(line l1, line l2)
{
  return
    max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
    max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
    max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
    max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
    // 跨立实验
    sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^(l1.s - l1.e)) <= 0 &&
    sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}

double xstart, ystart, xend, yend, xright, ytop, xleft, ybottom;
bool check()
{
  if (xleft > xright)swap(xleft, xright);
  if (ybottom > ytop) swap(ybottom , ytop);
  if (xstart >= xleft && xstart <= xright && ystart >= ybottom && ystart <= ytop)
  {
    return true;
  }
  if (xend >= xleft && xend <= xright && yend >= ybottom && yend <= ytop)
  {
    return true;
  }
  line s(point(xstart, ystart), point(xend, yend));
  point p0(xleft, ytop), p1(xright, ytop), p2(xright, ybottom), p3(xleft, ybottom);
  if (inter(line(p0, p1), s) || inter(s, line(p1, p2)) || inter(s, line(p2, p3)) || inter(s, line(p3, p0)))
  {
    return true;
  }
  return false;
}
int main()
{
  int n;
  scanf("%d", &n);
  while(n--)
  {
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &xstart, &ystart, &xend, &yend, &xleft, &ytop, &xright, &ybottom);
    if (check())
    {
      printf("T\n");
    }
    else
    {
      printf("F\n");
    }
  }
}
/*
1
2 4 4 2 1 1 11 11


*/
