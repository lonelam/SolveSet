#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 7;
int n;
typedef long double ld;
ld m;
ld k;
ld a[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m >> k)
    {
        m /= 3.6;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] /= 3.6;
        }

        ld mx = *max_element(a + 1, a+ n + 1);
        ld mn = *min_element(a + 1, a + n + 1);
        if (n == 0)
        {
            mx = mn = 0;
        }
        mx = max(0.0L, mx);
        mn = min(0.0L, mn);
        cout << ceill((k) / (mx + m)) << " "<<ceill((k ) / (mn  + m))<< endl;
    }
}
