#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll upk = sqrt(a[0]);
    ll ans = 3e18;
    for (int k = 1; k <= upk; k++)
    {
        ll cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] / k >= a[i] % k)
            {
                cnt += min(a[i] / k, (a[i] / (k + 1) + ((a[i] % (k + 1) ? 1 : 0))));
            }
            else
            {
                cnt = 3e18;
                break;
            }
        }
        ans = min(ans, cnt);
    }
    for (int k = 1; k <= upk; k++)
    {
        ll cnt = 0, c2 = 0;
        ll size = a[0] / k;
        for (int i = 0; i < n; i++)
        {
            if (a[i] / size >= a[i] % size)
            {
                cnt += min(a[i] / size, (a[i] / (size + 1) + (a[i] % (size + 1) ? 1 : 0)));
            }
            else
            {
                cnt = 3e18;
                break;
            }
        }
        ans = min(ans, cnt);
        if (size > 1)
        {
            cnt = 0;
            size--;
            for (int i = 0; i < n; i++)
            {
                if (a[i] / size >= a[i] % size)
                {
                    cnt += min(a[i] / size, (a[i] / (size + 1) + (a[i] % (size + 1) ? 1 : 0)));
                }
                else
                {
                    cnt = 3e18;
                    break;
                }
            }
        ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
}
