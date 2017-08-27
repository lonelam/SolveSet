#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100000;
void integerDivisionValues(int n, vector<int> & res)
{
  res.clear();
  res.push_back(1);
  for (int L = 1, d = n; L <= n; )
  {
    int U = n / d;
    res.push_back(U + 1);
    L = U + 1;
    d = n / L;
  }
}
int main()
{
  int n;
  ll k;
  while(scanf("%d%lld", &n, &k)!=EOF)
  {
    vector<int> as(n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &as[i]);
    }
    sort(as.begin(), as.end());
    ll total = accumulate(as.begin(), as.end(), 0LL);
    vector<int> bounds;
    for (int x: as)
    {
      vector<int> v;
      integerDivisionValues(x-1, v);
      bounds.insert(bounds.end(), v.begin(), v.end());
    }
    sort(bounds.begin(), bounds.end());
    bounds.erase(unique(bounds.begin(), bounds.end()), bounds.end());
    ll ans = -1;
    for (int bi = 0; bi < bounds.size(); bi++)
    {
      int dL = bounds[bi];
      // ll dR = bi + 1 == bounds.size() ? infl: bounds[bi + 1] - 1;
      ll sum = 0;
      for (int x: as)
      {
        sum += (x - 1) / dL;
      }
      ll t = (k + total) / (sum + n);
      ll d = t;
      if (dL <= d)
      {
        ans = max(ans, d);
      }
    }
    printf("%lld\n", ans);
  }
}
