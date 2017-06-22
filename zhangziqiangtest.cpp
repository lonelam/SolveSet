#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int bit[maxn];
int dp[maxn][2];
int dfs(int len,int head, bool up)
{
  if (len == 1)
  {
    return 1;
  }
  int ans = 0;
  if (up)
  {
    for (int i = 0; i < bit[len - 2]; i++)
    {
      ans += dfs(len - 1, i, false);
    }
    if (!(head && bit[len - 2])) ans += dfs(len - 1, bit[len - 2], true);
    return ans;
  }
  else
  {
    if (dp[len][head] != -1) return dp[len][head];
      ans += dfs(len - 1, 0, false);
      if (!head)
      {
        ans += dfs(len - 1, 1, false);
      }
      return dp[len][head] = ans;
  }
}
int main()
{
  int n;
  memset(dp, -1, sizeof(dp));
  while(cin >> n)
  {
    int d = 0;
    while(n)
    {
      bit[d++] = n & 1;
      n >>= 1;
    }
  //  cout << d << endl;
    int ans = dfs(d, 1, true) + dfs(d, 0, false);
    cout << ans << endl;
  }
}
