#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int a[maxn];
int b[maxn];
int c[maxn];
int n;
int main(){
  int T;
  int kase = 1;
  while(~scanf("%d", &T)){
    while(T--){
      scanf("%d", &n);
      for (int i = 0; i < n; i++){
        scanf("%d", a + i);
        if (i & 1){
          c[i >> 1] = a[i];
        }
        else{
          b[i >> 1] = a[i];
        }
      }
      sort(c, c + n / 2);
      sort(b, b + (n - n / 2));
      for (int i = 0; i < n; i++){
        if (i & 1){
          a[i] = c[i>> 1];
        }
        else{
          a[i] = b[i>>1];
        }
      }
      int ans = -1;
      for (int i = 0; i < n - 1; i++){
        if (a[i] > a[i+1]){
          ans = i;
          break;
        }
      }
      cout << "Case #" << kase++ << ": ";
      if (ans==-1){
        cout << "OK";
      }
      else{
        cout << ans ;
      }
      cout << endl;
    }
  }
}
