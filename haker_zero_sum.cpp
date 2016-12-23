#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 100;
ll p[maxn];
ll sg(ll xx)
{
    if (xx == 0)
        return 0;
    if (xx & 1)
        return xx + 1;
    else
        return xx - 1;
}
int main()
{
    int T;
    ll n;
    while(cin >> T)
    {
        while(T--)
        {
            cin >> n;
            ll nimsum = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> p[i];
                nimsum ^= sg(p[i]);
            }

            if (nimsum != 0)
            {
                cout << "W\n";
            }
            else
            {
                cout << "L\n";
            }
        }
    }
}
