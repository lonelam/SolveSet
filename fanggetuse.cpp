#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int dp[maxn];
int main()
{
  dp[]
  for (int i = 3; i < 80; i++)
  {
    dp[i] = dp[i - 2] * 2 + dp[i - 1];
  }
  int n;
  while(cin >> n)
  {
    cout << dp[n] << endl;
  }
}
