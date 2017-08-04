#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = LLONG_MAX;
const int maxn = 200000 + 100;
ll a[maxn];
ll k;
int n;
int check()
{
  for (int i = 0; i < n; i++)
  {
    if (a[i] >= k)
    {
      return 1;
    }
  }
  return 0;
}
ll add(ll a, ll b)
{
  if (inf - a <= b)
  {
    return inf;
  }
  return a + b;
}
ll mult(ll a, ll b)
{
  if (inf / a < b)
  {
    return inf;
  }
  return a * b;
}
int check2(ll x)
{
  ll cur = 0;
  ll now = 1;
  for (int i = 0; i < n; i++)
  {
    if (i != 0)
    {
      now = mult(now, x + i);
      if (now != inf)now /= i;
    }
    cur = add(cur, mult(now, a[i]));
  }
  if (cur >= k)
  {
    return 1;
  }
  return 0;
}

int main()
{
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", a + i);
  }
  int st = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != 0)
    {
      st = i;
      break;
    }
  }
  rotate(a, a + st, a + n);
  n -= st;
  if (check())
  {
    cout << 0 << "\n";
    return 0;
  }
  if (n >= 5)
  {
    for (int i = 0; ; i++)
    {
      if (check())
      {
        cout << i << "\n";
        return 0;
      }
      for (int i = 0; i < n - 1; ++i)
      {
        a [i + 1] += a[i];
      }
    }
  }
  else
  {
    reverse(a, a + n);
    ll r = 2e18;
    ll l = -1;
    while(r - l > 1)
    {
      ll mid = (l + r) / 2;
      if (check2(mid))
      {
        r = mid;

      }
      else
      {
        l = mid;
      }
    }
    cout << r + 1 << endl;
  } return 0;
}
