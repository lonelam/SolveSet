#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T, D;
string p;
ll calc(){
  ll cur = 1;
  ll ret = 0;
  for (int i = 0; i < p.size(); i++)
  {
    if (p[i] == 'C'){
      cur <<= 1;
    }
    else if (p[i] == 'S'){
      ret += cur;
    }
  }
  return ret;
}
bool shrink(){
  // cout << p << endl;
  while(!p.empty() && p.back() == 'C'){
    p.pop_back();
  }
  int lc = -1;
  for (int i = p.size() - 1; i >= 0; i--){
    if (p[i] == 'C'){
      lc = i;
      break;
    }
  }
  if (lc == -1){
    return false;
  }
  swap(p[lc], p[lc + 1]);
  return true;
}
int main(){
  int kase = 1;
  while(cin >> T){
    while(T--){
      cin >> D >> p;
      int ans = 0;
      ll cb = calc();
      while(cb > D){
        if (shrink()){
          cb = calc();
          ans++;
        }
        else{
          ans = -1;
          break;
        }
      }
      if (ans == -1)
      cout << "Case #" << kase++ << ": IMPOSSIBLE" << endl;
      else
      cout << "Case #" << kase++ << ": " << ans << endl;

    }
  }
}
