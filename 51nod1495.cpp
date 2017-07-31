#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000000 + 10;

ll a[maxn];
int n, k;
ll T, b, c, p;
int main()
{
  while(cin >> n >> k >> T >> a[0] >> b >> c >> p)
  {
    if (k==0)
    {
      cout << (ll) n * (n+1) / 2LL << endl;
    }
    for (int i = 1; i <= n; i++)
    {
      a[i] = (a[i-1]*b+c)%p;
      // cout << a[i] << " ";
    }
    // cout << endl;
    ll L = 1, R = 0;
    int knum = 0;
    ll ans =0;
    while(knum < k && R <= n)
    {
      R++;
      if (a[R] >= T)
      {
        knum++;
      }
    }
    while(L <= R && a[L] < T)
    {
      L++;
    }
    while(R <= n)
    {
      while(knum == k && R <= n)
      {
        ans += L;
        // cout << L << " "<< R << endl;
        R++;
        if (a[R] >= T)
        {
          knum++;
        }
      }
      L++;
      knum--;
      while(L<=R && a[L] < T)
      {
        L++;
      }
    }
    cout << ans << endl;
  }
}
