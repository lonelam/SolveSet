#include <iostream>
#include <cassert>
#include<cstdio>
#include<cmath>
using namespace std;

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
    Point operator +(const Point &b)const
    {
        return Point(x + b.x,y + b.y);
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
    bool is_rad;
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
//*两点间距离
double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
//*判断线段相交
//l1 rad line
bool inter(Line l1,Line l2)
{
  assert(l1.is_rad);
    auto interpoint = l1 & l2;
    if (interpoint.first == 1) return false;
    if (interpoint.first == 0)
    {
      return !(sgn((l1.s - l1.e) *(l1.e - l2.s))< 0 && sgn((l1.s - l1.e) *(l1.e - l2.e)) < 0);
    }
    l1.s = interpoint.second + (l1.s - l1.e);
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

bool Seg_inter_line(Line l1,Line l2) //判断she线l1和线段l2是否相交
{
  assert(l1.is_rad);
    auto interpoint = l1 & l2;
    if (interpoint.first == 1) return false;
    if (interpoint.first == 0)
    {
      return !(sgn((l1.s - l1.e) *(l1.e - l2.s))< 0 && sgn((l1.s - l1.e) *(l1.e - l2.e)) < 0);
    }
    l1.s = interpoint.second + (l1.s - l1.e);
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;

}


int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        Point p1[4],d1;
        Point p2[4],d2;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&p1[0].x,&p1[0].y,&p1[1].x,&p1[1].y,&p1[2].x,&p1[2].y,&d1.x,&d1.y);
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&p2[0].x,&p2[0].y,&p2[1].x,&p2[1].y,&p2[2].x,&p2[2].y,&d2.x,&d2.y);
        p1[3]=p1[0];
        p2[3]=p2[0];
        Point d=d2-d1;
        cout << d.x << " "<< d.y << endl;
        bool suc=true;
        for(int i=0;i<=2;i++)
        {
            Line s1=Line(p1[i],p1[i+1]);
            for(int j=0;j<3;j++)
            {
                Point tp=p2[j]+d;
                Line l1=Line(tp,p2[j]);
                l1.is_rad = 1;
                suc&=!Seg_inter_line(s1,l1);
            }
        }
        printf("Case #%d: ",tt);
        if(suc)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
