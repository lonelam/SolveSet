#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
ll fac[16];
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
vector<int> getkth(ll n, ll k){
  vector<int> ret;
  set<int> rem;
  for (int i = 1; i <= n; i++) rem.insert(i);
  for (int i = 0; i < n; i++){
    auto iter = rem.begin() ;
    for (int j = 0; j < k / fac[n - i - 1]; j++) iter++;
    int t = *iter;
    k %= fac[n - i - 1];
    ret.push_back(t);
    rem.erase(t);
  }
  return ret;
}
int gao(ll n){
  int cnt = 0;
  for (int i = nex(i); i <= n; i = nex(i + 1)){
    cnt++;
  }
  return cnt;
}
bool islucky(ll x){
  while(x){
    if (x % 10 != 4 && x % 10 != 7){
      return false;
    }
    x /= 10;
  }
  return true;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fac[1] = 1;
  fac[0] = 1;
  for (int i = 2; i < 16; i++){
    fac[i] = fac[i-1] * i;
  }
  ll n, k;
  cin >> n >> k;
    int ans = 0;
    k--;
    if (n <= 15){
      if (k > fac[n]){
        cout << -1 << endl;
        return 0;
      }
      vector<int> rr = getkth(n, k);
      for (int i = 0; i < rr.size(); i++){
        if (islucky(rr[i]) && islucky(i+1)){
          ans++;
        }
        cout << rr[i] << " " << i+1 << " "<<endl;
      }
    }
    else{
      ans += gao(n - 15);
      vector<int> rr = getkth(15, k);
      for (int i = 0; i < rr.size(); i++){
        if (islucky(n - 15 + rr[i]) && islucky(n - 15 + i + 1)){
          ans++;
        }
      }
    }
    cout << ans << endl;
}
