#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> factor(ll x)
{
    vector<ll> ret;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while(x % i == 0)
            {
                x /= i;
            }
            ret.push_back(i);
        }
    }
    if (x != 1) ret.push_back(x);
    return ret;
}
const int maxn = 100000 + 10;
int a[maxn];
int b[maxn];
int n;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            sum += a[i];
        }
        vector<ll> ps = factor(sum);
        ll ans = LLONG_MAX;
        for (ll x: ps)
        {
            //cout << x << endl;
            for (int i = 0; i < n; i++)
            {
                b[i] = a[i] % x;
            }
            sort(b, b + n);
            ll up = 0, down = 0;
            int L = 0, R = n;
            while(L < R)
            {
                while(up <= down && L < R)
                {
                    //cout << "up : " << L << endl;
                    up += b[L++];
                }
                while(down < up && L < R)
                {

                    down += x - b[--R];
                    //cout << "down: "<< R << endl;
                }
            }
            assert(up == down);

            ans = min(ans, up);
        }
        printf("%lld\n", ans);
    }
}
