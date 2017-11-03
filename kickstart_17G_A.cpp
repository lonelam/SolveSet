#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
ll a, n, p;
int main()
{
  freopen("A-small-attempt0.in", "r", stdin);
  //freopen("out.out", "w", stdout);
  int i;
  int T;
  cin >> T;
  int kase = 1;
  while(T--)
  {
    cout << "Case #" << kase++ << ": ";
    cin >> a >> n >> p;
    if (a % p == 0)
    {
      cout << 0 << endl;
      continue;
    }
    ll mul = 1;
    int flg = true;
    ll index = 1;
    for (i = 0; flg; i++)
    {
      mul = (mul * a) % p;
      if (mul == 1)
      {i++;break;}
      if (mul == 0)
      {
        i++;
        index = 1;
        for (ll j = 1; j <= n && index < i; j++)
        {
          index = (index * j) % i;
        }
        if (index >= i)
        {
          cout << 0 << endl;
          flg = false;
          break;
        }
        else
        {
          index = 1;
          i = p;
          break;
        }
      }
    }
    if (!flg) continue;
    for (ll j = 1; j <= n; j++)
    {
      index = (index * j) % i;
    }
    ll ans = 1;
    for (ll j = 0; j < index; j++)
    {
      ans = (ans * a) % p;
    }
    cout << ans << endl;
  }
}
