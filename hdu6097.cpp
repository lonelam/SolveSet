
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



const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}


const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write()
{
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(const char *s)
{
    while(*s)
    {
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x)
    {
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x)
    {
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}



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

    double px, py,qx,qy, r, R;
    double PQ;
    double d;
bool check(double a, double b)
{
  double a2 = a * a;
  double b2 = b * b;
  double A = (1 - a2 / b2);
  double B = -2 * d;
  double C = a2 + d * d - R * R;
  double delta = B * B - 4 * A * C;
  if (delta < 0) return false;
  double y = (-B + sqrt(delta)) *0.5 / A;
  double x2 = a2 - a2 / b2 * y * y;
  if (x2 >= 0) return true;
  y = (-B - sqrt(delta)) *0.5 / A;
  x2 = a2 - a2 / (b * b) * y * y;
  if (x2 >= 0) return true;
  return false;
  // if (x2 < 0) return false;
  // return true;
}




int main()
{
  // freopen("data.in", "r", stdin);
  int T;
  in(T);
  while(T--)
  {
    static int tR;
    in(tR);
    R = tR;
    static int tpx, tpy, tqx, tqy;
    in(tpx);
    in(tpy);
    in(tqx);
    in(tqy);
    px = tpx;py = tpy;
    qx = tqx, qy = tqy;
    r = sqrt(px * px + py * py);
    PQ = sqrt((qx - px) * (qx - px) + (qy - py) * (qy - py));
    d = sqrt(r * r - PQ * PQ *0.25);
    double ans = 2 * sqrt(R * R - d * d);
    ans = min(ans, 2 * sqrt((R - d) * (R - d) + PQ * PQ * 0.25));
    double lef = PQ * 0.5, righ = sqrt((R - d) * (R - d) + PQ * PQ * 0.25);
    for (int i = 0; i < 50; i++)
    {
      double mid = (lef + righ) / 2;
      if (check(mid, sqrt(mid * mid - PQ * PQ / 4)))
      {
        righ = mid;
      }
      else
      {
        lef = mid;
      }
    }
    // cout << 2 * lef << endl;
    // cout << check(righ, sqrt(righ * righ - PQ * PQ / 4)) << endl;
    ans = min(ans, 2 * righ);

    out_str(to_string(ans).c_str());
    out_str("\n");
    // printf("%.7f\n", ans);
  }
  write();
}
