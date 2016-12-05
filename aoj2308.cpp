#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const double g = 9.8;
const int maxn = 55;
double n, v, x, y;
double L[maxn], R[maxn], T[maxn], B[maxn];
double calc(double vy, double t)
{
    return vy * t - g * t * t / 2;
}
int cmp (double lb, double rb, double a)
{
    return a < lb + eps ? -1 : a > rb - eps ? 1 : 0;
}
bool check(double qx, double qy)
{
    double a = g * g / 4, b = g * qy - v * v, c = qx * qx + qy * qy;
    double delta = b * b - 4 * a * c;
    if(delta < 0 && delta > -eps) delta = 0;
    if(delta < 0) return false;
    double t2[2];
    t2[0] = (- b + sqrt(delta)) / (2 * a);
    t2[1] = (- b - sqrt(delta)) / (2 * a);
    for(int d = 0; d < 2; d++)
    {
        bool ans = true;
        if(t2[d] <= 0)
            continue;
        double t = sqrt(t2[d]);
        double vx = qx / t, vy = (qy + g * t * t / 2) / t;

        double yt = calc(vy, x / vx);
        if(yt < y - eps) continue;

        for(int i = 0; i < n; i++)
        {
            if(L[i] >= x)
                continue;
            if(R[i] == x && y <= T[i] && B[i] <= yt)
            {
                ans = false;
                break;
            }
            int yL = cmp(B[i], T[i], calc(vy, L[i] / vx));
            int yR = cmp(B[i], T[i], calc(vy, R[i] / vx));
            int xH = cmp(L[i], R[i], vx * (vy / g));
            int yH = cmp(B[i], T[i], calc(vy, vy / g));
            if ( xH == 0 && yH >= 0 && yL < 0)
            {
                ans = false;
                break;
            }
            if (yL * yR <= 0)
            {
                ans = false;
                break;
            }
        }
        if(ans)
        {
            //cout << "debug  "<<qx << "   " << qy<<endl;
            return true;
        }
    }

    return false;

}

int main()
{
    while(cin >> n >> v >> x >> y)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> L[i] >> B[i] >> R[i] >> T[i];
            R[i] = min(R[i], x);
        }
        bool ans = false;
        ans |= check(x, y);
        for(int i = 0; i < n; i++)
        {
            ans |= check(L[i], T[i]);
            ans |= check(R[i], T[i]);
            if(ans)
                break;
        }
        if(ans)
            cout << "Yes\n";
        else
            cout <<"No\n";
    }
}
