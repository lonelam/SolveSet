#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-10;
struct point{
	double x, y;
	point(double x=0, double y=0): x(x), y(y) {}
} a, b, c, d;
typedef point Vector;

Vector operator + (Vector a, Vector b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator - (point a, point b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x*p, a.y*p); }

int dcmp(double x){
	if (fabs(x) < eps)
		return 0;
	return x<0 ? -1 : 1;
}

double dot(Vector a, Vector b){
	return a.x*b.x+a.y*b.y;
}

double length(Vector a){
	return sqrt(dot(a, a));
}

double cross(Vector a, Vector b){
	return a.x*b.y-a.y*b.x;
}

point get_line_intersection(point p, Vector v, point q, Vector w){
	Vector u = p-q;
	double t = cross(w, u)/cross(v, w);
	return p+v*t;
}

double distance_to_line(point p, point a, point b){
	Vector v1=b-a, v2=p-a;
	return fabs(cross(v1, v2))/length(v1);	// 如果不取绝对值,得到的是有向距离
}

int main(){
	puts("INTERSECTING LINES OUTPUT");
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
		scanf("%lf%lf%lf%lf", &c.x, &c.y, &d.x, &d.y);
		Vector v1=b-a, v2=d-c;
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
