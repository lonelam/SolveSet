#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 +100;
typedef long long ll;

struct node
{
    ll x, y, val;
    bool operator<(const node & rhs) const
    {
        if (!y) return x > 0;
        if (!rhs.y) return rhs.x > 0;
        if (y * rhs.y > 0) return x * rhs.y - y * rhs.x > 0;
        return x * rhs.y - y * rhs.x < 0;
    }
}ns[maxn];
int n;
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld", &ns[i].x, &ns[i].y, &ns[i].val);
    }
    sort(ns, ns +n);
    ll lsum = 0;
    ll tsum = 0;
    ll ans = 0;
    ll rsum = 0;
    for (int i = 0; i < n ; i++)
    {
        if (ns[i].y > 0 || ns[i].y == 0 && ns[i].x > 0)
        {
            tsum += lsum * ns[i].val;
            rsum += ns[i].val;
        }
        else
        {
            tsum += rsum * ns[i].val;
            lsum += ns[i].val;
        }
    }
    ans = max(ans, tsum);
    for (int i = 0; i < n; i++)
    {
        if (ns[i].y > 0 || ns[i].y == 0 && ns[i].x > 0)
        {
            tsum -= lsum * ns[i].val;
            rsum -= ns[i].val;
            lsum += ns[i].val;
            tsum += rsum *ns[i].val;
        }
        else
        {
            tsum -= rsum * ns[i].val;
            lsum -= ns[i].val;
            rsum += ns[i].val;
            tsum += lsum * ns[i].val;
        }
        ans = max(ans, tsum);
    }
    printf("%lld\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        solve();
    }
}
