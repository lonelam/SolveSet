#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
pair<ll,ll> dp[10][20][2][400];
ll digits[20];
ll sig[2] = {1, -1};
const ll moder = 1e9 + 7;
ll k, L, R;
pair<ll,ll> dfs(int head, int digitnum, int sign, int sum, bool up)
{
  if (digitnum == 1)
  {
    return {200 + k == sum, (200 + k == sum) * head};
  }
  pair<ll, ll> ret = {0, 0};
  if (up)
  {
    for (int i = 0; i < digits[digitnum - 2]; i++)
    {
      pair<ll,ll> tmp = dfs(i, digitnum - 1, sign ^ 1, sum + sig[sign] * i, false);
      ret.first = (ret.first + tmp.first) % moder;
      ret.second = (ret.second + tmp.second) % moder;
    }
    pair<ll, ll> t2 = dfs(digits[digitnum - 2], digitnum - 1, sign ^ 1, sum + sig[sign] * digits[digitnum-2], true);
    ret.first = (ret.first + t2.first) % moder;
    ret.second = (ret.second + ret.second) % moder;
    return ret;
  }
  if (dp[head][digitnum][sign][sum] != -1) return dp[head][digitnum][sign][sum];
  for (int i = 0; i < 10; i++)
  {
    ret = (ret + dfs(i, digitnum - 1,sign ^ 1, sum + sig[sign] * i, false)) % moder;
  }
  return dp[head][digitnum][sign][sum] = ret;
}
ll calc(ll x)
{
  if (x == 0) return 1;
  int dnum = 0;
  while(x)
  {
    digits[dnum++] = x % 10;
    x /= 10;
  }
  ll ret = 0;
  for (int i = 1; i < digits[dnum - 1]; i++)
  {
    ret = (ret + dfs(i, dnum, 1, i + 200, false)) % moder;
  }
  ret = (ret + dfs(digits[dnum-1], dnum, 1, digits[dnum-1] + 200, true)) % moder;
  while(--dnum)
  {
    for (int i = 1; i < 10; i++)
    {
      ret = (ret + dfs(i, dnum, 1, i + 200, false)) % moder;
    }
  }
  return ret;
}
int main()
{
  memset(dp, -1, sizeof(dp));
  cin >> L >> R >> k;
  ll ans = calc(R);
  if (L) ans = (ans - calc(L - 1) + moder) % moder;
  cout << ans << endl;
}
