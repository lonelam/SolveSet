#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
const ll inf = LONG_LONG_MAX;
const ll maxn = 500000 + 199;
ll a[maxn];
int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    bool uni = false;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            uni = true;
            break;
        }
    }
    if (uni)
    {
        ll mins = 0;
        ll cnt = 1;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                mins += cnt++;
            }
            else
            {
                cnt = 1;
            }
        }
        cout << mins <<" ";
    }
    else
    {
        ll mdif = inf;
        ll cnt = 0;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] < mdif)
            {
                mdif = a[i] - a[i - 1];
                cnt = 1;
            }
            else if (a[i] - a[i - 1] == mdif)
            {
                cnt++;
            }
        }
        cout << cnt <<" ";
    }
    ll leascnt = 0;
    for (int i = 0; a[i] == a[0]; i++)
    {
        leascnt++;
    }
    ll moscnt = 0;
    for (int i = n - 1; a[i] == a[n - 1]; i--)
    {
        moscnt++;
    }
    ll ans = (ll) moscnt * leascnt;
    if (a[0] == a[n - 1])
    {
        ans = n * (n - 1) / 2;
    }
    cout << ans << endl;
}
