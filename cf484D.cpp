#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 1000;
ll a[maxn], dp[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int la = 1;
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[la - 1] + llabs(a[i] - a[la]), dp[la] + llabs(a[i] - a[la + 1]));
            if (i < n)
            {
                if (a[i - 1] <= a[i] && a[i] >= a[i + 1]) la = i;
                if (a[i - 1] >= a[i] && a[i] <= a[i + 1]) la = i;
            }
        }
        cout << dp[n] << endl;
    }
}
