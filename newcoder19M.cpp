#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
int T, n;
const int maxn = 100000  + 10;
struct point
{
    ld x, y;
    point operator - (const point & b) const
    {
        return {x - b.x, y - b.y};
    }
    point operator + (const point & b) const
    {
        return {x + b.x, y + b.y};
    }
    //cross product
    ld operator * (const point & b) const
    {
        return x * b.y - y * b.x;
    }

}ps[maxn];
const ld eps = 1e-6;
ld dis(const point & a, const point & b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
point midpoint(point & a, point & b)
{
    return {(a.x + b.x) / 2, (a.y + b.y) / 2};
}
point rotbar(point & a, point & b)
{
    point tmp = (a - b);
    swap(tmp.x, tmp.y);
    tmp.x = - tmp.x;
    return tmp;
}
struct Line
{
    point s, e;
    point operator& (const Line & b) const
    {
        point res = s;
        ld t = ((s - b.s) * (b.s - b.e)) / ((s - e) * (b.s - b.e));
        res.x += (e.x - s.x) * t;
        res.y += (e.y - s.y) * t;
        return res;
    }
};
int main()
{
    while(~scanf("%d", &T))
    {
        while(T--)
        {
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%lf%lf", &ps[i].x, &ps[i].y);
                //cout << ps[i].x << ' ' << ps[i].y << endl;
            }
            if (n == 1)
            {
                printf("%f %f %f\n", ps[0].x, ps[0].y, 0.0);
                continue;
            }
            else if (n >= 2 && n <= 4)
            {
                point tmp = midpoint(ps[0], ps[1]);
                printf("%f %f %f\n", tmp.x, tmp.y, dis(tmp, ps[0]));
                continue;
            }
            int cnt = 0;
            ld px, py, R;
            random_device rd;
            uniform_int_distribution<int> uni(0, n - 1);
            int pp[3];
            point mp[3];
            do
            {
                cnt = 0;
                set<int> vis;
                //cout << "???" <<endl;
                for (int i = 0; i < 3; i++)
                {
                    do
                    {
                        pp[i] = uni(rd);
                    }while(vis.find(pp[i]) != vis.end());
                    vis.insert(pp[i]);
                    mp[i] = ps[pp[i]];
                }

                Line l1 = {midpoint(mp[0], mp[1]),midpoint(mp[0], mp[1]) + rotbar(mp[0], mp[1])};
                Line l2 = {midpoint(mp[0], mp[2]), midpoint(mp[0], mp[2]) + rotbar(mp[0], mp[2])};
                if ((l1.s - l1.e) * (l2.s - l2.e) < eps)
                {
                    continue;
                }
                //cout << l1.s.x <<" "<< l1.s.y << "/" << l1.e.x << " "<< l1.e.y <<endl;
                point P = l1 & l2;
                R = dis(P, mp[0]);
                px = P.x;
                py = P.y;
               // cout << px << " "<< py << " "<< R << endl;
                for (int i = 0; i < n; i++)
                {
                    if (abs(dis(P, ps[i]) - R) < eps) cnt++;
                }
            }while(cnt * 2 < n);
            printf("%f %f %f\n", px, py, R);
        }
    }
}
