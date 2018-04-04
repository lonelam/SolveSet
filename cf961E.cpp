#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int a[maxn];
ll seg[maxn];
int inline lsb(int x){
  return x & (-x);
}
void add(int x){
  while(x <= n + 1){
    seg[x]++;
    x += lsb(x);
  }
}
ll query(int x){
  ll ret = 0;
  while(x){
    ret += seg[x];
    x -= lsb(x);
  }
  return ret;
}
vector<int> qs[maxn];
int main(){
  while(~scanf("%d", &n)){
    memset(seg, 0, sizeof(seg));
    for (int i = 1; i <= n; i++){
      scanf("%d", a + i);
      a[i] = min(a[i], n);
      if (a[i] < i){
        qs[a[i]].push_back(i);
      }
      else{
        qs[i - 1].push_back(i);
      }
      // disc.push_back(a[i]);
    }
    // sort(disc.begin(), disc.end());
    // disc.erase(unique(disc.begin(), disc.end()), disc.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++){
      add(a[i]);
      for (int j : qs[i]){
        // cout << i << " "<<j << " "<< (i - query(j - 1)) << endl;
        ans += (ll)i - query(j-1);
      }
    }
    printf("%lld\n", ans);
  }
}
