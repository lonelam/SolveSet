#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;

struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y) :x(_x), y(_y) {}
    double operator *(const Point & rhs) const
    {
        return x * rhs.y - y * rhs.x;
    }
    Point operator- (const Point & b) const
    {
        return Point(x - b.x, y - b.y);
    }
};
struct Line
{
    Point s, e;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
    }
};
double dist(Point &lhs, Point & rhs)
{
    return sqrt((lhs - rhs) * (lhs - rhs));
}
Point PointToLine(Point & P, Line & L)
{
    Point result;
    double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
    result.x = L.s.x + (L.e.x - L.s.x) * t;
    result.y = L.s.y + (L.e.y - L.s.y) * t;
    return result;
}
Point ps[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i].x >> ps[i].y;
    }
    double ans = inf;
    for (int i = 0; i < n; i++)
    {
        Line pass(ps[(i + 1) % n], ps[(i + n - 1) % n]);
        Point mpoint = PointToLine(ps[i], pass);
        ans = min(ans, dist(mpoint, ps[i]));
    }
    cout << ans << endl;
}
