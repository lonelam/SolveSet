#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200;
ld dp[maxn];
ld a[maxn];
int main()
{
    int T;
    int kase = 1;
    cout.setf(cout.fixed);
    cout.precision(10);
    while(cin >> T)
    {
        int n;
        while(T--)
        {
            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                cin >> a[i];
            }
            dp[n] = a[n];
            for (int i = n - 1; i >= 1; i--)
            {
                int x = min(n - i, 6);
                dp[i] = a[i];
                for (int k = 1; k <= x; k++)
                {
                    dp[i] += dp[i + k]/x;
                }
            }
            cout << "Case "<< kase++ << ": "<<dp[1] << endl;
        }
    }
}
