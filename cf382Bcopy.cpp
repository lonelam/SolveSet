#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

ll vis[maxn];
int main()
{
    ll a,b,w,x,c;
    cin >> a >> b >> w >> x >> c;
    if (c <= a)
    {
        cout << 0 << endl;
        return 0;
    }
    ll res = 0, cyc = 0;
    while(true)
    {
        res++, c--;
        if (b >= x) b-= x;
        else a--,b=w-(x-b);
        if (c <= a)
        {
            cout << res << endl;
            return 0;
        }
        if (vis[b])
        {
            cyc = res - vis[b];
            break;
        }
        vis[b] = res;
    }
    ll tot = 0;
    for (int i = 1; i <= cyc; i++)
    {
        res++, c--;
        if (b >= x) b-= x;
        else a--,b=w-(x-b),tot++;
        if (c <= a)
        {
            cout << res << endl;
            return 0;
        }
    }
    ll rnd = (c - a - 1) / (cyc - tot);
    c -= rnd * cyc, a -= rnd * tot, res += rnd * cyc;
    while(true)
    {
        res++,c--;
        if (b >= x) b-= x;
        else a--,b=w-(x-b);
        if (c <= a)
        {
            cout << res << endl;
            return 0;
        }
    }
    return 0;
}
