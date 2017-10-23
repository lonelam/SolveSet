#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string s;
int dp[maxn][3];
int presum[maxn];
int main()
{
  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    presum[i+1] = presum[i] + (s[i]=='a');
  }
  memset(dp, inf, sizeof dp);
  for (int i = 0; i < s.size(); i++)
  {
    dp[i][0] = (i+1 - presum[i+1]);
    dp[i][1] = min(presum[i+1], dp[i][0]);
    for (int j = 0; j < i; j++)
    {
      dp[i][1] = min(dp[i][1], dp[j][0] + (presum[i+1] - presum[j+1]));
    }
  }
  int ans = presum[s.size()];
  for (int i = 1; i < s.size(); i++)
  {
    ans = min(ans, (int)s.size() - i - presum[s.size()] + presum[i] + dp[i-1][1]);
  }
  cout << s.size() - ans << endl;
}
