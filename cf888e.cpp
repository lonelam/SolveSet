#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1 << 18;
ll a[maxn];
int n;
ll m;
ll c[maxn];
int totc;
ll b[maxn];
int totb;
void dfs(ll *dis, int & tot, ll acc, int i, int up)
{
  if (i == up)
  {
    dis[tot++] = acc;
    return;
  }
  dfs(dis, tot, acc, i + 1, up);
  dfs(dis, tot, (acc + a[i])%m, i + 1, up);
}
int main()
{

  while(cin >> n >> m)
  {
    totc = totb = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    const int mid = n / 2;
    dfs(b, totb, 0, 0, mid);
    dfs(c, totc, 0, mid, n);
    sort(b, b + totb);
    sort(c, c + totc);
    ll ans = max(*max_element(b, b + totb), *max_element(c, c + totc));
    for (int i = 0; i < totb; i++)
    {
      auto tar = upper_bound(c, c + totc, m - b[i] - 1);
      if (tar != c)
      {
        --tar;
        ans = max(ans, (*tar + b[i]) % m);
      }
      ans = max(ans, (b[i] + c[totc-1]) % m);
    }
    cout << ans << endl;
  }
}
