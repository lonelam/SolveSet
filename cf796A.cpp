#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;
    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0 && a[i] <= k) ans = min(ans, abs(m - 1 - i));
    }
    cout << ans * 10 << endl;
}
