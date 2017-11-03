
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 +10;
typedef long long ll;
ll w, l, r;
int main()
{
    while(cin >> l >> r >> w)
    {
        ll g = __gcd(r, w);
        if ((r / g - 1) * g + w > l)
        {
            cout << "DEADLOCK" << endl;
        }
        else{
            cout << "OK" << endl;
        }
    }
}
