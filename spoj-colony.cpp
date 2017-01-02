#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;

int main()
{
    ll a, y;
    while(cin >> y >> a)
    {
        bool flip = true;

        for (ll i = y; i >= 0; i--)
        {
            if (a >> i & 1)
            {
                flip = flip;
            }
            else
            {
                flip = !flip;
            }
        }
        if (!flip)
        {
            cout << "red" << endl;
        }
        else
        {
            cout << "blue" << endl;
        }
    }
}
