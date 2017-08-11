#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n, q, ans[maxn], a[maxn], last[maxn * 10];
//bit
int f[maxn];
vector<int> G[maxn];
int lsb(int x)
{
  return x & (-x);
}
void add(int k, int x)
{
  while(k <= n)
  {
    f[k] += x;
    k += lsb(k);
  }
}
int sum(int k)
{
  int ans = 0;
  while(k)
  {
    ans += f[k];
    k -= lsb(k);
  }
  return ans;
}
struct query
{
  int l, r;
} qs[maxn];
int main()
{
  while(~scanf("%d%d", &n, &q))
  {
    memset(last, 0, sizeof(last));
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
      G[i].clear();
    }
    for (int i = 1; i <= q; i++)
    {
      scanf("%d%d", & qs[i].l, &qs[i].r);
      G[qs[i].r].push_back(i);
    }
    typedef pair<int, int> pii;
    vector<pii> pre;
    for (int i = 1; i <= n; i++)
    {
      vector<pii> tmp;
      for (pii v: pre)
      {
        if (tmp.size() && __gcd(v.first, a[i]) == tmp.rbegin()->first)
        {
          *tmp.rbegin() = {tmp.rbegin()->first, v.second};
        }
        else
        {
          tmp.push_back({__gcd(v.first, a[i]), v.second});
        }
      }
      //pre.push_back({a[i], i});
      tmp.push_back({a[i], i});
      for (pii v: tmp)
      {
        if (!last[v.first] || last[v.first] < v.second)
        {
          if (last[v.first]) add(last[v.first], -1);
          last[v.first] = v.second;
          add(last[v.first], 1);
        }
      }
      swap(pre, tmp);
  //    pre = tmp;
      for (int v: G[i]) ans[v] = sum(n) - sum(qs[v].l - 1);
    }
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  }
}
