#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
int main()
{
    ll T;
    while(cin >> T)
    {
        while(T--)
        {
            ll n;
            cin >> n;
            ll xxx;
            ll sum = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> xxx;
                sum += xxx;
            }
            if (sum % n)
            {
                cout << n - 1 << endl;
            }
            else
            {
                cout << n << endl;
            }
        }
    }
}
