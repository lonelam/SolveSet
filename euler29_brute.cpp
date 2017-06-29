#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  ll n;
  while(cin >> n)
  {
    set<ll> cnt;
    for (ll a = 2; a <= n; a++)
    {
      ll o = a;
      for (ll b = 2; b <= n; b++)
      {
        o *= a;
        if (cnt.find(o)!=cnt.end()) cout << o << endl;
        cnt.insert(o);
      }
    }
    cout << cnt.size() <<endl;
  }
}
