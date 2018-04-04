#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int k, n;
int a[maxn];
int t[maxn];
int main(){
  while(~scanf("%d%d", &n, &k)){
    int res = 0;
    int base = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++){
      scanf("%d", t + i);
      if (t[i]){
        base += a[i];
      }
    }
    for (int i = 0; i < k; i++){
      if (!t[i]){
        res += a[i];
      }
    }
    ans = max(ans, res);
    for (int i = k; i < n; i++){
      if (!t[i-k]) res -= a[i - k];
      if (!t[i]) res += a[i];
      ans = max(ans, res);
    }

    printf("%d\n", ans + base);
  }
}
