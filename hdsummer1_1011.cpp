#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int maxn = 100000 + 100;
typedef long double ld;
typedef long long ll;
ll n, k;
int main()
{
    int kase = 1;
    while(scanf("%lld%lld", &n, &k) != EOF)
    {
        ll ans = -1;
        if (k <= n)
        {
            ans = k;
        }
        else
        {
            k -= 1;
            ll turn = k / (n-1);
            ll rem = k % (n-1);
            if (rem != 0)
            {
                ans = rem;
            }
            else if (turn & 1)
            {
                ans = n;
            }
            else
            {
                ans = n - 1;
            }
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
}
