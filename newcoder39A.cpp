#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll ans = 0;
    ll n;
    cin >> n;
    ll i;
    for (i = 1; i * i < n; i++)
    {
        ans += n / i;
        ans += i * (n / i - n / (i+1));
    }
    if (i * i == n)
    {
        ans += n / i;
    }
    cout << ans << endl;
}
