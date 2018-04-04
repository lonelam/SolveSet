#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll nex(ll x){
  ll mask = 1;
  ll ret = 0;
  ll C = 0;
  while(x){
    // mask *= 10;
    if (x % 10 < 4){
      ret = 0;
      for (ll m = 1; m < mask; m *= 10){
        ret += m * 4;
      }
      ret += mask * 4LL;
    }
    else if (x % 10 == 4){
      ret += mask * 4LL;
    }
    else if (x % 10 < 7){
      ret = 0;
      for (ll m = 1; m < mask; m *= 10){
        ret += m * 4;
      }
      ret += mask * 7LL;
    }
    else if (x % 10 == 7){
      ret += mask * 7LL;
    }
    else if (x % 10 > 7){
      ret = 0;
      for (ll m = 1; m < mask; m *= 10){
        ret += m * 4;
      }
      ret += mask * 4LL;
      C = 1;
    }
    x /= 10;
    mask *= 10;
    if (C){
      C = 0;
      x += 1;
    }
  }
  return ret;
}
int main(){
  ll L, R;
  while(cin >> L >> R){
    ll ans = (min(nex(L), R) - L + 1) * nex(L);
    for (ll cur = nex(L) + 1; cur <= R; cur = nex(cur) + 1){
      ans += nex(cur) * (min(nex(cur), R) - cur + 1);
      // cout << cur << endl;
    }
    cout << ans << endl;
  }
}
