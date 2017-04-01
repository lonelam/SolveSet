#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll a[maxn];
int main()
{
    ll b,q,l,m;
    cin >> b >> q >> l >> m;
    ll abb = abs(b);
    bool zero = false, hasb = false, hasnb = false;
    set<ll> bad;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        bad.insert(a[i]);
    }
    set<ll> occur;
    ll x = b * q;
    if (abb > l)
    {
        cout << 0 << endl;
        return 0;
    }
    while(abs(x) <= l && occur.find(x) == occur.end())
    {
        occur.insert(x);
        x *= q;
    }
    if (occur.find(x) != occur.end())
    {
        for (ll oc : occur)
        {
            if (bad.find(oc) == bad.end())
            {
                cout << "inf"<< endl;
                return 0;
            }
        }
        if (bad.find(b) == bad.end()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else
    {
        ll cnt = 0;
        ll y = b;
        while(abs(y) <= l)
        {
            if (bad.find(y) == bad.end())
            {
                cnt++;
            }
            y *= q;
        }
        cout << cnt << endl;
    }
}
