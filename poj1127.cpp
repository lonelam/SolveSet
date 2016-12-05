#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

#include<vector>
using namespace std;

double eps = 1e-10;
const int maxn = 1005;
const int maxm = 1005;
double add(double a, double b)
{
    if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
    return a + b;
}

struct P
{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y){}
    P operator+ (P p)
    {
        return P(add(x, p.x), add(y, p.y));
    }
    P operator- (P p)
    {
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator* (double d)
    {
        return P(x * d, y * d);
    }
    double dot(P p)
    {
        return add(x * p.x, y * p.y);
    }
    double cross(P p)
    {
        return add(x * p.y, -y * p.x);
    }
};
bool on_seg(P & p1, P & p2, P & q)
{
    return (p1 - q).cross(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
P intersection(P & p1, P & p2, P & q1, P & q2)
{
    return p1 + (p2 - p1) * ((q2 - q1).cross(q1 - p1) / (q2 - q1).cross(p2 - p1));
}
int n;

P p[maxn], q[maxn];
int m;
int a[maxm], b[maxm];

bool g[maxn][maxn];

void solve()
{

    for(int i = 0;i < n; i++)
    {

        g[i][i] = true;
        for(int j = 0; j < i; j++)
        {

            if((p[i] - q[i]).cross(p[j] - q[j]) == 0)
            {
                g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j]) || on_seg(p[i], q[i], q[j]) || on_seg(p[j], q[j], p[i]) || on_seg(p[j],q[j], q[i]);
            }
            else
            {
                P r = intersection(p[i], q[i], p[j], q[j]);
                g[i][j] = g[j][i] = on_seg(p[i], q[i], r) && on_seg(p[j], q[j], r);
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        cout << g[a[i] - 1][b[i] - 1] ? "CONNECTED\n" : "NOT CONNECTED\n";
    }
}

