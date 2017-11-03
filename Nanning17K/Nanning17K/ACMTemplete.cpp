#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <cassert>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <sstream>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-8;
const ld PI = acosl(-1.0L);
#define y0 y000
#define y1 y111
int sgn(ld x)
{
	if (fabsl(x) < eps) return 0;
	if (x < 0) return -1;
	else return 1;
}
struct Point
{
	ld x, y;
	Point() {}

	Point(ld _x, ld _y)
	{
		x = _x, y = _y;
	}
	Point operator-(const Point & b) const
	{
		return Point(x - b.x, y - b.y);
	}
	bool operator==(const Point & b) const
	{
		return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
	}
	bool operator<(const Point & b) const
	{
		if (sgn(x - b.x) != 0) return x < b.x;
		return y < b.y;
	}
	//叉积
	ld operator ^(const Point &b)const
	{
		return x*b.y - y*b.x;
	}
	//点积
	ld operator *(const Point &b)const
	{
		return x*b.x + y*b.y;
	}
	//绕原点旋转角度B（弧度值），后x,y的变化
	void transXY(double B)
	{
		double tx = x, ty = y;
		x = tx*cos(B) - ty*sin(B);
		y = tx*sin(B) + ty*cos(B);
	}
	
};
struct Line
{
	Point s, e;
	Line() {}
	
	Line(Point _s, Point _e)
	{
		s = _s; e = _e;
	}
	
	bool operator<(const Line & b) const
	{
		return s.x > b.s.x;
	}
	//两直线相交求交点
	//第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
	//只有第一个值为2时，交点才有意义
	pair<int, Point> operator &(const Line &b)const
	{
		Point res = s;
		if (sgn((s - e) ^ (b.s - b.e)) == 0)
		{
			if (sgn((s - b.e) ^ (b.s - b.e)) == 0)
				return make_pair(0, res);//重合
			else return make_pair(1, res);//平行
		}
		ld t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return make_pair(2, res);
	}
};
//*两点间距离
ld dist(Point a, Point b)
{
	return sqrtl((a - b)*(a - b));
}//*判断线段相交
bool inter(Line l1, Line l2)
{
	return
		max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
		max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
		max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
		max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
		sgn((l2.s - l1.e) ^ (l1.s - l1.e))*sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 &&
		sgn((l1.s - l2.e) ^ (l2.s - l2.e))*sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}//判断直线和线段相交
bool Seg_inter_line(Line l1, Line l2) //判断直线l1和线段l2是否相交
{
	return sgn((l2.s - l1.e) ^ (l1.s - l1.e))*sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}
//点到直线距离
//返回为result,是点到直线最近的点
Point PointToLine(Point P, Line L)
{
	Point result;
	double t = ((P - L.s)*(L.e - L.s)) / ((L.e - L.s)*(L.e - L.s));
	result.x = L.s.x + (L.e.x - L.s.x)*t;
	result.y = L.s.y + (L.e.y - L.s.y)*t;
	return result;
}//计算多边形面积
//点的编号从0~n-1
double CalcArea(Point p[], int n)
{
	double res = 0;
	for (int i = 0; i < n; i++)
		res += (p[i] ^ p[(i + 1) % n]) / 2;
	return fabs(res);
}
//*判断点在线段上
bool OnSeg(Point P, Line L)
{
	return
		sgn((L.s - P) ^ (L.e - P)) == 0 &&
		sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
		sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
vector<Line> ns, ns2;
ld x0[2], y0[2], x1[2], y1[2];
bool inRect(Point o, int i)
{
	return x0[i] < o.x && o.x < x1[i] && y0[i] < o.y && o.y < y1[i];
}

int main()
{
	for (int i = 0; i < 2; i++)
	{
		cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
	}
	string buf;
	Point s, t;
	Line borders[4][2];
	Point angles[4][2];
	for (int i = 0; i < 2; i++)
	{
		angles[0][i] = Point(x0[i], y0[i]);
		angles[1][i] = Point(x1[i], y0[i]);
		angles[2][i] = Point(x1[i], y1[i]);
		angles[3][i] = Point(x0[i], y1[i]);
		for (int j = 0; j < 4; j++)
		{
			borders[j][i] = Line(angles[j][i], angles[(j + 1) % 4][i]);
		}
	}
	while (cin >> s.x >> s.y >> t.x >> t.y)
	{
		if (s.x == -1.0 && s.y == -1.0) break;
		Line lin(s, t);
		vector<Point> pss;
		for (int i = 0; i < 4; i++)
		{
			if (inter(borders[i][0], lin))
			{
				auto res = borders[i][0] & lin;
				pss.push_back(res.second);
			}
		}
		sort(pss.begin(), pss.end());
		pss.erase(unique(pss.begin(), pss.end()), pss.end());
		if (pss.size() == 0)
		{
			if (inRect(s, 0) && inRect(t, 0))
			{
				ns.push_back(lin);
			}
			else
			{
				continue;
			}
		}
		else if (pss.size() == 1)
		{
			if (inRect(s, 0))
			{
				ns.push_back(Line(pss[0], s));
			}
			else if (inRect(t, 0))
			{
				ns.push_back(Line(pss[0], t));
			}
			else
			{
				assert(true);
			}
		}
		else if (pss.size() == 2)
		{
			ns.push_back(Line(pss[0], pss[1]));
		}
		else
		{
			assert(true);
		}
	}
	for (int k = 0; k < ns.size(); k++)
	{
		Line lin = ns[k];
		//cout << lin.s.x << " " << lin.s.y << " " << lin.e.x << " " << lin.e.y << endl;
		vector<Point> pss;
		for (int i = 0; i < 4; i++)
		{
			if (inter(borders[i][1], lin))
			{
				auto res = borders[i][1] & lin;
				pss.push_back(res.second);
			}
		}
		sort(pss.begin(), pss.end());
		pss.erase(unique(pss.begin(), pss.end()), pss.end());
		if (pss.size() == 0)
		{
			if (inRect(lin.s, 1) && inRect(lin.e, 1))
			{
				continue;
			}
			ns2.push_back(lin);
		}
		else if (pss.size() == 1)
		{
			if (inRect(lin.s, 1))
			{
				ns2.push_back(Line(lin.e, pss[0]));
			}
			else if (inRect(lin.e, 1))
			{
				ns2.push_back(Line(lin.s, pss[0]));
			}
			else
			{
				assert(true);
			}
		}
		else if (pss.size() == 2)
		{
			if (dist(lin.s, pss[0]) < dist(lin.s, pss[1]))
			{
				ns2.push_back(Line(lin.s, pss[0]));
				ns2.push_back(Line(lin.e, pss[1]));
			}
			else
			{
				ns2.push_back(Line(lin.e, pss[0]));
				ns2.push_back(Line(lin.s, pss[1]));
			}
		}
		else
		{
			assert(true);
		}
	}

	for (int i = 0; i < ns2.size(); i++)
	{
		if (ns2[i].s.x >= ns2[i].e.x) swap(ns2[i].s, ns2[i].e);
	}
	sort(ns2.begin(), ns2.end());
	for (int i = 0; i < ns2.size(); i++)
	{
		if (ns2[i].s == ns2[i].e)
		{
			continue;
		}
		else
		{
			printf("%.4Lf %.4Lf %.4Lf %.4Lf\n", ns2[i].s.x, ns2[i].s.y, ns2[i].e.x, ns2[i].e.y);
		}
	}
	return 0;
	return 0;
}
/*

*/