#include <iostream>
using namespace std;

typedef long long ll;
ll l, r, x, y, k;
bool check()
{
    for (ll i = max(k * x, l)+1; i < min(k * y, r); i++)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> l >> r >> x >> y >> k;
    if (check())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
