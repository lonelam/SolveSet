#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
int main(){
  while(cin >> n)
  {
    double r[6];
    cin >> r[1] >> r[2] >> r[3] >> r[5];
    r[0] = 0;
    double dp[25] = {0,};
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
      dp[i] = max(dp[i], dp[i-1] * (1 + r[1]));
      if (i >= 2){
          dp[i] = max(dp[i], dp[i-2] * pow(1 + r[2], 2));
      }
      if (i >= 3){
          dp[i] = max(dp[i], dp[i-3] * pow(1 + r[3], 3));
      }
      if (i >= 5){
          dp[i] = max(dp[i], dp[i-5] * pow(1 + r[5], 5));
      }
    }
    printf("%.5f\n", dp[n]);
  }
}
