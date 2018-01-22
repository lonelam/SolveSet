#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m;
int a[maxn];
int belong[maxn];
// int L[maxn], R[maxn];
int bnum, bsize;
int p_m(ll base, ll index, ll p)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret = (ret * base) % p;
    }
    index >>= 1;
    base = (base * base ) % p;
  }
  return ret;
}
struct node
{
  int l, r, p, id;
  bool operator<(const node & rhs) const
  {
    if (belong[l] != belong[rhs.l]) return l > rhs.l;
    return r < rhs.r;
  }
} ns[maxn];
void init()
{
  bsize = sqrt(m);
  bnum = (m + bsize - 1) / bsize;
  for (int i = 0; i < m; i++)
  {
    belong[i] = i / bsize;
  }
  // for (int i = 0; i < bnum; i++)
  // {
  //   L[i] = i * bsize;
  //   R[i] = (i + 1) * bsize;
  // }
  // R[bnum - 1] = m;
}
int cnt[maxn];
int ans[maxn];

int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d", &ns[i].l, &ns[i].r, &ns[i].p);
      ns[i].l--;
      ns[i].r--;
      ns[i].id = i;
    }
    init();
    sort(ns, ns + m);
    map<int,int> gwf;
    gwf[0] = accumulate(a, a + n, 0);
    int L = 0, R = -1;
    for (int i =  0; i < m; i++)
    {
      while(R < ns[i].r)
      {
        R++;
        if ((gwf[cnt[a[R]]]-=a[R]) == 0)
        {
          gwf.erase(cnt[a[R]]);
        }
        cnt[a[R]]++;
        gwf[cnt[a[R]]] += a[R];
      }
      while(L > ns[i].l)
      {
        L--;
        if ( (gwf[cnt[a[L]]]-=a[L]) == 0)
        {
          gwf.erase(cnt[a[L]]);
        }
        cnt[a[L]]++;
        gwf[cnt[a[L]]] += a[L];
      }
      while(L < ns[i].l)
      {
        if ( (gwf[cnt[a[L]]]-=a[L]) == 0)
        {
          gwf.erase(cnt[a[L]]);
        }
        cnt[a[L]]--;
        gwf[cnt[a[L]]] += a[L];
        L++;
      }
      while(R > ns[i].r)
      {
        if ( (gwf[cnt[a[R]]] -= a[R]) == 0)
        {
          gwf.erase(cnt[a[R]]);
        }
        cnt[a[R]]--;
        gwf[cnt[a[R]]] +=a[R];
        R--;
      }
      ll tot = 0;
      for (pair<int,int> p: gwf)
      {
        if (p.first == 0) continue;
        printf("%d %d\n", p.first, p.second);
        tot = tot + (p_m(2, ns[i].r - ns[i].l + 1, ns[i].p) - p_m(2, ns[i].r - ns[i].l + 1 - p.first , ns[i].p) + ns[i].p) % ns[i].p * (ll)p.second % ns[i].p;
        tot %= ns[i].p;
      }
      ans[ns[i].id] = tot;
      // printf("%lld\n", tot);
    }
    for (int i = 0; i < m; i++)
    {
      printf("%d\n", ans[i]);
    }
  }
}
