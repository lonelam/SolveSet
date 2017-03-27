#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    int m, n;
    cin >> n;
    int l, r;
    int lefta = -1, leftb = -1, righta = 2e9, rightb= 2e9;
    for (int i = 0; i < n ; i++)
    {
        cin >> l >> r;
        lefta = max(l, lefta);
        righta = min(r, righta);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        leftb = max(l, leftb);
        rightb = min(r, rightb);
    }
    int ans = 0;
    if (leftb > righta)
    {
        ans = max(leftb - righta, ans);
    }
    if (lefta > rightb)
    {
        ans = max(ans, lefta - rightb);
    }
    cout << ans << endl;
}
