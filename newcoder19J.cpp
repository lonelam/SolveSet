#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll moder = 1e9 + 7;
ll p_m(ll base, ll index)
{
    ll ret = 1;
    while(index)
    {
        if (index &1)
        {
            ret = (ret * base) % moder;
        }
        index >>= 1;
        base = (base * base) % moder;
    }
    return ret;
}

int main()
{
    ll rev4 = p_m(4, moder - 2);
    ll rev8 = p_m(8, moder - 2);
    //cout << (875000008 * 4LL * 2LL) % moder<< endl;
    int T;
    scanf("%d", &T);
    int n, d;
    while(T--)
    {
        scanf("%d%d", &n, &d);
        if (d == 1)
        printf("%lld\n", (rev4 *(n + 2) % moder));
        else if (d == 2)
        {
            printf("%lld\n", ((rev8 * (n) % moder * (n + 1) ) % moder));
        }
    }
}
