#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
    int n, m;
    cin >> n >> m;
    int l = m + 1, r = n;
    if (l > r)
    {
        cout << n << endl;
        return 0;
    }
    while(l + 1 < r)
    {
        const int mid = (l + r) / 2;
        if (n - (mid - m)* ( mid - m - 1) / 2 + m > mid)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << endl;
}
