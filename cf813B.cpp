#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll up = 1e18;
ll x, y, l, r;
ll sta[maxn], stb[maxn], tota, totb;
ll stc[maxn], totc;
int main()
{
  while(cin >> x >> y >> l >> r)
  {
    tota = totb = totc = 0;
    ll sx = 1, sy = 1;
    while(true)
    {
      sta[tota++] = sx;
      if (sx <= up / x)
      {
        sx *= x;
      }
      else break;
    }
    while(true)
    {
      stb[totb++] = sy;
      if (sy <= up / y)
      {
        sy *= y;
      }
      else break;
    }
    for (int i = 0; i < tota; i++)
    {
      for (int j = 0; j < totb; j++)
      {
        if (sta[i] + stb[j] >= 0 && sta[i] + stb[j] <= up) stc[totc++] = sta[i] + stb[j];
      }
    }
    //cout << totc << endl;
    stc[totc++] = l - 1;
    stc[totc++] = r + 1;
    sort(stc, stc + totc);
    totc = unique(stc, stc + totc) - stc;
    int from = lower_bound(stc, stc + totc, l - 1) - stc, to = lower_bound(stc, stc + totc, r + 1) - stc;
    ll ans = 0;
    for (int i = from; i < to; i++)
    {
      ans = max(ans, stc[i + 1] - stc[i] - 1);
    }
    cout << ans << endl;
  }
}
