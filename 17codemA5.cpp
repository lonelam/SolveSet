#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;
int a[maxn];
int cnt[maxn];
int belong[maxn];
int bsize, bnum;
int n, m;
void init()
{
  bsize = sqrt(n);
  bnum = n / bsize;
  if (n % bsize) bnum++;
  for (int i = 0; i <= n; i++)
  {
    belong[i] = i / bsize;
  }
}
struct node
{
  int l, r, k, id;
  bool operator<(const node & rhs) const
  {
    if (belong[l] == belong[rhs.l])
    {
      return r < rhs.r;
    }
    else
    {
      return l < rhs.l;
    }
  }
}ns[maxn];
int ans[maxn];
int main()
{
  scanf("%d%d", &n, &m);
  {
    init();
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
    }
    for (int i = 0; i < m; i++)
    {
      ns[i].id = i;
      scanf("%d%d%d", &ns[i].l, &ns[i].r, &ns[i].k);
      ns[i].l--;
      ns[i].r--;
    }
    sort(ns, ns + m);
    int L = 0, R = -1;
    map<int, int> times;
    times[0] = n + 1;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; i++)
    {
      while(R < ns[i].r)
      {
        ++R;
        if (--times[cnt[a[R]]] == 0)
        {
          times.erase(cnt[a[R]]);
        }
        ++cnt[a[R]];
        ++times[cnt[a[R]]];
      }
      while(L > ns[i].l)
      {
        --L;
        if (--times[cnt[a[L]]] == 0)
        {
          times.erase(cnt[a[L]]);
        }
        ++cnt[a[L]];
        ++times[cnt[a[L]]];
      }
      while(L < ns[i].l)
      {
        if (--times[cnt[a[L]]] == 0)
        {
          times.erase(cnt[a[L]]);
        }
        --cnt[a[L]];
        ++times[cnt[a[L]]];
        ++L;
      }
      while(R > ns[i].r)
      {
        if (--times[cnt[a[R]]] == 0)
        {
          times.erase(cnt[a[R]]);
        }
        --cnt[a[R]];
        ++times[cnt[a[R]]];
        --R;
      }
      for (pair<int, int> elem : times)
      {
        if (elem.first && __gcd(elem.first, ns[i].k) == 1)
        {
          ans[ns[i].id] += elem.second;
        }
      }
    }
    for (int i = 0; i < m; i++)
    {
      printf("%d\n", ans[i]);
    }
  }
}
