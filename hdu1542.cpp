#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
struct seg
{
    double lx, rx;
    double y;
    int type;
    seg() {}
    seg(double a, double b, double c, int d) : lx(a), rx(b), y(c), type(d) {}
    bool operator< (const seg & rhs) const
    {
        return y < rhs.y;
    }
} ss[maxn];
