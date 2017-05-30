#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 2520;

ll lcm(ll x, ll y)
{
    return x / __gcd(x, y) * y;
}
ll dp[20][1 << 8][2520];
int digit[20];
ll dfs(int l, int s, int rem, bool flg)
{
    if (l <= 0)
    {
        for (int i = 2; i < 10; i++)
        {
            if ((s >> (i - 2) & 1) && (rem % i)) return 0;
        }
        return 1;
    }
    if (!flg && ~dp[l][s][rem] ) return dp[l][s][rem];
    ll ret = 0;
    int last = !flg ? 9 : digit[l - 1];
    for (int i = 0; i <= last; i++)
    {
        if (i >= 2)
            ret += dfs(l - 1, s | (1 << (i - 2)), (rem * 10 + i) % mod, flg && i == last);
        else
            ret += dfs(l - 1, s , (rem * 10 + i) % mod, flg && i == last);
    }
    if (!flg) dp[l][s][rem] = ret;
    return ret;
}
ll L, R;
ll calc(ll x)
{
    //memset(dp, -1, sizeof(dp));
    ll rx = x;
    int i = 0;
    while(x)
    {
        digit[i++] = x % 10;
        x /= 10;
    }
    return dfs(i, 0, 0, true);
}
int main()
{
    int t;

    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    while(cin >> t)
    {
        while(t--)
        {
            cin >> L >> R;
          //  cout << calc(L - 1) <<" " << calc(R) << endl;
            cout << calc(R) - calc(L - 1) << endl;
        }
    }
}

