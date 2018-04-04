#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int main(){
  int n, ans = 0;
  cin >> n;
  while(n){
    ans += (n /= 5);
  }
  cout << ans << endl;
}
