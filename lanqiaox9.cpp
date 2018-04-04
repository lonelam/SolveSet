#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300 + 10;
// map<tuple<int,int,int>,ll > mem;
ll mem[maxn][maxn][maxn];
ll f(int n, int k, int m){
  ll ans = 0;
  if (n == 0){
    return 1;
  }
  if (k * m < n){
    return 0;
  }
  if (mem[n][k][m] != -1){
    return mem[n][k][m];
  }
  for (int i = 0; i * m <= n && i <= k; i++){
    ans += f(n - i * m, k - i, m - 1);
  }
  return mem[n][k][m] = ans;
}
int n, K;
int main(){
  memset(mem, -1, sizeof(mem));
  scanf("%d%d", &n, &K);
  printf("%lld\n", f(n, K, n));
}
