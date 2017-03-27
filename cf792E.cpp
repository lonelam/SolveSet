#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll a[maxn];

int main()
{
    ll n;
    cin >> n;
    ll L = 1, R = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        R = max(a[i], R);
    }
    R++;
    while(L + 1< R)
    {
        const ll mid = L + (R - L)/ 2;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % mid > a[i] / mid)
            {
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            R = mid;
        }
        else
        {
            L = mid;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += a[i] / L;
    }
    cout << cnt << endl;
}
