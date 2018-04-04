#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n, m;
int a[maxn];
int b[maxn];
int main(){
  while(~scanf("%d%d", &n, &m)){
    for (int i = 0; i < n; i++){
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++){
      scanf("%d", b + i);
    }
    sort(a, a + n);
    sort(b, b + n);
    ll ans = 0;
    ll tmp = 0;
    reverse(a, a + n);
    for (int i = n - 1, j = 1; i >= 0; i--, j++){
      tmp += b[i] - a[i];
      if (j % 3 == 0){
        tmp += m;
      }
      // cout << tmp << endl;
      ans = max(ans, tmp);
    }
    printf("%lld\n", ans);
  }
}
