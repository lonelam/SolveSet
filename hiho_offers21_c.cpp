#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define double ld
const int inf = 0x3f3f3f3f;
const int maxn = 400;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
  if (fabs(x) < eps)
  {
    return 0;
  }
  if (x < 0) return -1;
  else return 1;
}
struct Point
{
  double x, y;
  Point() {}
  Point(double _x, double _y) : x(_x), y(_y){}
  Point operator - (const Point & b) const
  {
    return Point(x - b.x, y - b.y);
  }
  double operator ^ (const Point & b) const
  {
    return x * b.y - y * b.x;
  }
  bool operator== (const Point & b) const
  {
    return x == b.x && y == b.y;
  }
};
struct Line
{
  Point s, e;
  Line() {};
  Line(Point _s, Point _e):s(_s), e(_e){}
  Point operator & (const Line & b) const
  {
    Point res = s;
    double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
    res.x += (e.x - s.x) * t;
    res.y += (e.y - s.y) * t;
    return res;
  }
};
bool inter(Line l1, Line l2)
{
  return
  max(l1.s.x, l1.e.x) > min(l2.s.x, l2.e.x) &&
  max(l2.s.x, l2.e.x) > min(l1.s.x, l1.e.x) &&
  max(l1.s.y, l1.e.y) > min(l2.s.y, l2.e.y) &&
  max(l2.s.y, l2.e.y) > min(l1.s.y, l1.e.y) &&
  sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) < 0 &&
  sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) < 0;
}
double dist(Point a, Point b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}
Line ls[maxn];
int ltot = 0;
Point ps[maxn];
int ptot = 0;
static double X[maxn], Y[maxn];
double N, M, K;
int Q;
double xs, ys, xt, yt;
bool G[maxn][maxn];

int main()
{
  int T;
  while(cin >> T)
  {
    while(T--)
    {
      cin >> N >> M >> K >> Q;
      ltot = ptot = 0;
      for (int i = 0; i <= Q; i++)
      {
        cin >> X[i] >> Y[i];
        ps[ptot++] = Point(X[i] + K, Y[i]);
        ps[ptot++] = Point(X[i] - K, Y[i]);
        ps[ptot++] = Point(X[i], Y[i] + K);
        ps[ptot++] = Point(X[i], Y[i] - K);
        ls[ltot++] = Line(ps[ptot - 1], ps[ptot - 3]);
        ls[ltot++] = Line(ps[ptot - 1], ps[ptot - 4]);
        ls[ltot++] = Line(ps[ptot - 2], ps[ptot - 3]);
        ls[ltot++] = Line(ps[ptot - 2], ps[ptot - 4]);
      }
      ls[ltot++] = Line(Point(0,0), Point(0, M));
      ls[ltot++] = Line(Point(0, 0), Point(N, 0));
      ls[ltot++] = Line(Point(0, M), Point (N, M));
      ls[ltot++] = Line(Point(N, 0), Point(N, M));
      cin >> xs >> ys >> xt >> yt;
      for (int i = 0; i < ltot; i++)
      {
        for (int j = i + 1; j < ltot; j++)
        {
          if (inter(ls[i], ls[j]))
          {
            ps[ptot++] = ls[i] & ls[j];
          }
        }
      }
      for (int i = 0; i < ptot; i++)
      {
        G[i][i] = 1;
        for (int j = i + 1; j < ptot; j++)
        {
          G[i][j] = G[j][i] = 1;
          if (sgn(ps[i].x )< 0 || sgn(ps[i].y) < 0 || sgn(ps[i].x - N) > 0 || sgn(ps[i].y - M) > 0 )
          {
            G[i][j] = G[j][i] = 0;
            continue;
          }
          if (sgn(ps[j].x )< 0 || sgn(ps[j].y) < 0 || sgn(ps[j].x - N) > 0 || sgn(ps[j].y - M) > 0 )
          {
            G[i][j] = G[j][i] = 0;
            continue;
          }
          if (ps[i] == ps[j])
          {
            continue;
          }
          for (int k = 0; k <= Q; k++)
          {
            if (sgn(dist(ps[i], Point(X[k], Y[k]))-K) == 0 && sgn(dist(ps[i], Point(X[k], Y[k])) - K ) == 0 && sgn(dist((Point((ps[i].x + ps[j].x)/ 2, (ps[i].y + ps[j].y) / 2)), Point(X[k], Y[k])) - K) < 0)
            {
              G[i][j] = G[j][i] = 0;
              break;
            }
          }
          for (int k = 0; k < ltot; k++)
          {
            if (inter(Line(ps[j], ps[i]), ls[k]))
            {
              G[i][j] = G[j][i] = 0;
              break;
            }
          }
        }
      }
      for (int k = 0; k < ptot; k++)
      {
        for (int i = 0; i < ptot; i++)
        {
          for (int j = 0; j < ptot; j++)
          {
            G[i][j] |= G[i][k] && G[k][j];
          }
        }
      }
      int spoint = -1; int tpoint = -1;
      Point SS(xs, ys), TT(xt, yt);
      for (int i = 0; i < ptot; i++)
      {
        if (sgn(ps[i].x )< 0 || sgn(ps[i].y) < 0 || sgn(ps[i].x - N) > 0 || sgn(ps[i].y - M) > 0 )
        {
          continue;
        }
        if (spoint == -1 || dist(ps[i], SS) < dist(ps[spoint], SS))
        {
          spoint = i;
        }
        if (tpoint == -1 || dist(ps[i], TT) < dist(ps[tpoint], TT))
        {
          tpoint = i;
        }
      }
      int ans = G[spoint][tpoint];
      for (int i = 0; i <= Q; i++)
      {
        if (dist(Point(X[i], Y[i]), SS) < K || dist(Point(X[i], Y[i]), TT) < K)
        {
          ans = 0;
          break;
        }
      }
      if (ans)
      {
        cout << "Yes\n";
      }
      else
      {
        cout << "No\n";
      }
    }
  }
}
/*
1
100 100 20 3
19 19
80 20
20 80
80 80
50 50
0 0
*/
