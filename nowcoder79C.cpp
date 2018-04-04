#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m;
int dp[maxn][11][2];
char s[maxn];
int main(){
  while(~scanf("%d%d", &n, &m)){
    memset(dp, 0, sizeof(dp));
    scanf("%s", s);
    int firsta = -1;
    for (int i = 0; i < n; i++){
      if (s[i] == 'a'){
        firsta = i;
        break;
      }
    }
    if (firsta == -1){
      printf("0\n");
      continue;
    }
    dp[firsta][0][0] = 0;
    dp[firsta][0][1] = -inf;
    for (int i = firsta; i < n; i++){
      for (int j = 0; j <= m; j++)
      {
        if (s[i] == 'a'){
          dp[i+1][j][0] = dp[i][j][0] + 1;
          if (j)
          {
            dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j - 1][1] + 1);
          }
          dp[i+1][j][1] = dp[i][j][1];

        }
        else{
          dp[i+1][j][1] = dp[i][j][1] + 1;
          if (j){
            dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j-1][0] + 1);
          }
          dp[i+1][j][0] = dp[i][j][0];
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++){
      ans = max(ans, dp[n][i][0]);
      ans = max(ans, dp[n][i][1]);
    }
    printf("%d\n", ans);
  }
}
