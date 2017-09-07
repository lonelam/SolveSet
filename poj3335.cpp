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
#define x first
#define y second
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
typedef pair<int,int> pii;
typedef pair<double,double> Point;
double eps = 1e-6;
Point operator-(const Point & lhs,const Point & rhs)
{
  return Point({lhs.x - rhs.x, lhs.y - rhs.y});
}
// double operator*(const Point & lhs,const Point & rhs)
// {
//   return lhs.x * rhs.x + lhs.y * rhs.y;
// }
double operator *(const Point & lhs,const Point & rhs)
{
  return lhs.x * rhs.y - lhs.y * rhs.x;
}
struct Line
{
  Point s, e;
  double k;
  Point operator & (const Line & b) const
  {
    Point res = s;
    double t = ((s - b.s) * (b.s - b.e)) / ((s - e) * (b.s - b.e));
    res.x += (e.x - s.x) * t;
    res.y += (e.y - s.y) * t;
    return res;
  }
}Q [maxn];
bool HPIcmp(Line a, Line b)
{
  if (fabs(a.k - b.k) > eps) return a.k < b.k;
  return ((a.s - b.s) * (b.e - b.s)) < 0;
}
void HPI(Line line[], int n, Point res[], int & resn)
{
  int tot = n;
  sort(line, line + n, HPIcmp);
  tot = 1;
  for (int i = 1; i < n; i++)
  {
    if (fabs(line[i].k - line[i - 1].k) > eps)
    {
      line[tot++] = line[i];
    }
  }
  int head = 0, tail = 1;
  Q[0] = line[0];
  Q[1] = line[1];
  resn = 0;
  for (int i = 2; i < tot; i++)
  {
    if (fabs((Q[tail].e - Q[tail].s) * (Q[tail - 1].e - Q[tail - 1].s))< eps || fabs((Q[head].e - Q[head].s) * (Q[head + 1].e - Q[head + 1].s)) < eps)
    {
      return;
    }
    while(head < tail && (((Q[tail] & Q[tail - 1]) - line[i].s) * (line[i].e - line[i].s)) > eps)
    {
      tail--;
    }
    while(head < tail && (((Q[head] & Q[head + 1]) - line[i].s) * (line[i].e - line[i].s)) > eps)
    {
      head++;
    }
  }
}
int main()
{
  int T;
  int n;
  while(~scanf("%d", &T))
  {
    while(T--)
    {
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        scanf("%d%d", x + i, y + i);
      }
    }
  }

}
