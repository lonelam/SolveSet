#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    if(a < b)
    {
        return lcm(b, a);
    }
    return a / gcd(a, b) * b;
}
int main()
{
    int n;
    int t;
    while(cin >> t)
    {
        while(t--)
        {
            cin >> n;
            ll cur;
            ll ans = 1;
            for(int i = 0; i < n; i++)
            {
                cin >> cur;
                ans = lcm(ans, cur);
            }
            cout << ans<<endl;
        }
    }
}
