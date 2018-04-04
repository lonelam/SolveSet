#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int L, R, A;
int main(){
  cin >> L >> R >> A;
  int ans = L + R + A;
  int diff = abs(L - R);
  if (diff <= A)
  {
    ans = ans / 2 * 2;
  }
  else
  {
    ans = min(L + A, R + A) * 2;
  }
  cout << ans << endl;
}
