#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long double ld;
int n, k;
const int inf = 0x3f3f3f3f;
ld a[10002];
int check(ld x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += floor(a[i] / x);
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> k){
        for (int i = 0; i < n; i++) cin >> a[i];
        ld l = 0.0, r = (ld)inf;
        for (int i = 0; i < 200; i++){
            ld mid = l + (r - l) / 2.0;
            if(check(mid) >= k)
                l = mid;
            else
                r = mid;
        }
        cout << fixed << setprecision(2) << (int)floor(r * 100.0) *1.0 / 100 << endl;
    }
    return 0;
}
