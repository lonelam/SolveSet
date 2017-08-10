#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
  if(fabs(x) < eps)return 0;
  if(x < 0)return -1;
  else return 1;
}
struct Point
{
double x,y;
Point(){}
Point(double _x,double _y)
{
x = _x;y = _y;
}
Point operator -(const Point &b)const
{
return Point(x - b.x,y - b.y);
}
//叉积
double operator ^(const Point &b)const
{
return x*b.y - y*b.x;
}
//点积
double operator *(const Point &b)const
{
return x*b.x + y*b.y;
}
//绕原点旋转角度B（弧度值），后x,y的变化
void transXY(double B)
{
double tx = x,ty = y;
x = tx*cos(B) - ty*sin(B);
y = tx*sin(B) + ty*cos(B);
}
};

struct Line
{
Point s,e;
Line(){}
Line(Point _s,Point _e)
{
s = _s;e = _e;
}
//两直线相交求交点
//第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
//只有第一个值为2时，交点才有意义
 pair<int,Point> operator &(const Line &b)const
 {
 Point res = s;
 if(sgn((s-e)^(b.s-b.e)) == 0)
 {
 if(sgn((s-b.e)^(b.s-b.e)) == 0)
 return make_pair(0,res);//重合
 else return make_pair(1,res);//平行
 }
 double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
 res.x += (e.x-s.x)*t;
 res.y += (e.y-s.y)*t;
 return make_pair(2,res);
 }
};

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    double px, py,qx,qy, r, R;
    scanf("%lf", &R);
    scanf("%lf%lf", &px, &py);
    scanf("%lf%lf", &qx, &qy);
    double PQ = sqrt((qx - px) * (qx - px) + (qy - py) * (qy - py));
    r = sqrt(px * px + py * py);
    double d = sqrt(r * r - PQ * PQ / 4);
    double ans = 2 * sqrt(R * R - d * d);
    ans = min(ans, 2 * sqrt((R - d) * (R - d) + PQ * PQ / 4));
    printf("%.7f\n", ans);
  }
}
