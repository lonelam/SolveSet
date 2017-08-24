#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 10;
const ll moder = 1e9 + 7;
ll C[maxn][maxn];
void init()
{
  C[1][1] = C[1][0] = 1;;
  for (int i = 2; i < maxn; i++)
  {
    C[i][0] = 1;
    C[i][1] = i;
    for (int j = 2; j <= i; j++)
    {
      C[i][j] = (C[i-1][j-1] + C[i-1][j])%moder;
    }
  }
}
ll p_m(ll base, ll index)
{
  if (base == 0) return 0;
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret *= base;
      ret %= moder;
    }
    base *= base;
    base %= moder;
    index >>= 1;
  }
  return ret;
}
ll n, m;
ll dp[maxn];
ll solve()
{
  memset(dp,0,sizeof(dp));
  ll ans = 0;
  dp[1] = 1;
  for (int i = 2; i < m; i++)
  {
    dp[i] = p_m(i, n);
    for (int j = 1; j < i; j++)
    {
      dp[i] += moder - dp[j] * C[i][j] % moder;
      dp[i] %= moder;
    }
  }
  for (int i = 1; i <= min(n, m); i++)
  {
    ans = (ans + dp[i] * C[m][i] % moder * p_m(m-i, n) % moder) % moder;
  }
  return ans;
}
int main()
{
  init();
  // for (int i = 1; i <= 10; i++)
  // {
  //   for (int j = 0; j <= 10; j++)
  //   {
  //     cout << C[i][j] <<" ";
  //   }
  //   cout << endl;
  // }
  int T;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while(cin >> T)
  {
    while(T--)
    {
      cin >> n >> m;
      cout << solve() << endl;
    }
  }
}
