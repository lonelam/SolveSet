#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
typedef double ld;
const int inf = 0x3f3f3f3f;
const ld eps = 1e-7;
const ld PI = acos(-1.0);

int sgn(double x)
{
  if (abs(x) < eps) return 0;
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

ld x[4], y[4];
point p[4];
ld solve()
{
    if (!inter(line(p[0], p[1]), line(p[2], p[3]))) return 0;
    pair<int, point> res = line(p[0], p[1]) & line(p[2], p[3]);
    if (res.first != 2) return 0;
    if (p[0].y < p[1].y) swap(p[0], p[1]);
    if (p[2].y < p[3].y) swap(p[2], p[3]);
    if (p[0].y > p[2].y) swap(p[0], p[2]);
    point stick0 = p[2] - res.second;
    point stick1 = p[0] - res.second;
    if (sgn(p[2].x - res.second.x) * sgn(p[0].x - res.second.x) >= 0 && sgn(p[2].x - res.second.x) * sgn(p[2].x - p[0].x) >= 0 && sgn(stick0.x) != 0 && sgn(stick1.x) != 0 && abs(stick0.y* stick1.x) > abs(stick1.y * stick0.x)) return 0;
    if (sgn(p[2].y - res.second.y) == 0 ) return 0;
    ld t = (p[0].y - res.second.y) / (p[2].y - res.second.y);
    p[2].x = res.second.x + (p[2].x - res.second.x) * t;
    p[2].y = p[0].y;
    return abs((p[0] - res.second) ^ (p[2] - res.second)) / 2.0;
}
int main()
{

  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int T;
  ios::sync_with_stdio(0);cin.tie(0);

  cout.setf(ios::fixed);
  cout.precision(2);
  while(cin >> T)
  {
    while(T--)
    {
      for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
      printf("%.2f\n", solve() + eps);
    }
  }
}
/*
100
28 25 41 66
41 66 38 66
*/
