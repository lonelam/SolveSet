#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 100;
int dp[maxn];
int main()
{
  dp[1] = 0;
  dp[2] = 1;
  for (int i = 3; i < maxn; i++)
  {
    dp[i] = (i-1)*(dp[i-2] + dp[i-1]);
  }
  ll n, k;
  while(cin >> n >> k)
  {
    
  }

}
