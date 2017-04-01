#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}
struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y):x(_x), y(_y) {}

}
class PolygonRotation
{
public:
    PolygonRotation() {}

    bool _cmp(Point p1, Point p2)
    {
        double tmp = (p1 - list[0]) ^ (p2 - list[0]);
        if (sgn(tmp) > 0) return true;
        else if (sgn(tmp) == 0 && sgn(dist(p1, list[0]) - d))
    }

    double getVolume(vector <int> x, vector <int> y)
    {
        for (int i = 0; i < x.size(); i++)
        {
            if ()
        }
    }
};
