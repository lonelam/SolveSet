#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 100;
int w[maxn], s[maxn];
bool vis[maxn];
  int n;
bool check(ll tar)
{
  ll rem = accumulate(w, w + n, 0);
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++)
  {
    int mx = -1;
    for (int j = 0; j < n; j++)
    {
      if (!vis[j] && rem - w[j] - s[j] <= tar && (mx == -1 || w[j] > w[mx]))
      {
        mx = j;
      }
    }
    if (mx == -1)
    {
      return false;
    }
    vis[mx] = true;
    rem -= w[mx];
  }
  return true;
}
int main()
{
  freopen("shu1790.in", "r", stdin);
  while(scanf("%d", &n) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", w + i, s + i);
    }
    ll L = -1000000001, R = 1000000001;
    while(L + 1 < R)
    {
      const ll mid = (R + L )/ 2;
//      cout << L << "  "<< R << endl;
      if (check(mid))
      {
        R = mid;
      }
      else
      {
        L = mid;
      }
    }
    printf("%lld\n", R);
  }
}
