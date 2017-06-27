#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 5;
const int moder = 1e9+7;
int dp[maxn][maxn];
int main()
{
  for (int i = 0; i < maxn; i++)
  {
    dp[0][i] = 1;
  }
  for (int i = 1; i < maxn; i++)
  {
    dp[i][0] = 1;
    for (int j = 1; j < maxn; j++)
    {
      dp[i][j] = (dp[i - 1][j] + dp[i][j-1])%moder;
    }
  }
  int T,n,m;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &m);
    printf("%d\n", dp[n][m]);
  }
}
