#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 30000 + 100;
const int maxq = 100000 + 100;
int lsb(int x)
{
  return x& (-x);
}
map<ll, int> last;
int n, q;
using pii=pair<int, int>;
map<int,vector<pii> > Qs;
ll ans[maxq];
ll BIT[maxn];
int a[maxn];
void add(int x, ll a)
{
  while(x <= n)
  {
    BIT[x] += a;
    x += lsb(x);
  }
}
ll query(int x)
{
  ll ans = 0;
  while(x)
  {
    ans += BIT[x];
    x -= lsb(x);
  }
  return ans;
}
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {

    while(T--)
    {
      scanf("%d", &n);
      memset(BIT, 0, sizeof(BIT));
      last.clear();
      Qs.clear();
      for (int i = 1; i <= n; i++)
      {
        scanf("%d", a + i);
      }
      scanf("%d", &q);
      for (int i = 0; i < q; i++)
      {
        static int l, r;
        scanf("%d%d", &l, &r);
        Qs[r].push_back({i, l});
      }
      for (int i = 1; i <= n; i++)
      {
        if (last[a[i]])
        {
          add(last[a[i]], -a[i]);
        }
        last[a[i]] = i;
        add(i, a[i]);
        for (pii q: Qs[i])
        {
          ans[q.first] = query(n) - query(q.second - 1);
        }
      }
      for (int i = 0; i < q; i++)
      {
        printf("%lld\n", ans[i]);
      }
    }
  }
}
