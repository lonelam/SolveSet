#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ld eps = 1e-6;
int lcm(int a, int b)
{
  return a / __gcd(a,b) * b;
}
int cnt[maxn];
bool flag[maxn];
bool vis[21][maxn];
int main()
{
  int T;
  int n;
  while(cin >> n)
  {
    int m = 1;
    for (int i = 2; i <= n; i<<= 1, m++);
    m--;
    for (int i = 2; i <= m; i++)
    {
      for (int j = 1; j < i; j++)
      {
        int l = lcm(i, j), len1 = l / j, len2 = l / i;
        for (int k = 1; k * len1 <= n; k++)
        {
          vis[i][k * len2] = true;
        }
      }
    }
    cnt[1] = n - 1;
    for (int i = 2; i <= m; i++)
    {
      cnt[i] = cnt[i-1];
      for (int j = 2; j <= n; j++) if (!vis[i][j]) cnt[i]++;
    }
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
      if (flag[i]) continue;
      int p = 0; ll x = i;
      do {
        flag[x] = true;
        p++;
        x *= i;
      } while(x <= n);
      ans += cnt[p];
    }
    cout << ans << endl;
  }
}
