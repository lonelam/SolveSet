#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
ll gao(ll x, ll n){
  if (x & 1){
    return x / 2LL + 1LL;
  }
  else{
    if (n & 1)
    {
      return gao(x == 2 ? (n-1):(x -2), n - 1) + 1;
    }
    else{
      return gao(x / 2, n / 2) + n / 2;
    }
  }
}
int main(){
  ll n;
  int q;
  while(~scanf("%I64d%d", &n, &q)){
    for (int i = 0; i < q; i++){
      ll x;
      scanf("%I64d", &x);
      printf("%I64d\n", gao(x, n));
    }
  }
}
