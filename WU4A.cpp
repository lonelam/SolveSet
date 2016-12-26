#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1000000 + 10;
ll dp[maxn];

int main()
{
    ios::sync_with_stdio(false);
    const ll UB = 1e12 + 1;
    dp[0] = 0;
    int n;
    for (int i = 1;; i++)
    {
        dp[i] = dp[i - 1] + 2LL * i + 1LL;
        if (dp[i] > UB)
        {
            n = i;
            break;
        }
    }
    int t;

    cin >> t;
    ll xx;
    for (int i = 1; i <= t; i++)
    {
        cin >> xx;
        int pos = upper_bound(dp, dp + n, xx) - dp - 1;
        cout << "Case "<< i << ": " << pos << endl;
    }
}
