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
const int inf = 0x3f3f3f3f;
const double eps = 1e-10;

struct point
{
  double x, y;
  point (double x = 0, double y = 0) : x(x), y(y) {}
} a, b, c, d;
typedef point vect;
vect operator+ (const vect & a,const vect & b)
{
  return vect(a.x + b.x, a.y + b.y);
}
vect operator- (point & a, point & b)
{
  return vect(a.x - b.x, a.y - b.y);
}
vect operator* (vect &a, double p)
{
  return vect(a.x * p, a.y * p);
}
int dcmp(double x)
{
  if (fabs(x) < eps)
  {
    return 0;
  }
  return x < 0 ? -1 : 1;
}

double dot(vect & a, vect & b)
{
  return a.x * b.x + a.y * b.y;
}

double len(vect & a)
{
  return sqrt(dot(a, a));
}
double cross(vect & a, vect & b)
{
  return a.x * b.y - a.y * b.x;
}
point get_line_intersection(point & p, vect & v, point & q, vect & w)
{
  vect u = p - q;
  double t = cross(w, u) / cross(v, w);
  return p + v * t;
}

double distance_to_line(point p, point a, point b)
{
  vect v1 = b - a, v2 = p - a;
  return fabs(cross(v1, v2)) / len(v1);
}
int main(){
	puts("INTERSECTING LINES OUTPUT");
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
		scanf("%lf%lf%lf%lf", &c.x, &c.y, &d.x, &d.y);
		vect v1=b-a, v2=d-c;
		if (cross(v1, v2)){
			point t = get_line_intersection(a, v1, c, v2);
			printf("POINT %.2f %.2f\n", t.x, t.y);
		}
		else if (dcmp(distance_to_line(c, a, b)))
			puts("NONE");
		else
			puts("LINE");
	}
	puts("END OF OUTPUT");
	return 0;
}
