/*

4! = 4 * 3 * 2 * 1
15! = 15 * .. * 2 * 1
n! =
有 n / 2 个 2 的倍数
有 n / 4 个 4 的倍数
有 n / 8 个 8 的倍数
...

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            ll n;
            scanf("%lld", &n);
            ll ans = 0;
            for (ll i = 2; i <= n; i *= 2)
            {
                ans += n / i;
            }
            printf("%lld\n", ans);
        }
    }
}
