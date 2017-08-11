

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

int mu[maxn], sum[maxn], primes[maxn], ptot = 0;
bool nprime[maxn];
int a, b, c, d, k;
void init()
{
    mu[1] = 1;
    nprime[1] = true;
    for (int i = 2; i < maxn; i++)
    {
        if (!nprime[i])
        {
            primes[ptot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < ptot && i * primes[j] < maxn; j++)
        {
            nprime[i * primes[j]] = true;
            if (i % primes[j]==0)
            {
                mu[i * primes[j]] = 0;
                break;
            }
            else mu[i * primes[j]] = -mu[i];

        }
    }
}
ll calc(int n, int m, int d)
{
    ll ans = 0;
    n /= d;
    m /= d;
    int up = min(n, m);
    for (int i = 1; i <= up; i++)
    {
        ans += mu[i] * (ll)(n/i) * (ll)(m/i);
    //    cout << mu[i] * (n/i) * (m/i) << endl;
    }
    ll ans2 = 0;
    for (int i = 1; i <= up; i++)
    {
        ans2 += mu[i] * (ll)(up/i) * (ll)(up/i);
  //      cout << mu[i] * (up/i) * (up/i) << endl;
    }
    return ans - ans2 / 2LL;
}
int main()
{
    init();
    int n;
    while(cin >> n)
    {
        for (int kase = 1; kase <= n; kase++)
        {
            cin >> a >> b >> c >> d >> k;
            ll ans = 0;
            if (k) ans = calc(b, d, k) - calc(b, c - 1, k) - calc(a - 1, d, k) + calc(a-1,c-1,k);
            cout << "Case "<<kase<<": "<<ans << endl;
        }
    }
}
