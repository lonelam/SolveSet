#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100000 + 190;

ll a[maxn];
ll b[maxn];
ll presum[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    presum[0] = 0;
    ll ans = INT64_MIN;
    ll oddm = -inf, evenm = 0;
    for (int i = 1; i < n; i++)
    {
        b[i] = abs(a[i] - a[i - 1]);
        if (i & 1) presum[i] = presum[i - 1] + b[i];
        else presum[i] = presum[i - 1] - b[i];
        ans = max({ans, presum[i] - evenm, oddm - presum[i]});
        if (i & 1) oddm = max(oddm, presum[i]);
        else evenm = min(evenm, presum[i]);
    }
    cout << ans << endl;

}
