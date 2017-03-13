#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
    ld cow, car, show;
    while(cin >> cow >> car >> show)
    {
        ld d1 = cow + car, d2 = cow + car - show - 1;
        ld ans1 = cow / d1 * car / d2 + car / d1 * (car - 1) /d2;
    //    ld ans2 = cow / d1 * (d2 - car) / d2 + car / d1 * (d2 - car + 1) / d2;
        printf("%.5llf\n", ans1);
    }
}
