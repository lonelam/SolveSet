#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
using namespace std;
const ll moder = 1e9 + 7;

int n, m, X;
ll dp[2][320][320];
int main()
{
  int i, j, x;
  cin >> n >> m >> X;
  x--;
  if (n > m)
  {
    cout << 0 << endl;
    return 0;
  }
  dp[0][0][0] = 1;
  X--;
  for (x = 0; x < m; x++)
  {
    int cur = x % 2, nex = (x + 1) % 2;
    for (i = 0; i < n + 1; i++)
    {
      for (j = 0; j < n + 1; j++)
      {
        dp[nex][i][j] = 0;
      }
    }
    for (i = 0; i < n + 1; i++)
    {
      for (j = 0; j <= i; j++)
      {
        if (x != X) dp[nex][i][j] = (dp[cur][i][j] + dp[nex][i][j]) % moder;
        if(i)dp[nex][i][j] = (dp[cur][i-1][j] + dp[nex][i][j]) % moder;
        if(j && x != X)dp[nex][i][j] = (dp[cur][i][j-1] + dp[nex][i][j]) % moder;
        if(i&&j)dp[nex][i][j] = (dp[cur][i-1][j-1] + dp[nex][i][j]) % moder;
      }
    }
  }
  ll ans = dp[m % 2][n][n];
  for (ll a = 1; a <= n; a++)
  {
    ans = (ans * a) % moder;
  }
  cout << ans << endl;
}
