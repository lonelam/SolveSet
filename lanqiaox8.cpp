#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n;
int x[maxn];

int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", x + i);
  }
  if (n <= 3){
    printf("0\n");
    return 0;
  }
  sort(x, x + n);
  for (int i = n - 1; i >= 0; i--){
    x[i] -= x[0];
  }
  int ans = 0;
  int mm = 0;
  int split = x[1];
  for (int i = 2; i < n; i++){
    split = __gcd(split, x[i] - x[i-1]);
  }
  for (int i = 1; i < n; i++){
    ans += (x[i] - x[i-1] - 1) / split;
    mm = max(mm, (x[i] - x[i-1] - 1) / split);
  }
  ans -= mm;
  int ans2 = 0;
  split = x[2] - x[1];
  for (int i = 3; i < n; i++){
    split = __gcd(split, x[i] - x[i-1]);
  }
  for (int i = 1; i < n; i++){
    ans2 += (x[i] - x[i-1] - 1) / split;
  }
  printf("%d\n", min(ans, ans2));
}
