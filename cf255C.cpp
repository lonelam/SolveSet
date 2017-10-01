#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 4000 + 100;
int a[maxn];
vector<int> disc;
int dp[maxn][maxn];
int n;
int main()
{
  while(~scanf("%d", &n))
  {
    for (int i = 1;i <= n; i++)
    {
      scanf("%d", a + i);
      disc.push_back(a[i]);
    }
    sort(disc.begin(), disc.end());
    disc.erase(unique(disc.begin(), disc.end()), disc.end());
    for (int i = 1; i <= n; i++)
    {
      a[i] = lower_bound(disc.begin(), disc.end(), a[i]) - disc.begin();
    }
    int ans = 1;
    if (n >= 2) ans = 2;
    for (int i = 1; i <= n; i++)
    {
  //    cout << a[i] << endl;
      for (int j = 0; j < disc.size(); j++)
      {
        dp[a[i]][j] = max(dp[j][a[i]] + 1, dp[a[i]][j]);
    //    dp[a[i]][j] = max(dp[j][a[i]][1] + 1, dp[a[i]][j][0]);
      }
    }
    for (int i = 0; i < disc.size(); i++)
    {
      for (int j = 0; j < disc.size(); j++)
      {
        ans = max(ans, dp[i][j]);
      }
    }
    printf("%d\n", ans);
  }
}
