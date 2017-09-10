#include <iostream>
#include <vector>
#include <cassert>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(ll x)
{
  if (x == 0) return 0;
    // if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y)
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
  if (l1.is_rad == false)
  {
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;

  }
    auto interpoint = l1 & l2;
    if (interpoint.first == 1) return false;
    if (interpoint.first == 0)
    {
      // printf("debug");
      return !(sgn((l1.e - l1.s) *(l2.s - l1.s))< 0 && sgn((l1.e - l1.s) *(l2.e - l1.s)) < 0);
    }
    l1.e = interpoint.second + (l1.e - l1.s);
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

// bool Seg_inter_line(Line l1,Line l2) //判断she线l1和线段l2是否相交
// {
//   assert(l1.is_rad);
//     auto interpoint = l1 & l2;
//     if (interpoint.first == 1) return false;
//     if (interpoint.first == 0)
//     {
//       return !(sgn((l1.s - l1.e) *(l1.e - l2.s))< 0 && sgn((l1.s - l1.e) *(l1.e - l2.e)) < 0);
//     }
//     l1.s = interpoint.second + (l1.s - l1.e);
//     return
//     max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
//     max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
//     max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
//     max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
//     sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
//     sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
//
// }
Line V[3][2];
Point Ang[3][2];
Point vi[2];
bool OnSeg(Point P,Line L)
{
 return
 sgn((L.s-P)^(L.e-P)) == 0 &&
 sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
 sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
//*判断点在凸多边形内
//点形成一个凸包，而且按逆时针排序（如果是顺时针把里面的<0改为>0）
//点的编号:0~n-1
//返回值：
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inConvexPoly(Point a)
{
  if (sgn((Ang[2][1] - Ang[1][1]) ^ (Ang[1][1] - Ang[0][1])) == 1)
  {
    swap(Ang[1][1], Ang[2][1]);
  }
  for (int i = 0; i < 3; i++)
  {
      cout << Ang[i][1].x <<" "<< Ang[i][1].y <<endl;

  }
    for(int i = 0;i < 3;i++)
    {
    if(sgn((Ang[i][1]-a)^(Ang[(i+1)%3][1]-a)) < 0)return -1;
    else if(OnSeg(a,Line(Ang[i][1],Ang[(i+1)%3][1])))return 1;
    }
    return 1;
}
int main()
{
  int T;
  int kase = 1;
  scanf("%d", &T);
  while(T--)
  {
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        scanf("%lld%lld", &Ang[j][i].x, &Ang[j][i].y);
      }
      scanf("%lld%lld", &vi[i].x, &vi[i].y);
    }
    bool ans = false;
    if (vi[0].x == vi[1].x && vi[0].y == vi[1].y )
    {
      for (int i = 0; i < 3; i++)
      {
        if (inConvexPoly(Ang[i][0]) == 1)
        {
          ans = true;
        }
        vector<ll> a2;
        for (int j = 0; j < 3; j++)
        {
          // Point r1(Ang[i][0] - Ang[j][1]);
          // Point r2(Ang[(j+1)%3][1] - Ang[j][1] );
          // ll tmp = sgn(r1 ^ r2);
          // if (tmp == 0)
          // {
          //   ans = true;
          // }
          // a2.push_back(tmp);
          Line l1(Ang[i][0], Ang[(i+1)%3][0]);
          l1.is_rad = false;
          Line l2(Ang[j][1], Ang[(j+1)%3][1]);
          l2.is_rad = false;
          if (inter(l1,l2))
          {
            ans = true;
          }
        }
        // if (a2[0] == a2[1] && a2[0] == a2[2] && a2[1]==a2[2])
        // {
        //   ans = true;
        // }
      }
        for (int i = 0; i < 3; i++)
        {
          swap(Ang[i][0], Ang[i][1]);
        }
      for (int i = 0; i < 3; i++)
      {
        if (inConvexPoly(Ang[i][0]) == 1)
        {
          ans = true;
        }
        vector<ll> a2;
        for (int j = 0; j < 3; j++)
        {
          // Point r1(Ang[i][0] - Ang[j][1]);
          // Point r2(Ang[(j+1)%3][1] - Ang[j][1] );
          // ll tmp = sgn(r1 ^ r2);
          // if (tmp == 0)
          // {
          //   ans = true;
          // }
          // a2.push_back(tmp);
          Line l1(Ang[i][0], Ang[(i+1)%3][0]);
          l1.is_rad = false;
          Line l2(Ang[j][1], Ang[(j+1)%3][1]);
          l2.is_rad = false;
          if (inter(l1,l2))
          {
            ans = true;
          }
        }
        // if (a2[0] == a2[1] && a2[0] == a2[2] && a2[1]==a2[2])
        // {
        //   ans = true;
        // }
      }
    }
    else
    for (int i = 0; i < 2; i++)
    {
      //vector
      for (int j = 0; j < 3; j++)
      {
        //seg
        for (int k = 0; k < 3; k++)
        {
          //radline
          Line l1(Ang[j][i], Ang[j][i] + vi[i] - vi[i^1]);
          l1.is_rad = true;
          //seg
          Line l2(Ang[k][i ^ 1], Ang[(k+1)%3][i^1]);
          l2.is_rad = false;
          if (inter(l1, l2))
          {
            ans = true;
          }
        }
      }
    }
    if (ans)
    {
      printf("Case #%d: YES\n",kase++);
    }
    else
    {

      printf("Case #%d: NO\n", kase++);
    }
  }
}
/*
10
0 2 2 2 1 4 1 0
3 1 4 1 2 2 2 0
0 2 5 0 2 5 1 0
5 2 6 2 6 4 1 0

10
0 2 5 0 2 5 1 0
5 2 6 2 6 4 -1 0
Case #1: YES
0 2 5 0 2 5 0 1
5 2 6 2 6 4 0 -1
Case #2: YES
0 2 4 0 2 5 0 1
5 2 6 2 6 4 0 -1
Case #3: NO
0 2 4 0 2 5 0 1
3 2 6 2 6 4 0 1
Case #4: YES
3 2 6 2 6 4 0 1
0 2 4 0 2 5 0 1
Case #5: YES
0  2 4 2 2 5 0 1
3 2 6 2 6 4 0 1
Case #6: YES
3 2 6 2 6 4 0 1
0  2 4 2 2 5 0 1
Case #7: YES
0 2 4 2 7 4 0 1
3 2 6 2 6 4 0 1
Case #8: YES
0 0 10 0 0 10 0 0
1 1 1 2 2 1 0 0
Case #9: NO


*/
