#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9+5;
const int MAXN = 1e6+5;
const int MOD = 1e4+7;
const double eps = 1e-7;
const double PI = acos(-1);
using namespace std;
LL quick_mod(LL a, LL b, LL c)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans*a)%c;
        // b>>=1;
        a = (a*a)%c;
    }
    return ans;
}
LL fac[MAXN];
void Get_Fac(LL m)///m!
{
    fac[0] = 1;
    for(int i=1; i<=m; i++)
        fac[i] = (fac[i-1]*i) % m;
}
LL Lucas(LL n, LL m, LL p)
{
    LL ans = 1;
    while(n && m)
    {
        LL a = n % p;
        LL b = m % p;
        if(a < b)
            return 0;
        ans = ( (ans*fac[a]%p) * (quick_mod(fac[b]*fac[a-b]%p,p-2,p)) ) % p;
        n /= p;
        m /= p;
    }
    return ans;
}
int main()
{
    LL n, m, p;
    p = 1e4 + 7;
    Get_Fac(p);
    while(cin >> n)
    {
      m = n - 1;
      n = m * 2;
      LL inv = quick_mod(m + 1, p - 2, p);
      // cout << inv << endl;
      cout << 2LL * inv * Lucas(n, m, p) % p << endl;
    }
    // Get_Fac(p);
    // Lucas(n, m, p);///C(n,m)%p
    return 0;
}
