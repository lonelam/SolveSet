#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, k;
int t[maxn], a[maxn];
ll presum[maxn];
int q;
ll ans[maxn];
ll cnt[maxn];
int bsize;
void init()
{
  bsize = sqrt(n+1);
}
struct node
{
  int l, r, id;
  bool operator<(const node & rhs) const
  {

    if (l /bsize != rhs.l / bsize) return l / bsize < rhs.l / bsize; return r < rhs.r;
  }
}ns[maxn];
ll subk[maxn], addk[maxn], discid[maxn];
vector<ll> disc;
int main()
{
  scanf("%d%d",&n, &k);
  init();
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", t + i);
  }
  disc.push_back(0);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", a + i);
    if (t[i] == 2) a[i] = -a[i];
    presum[i] = presum[i-1] + a[i];
    disc.push_back(presum[i]);
  }
  sort(disc.begin(), disc.end());
  for (int i = 0; i <= n; i++)
  {
    discid[i] = lower_bound(disc.begin(), disc.end(), presum[i]) - disc.begin();
    auto f = lower_bound(disc.begin(), disc.end(), presum[i] + k);
    if (f != disc.end() && *f == presum[i]+k)
    {
      addk[i] = f - disc.begin();
    }
    else
    {
      addk[i] = -1;
    }
    f = lower_bound(disc.begin(), disc.end(), presum[i]- k);
    if (f != disc.end() && *f == presum[i]-k)
    {
      subk[i] = f - disc.begin();
    }
    else
    {
      subk[i] = -1;
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    scanf("%d%d", &ns[i].l, &ns[i].r);
    ns[i].id = i;
  }
  sort(ns, ns + q);
  //  reverse(ns, ns + q);
  int L = 1, R = 0;
  ll tot = 0;
  cnt[discid[0]] = 1;
  for (int i = 0; i < q; i++)
  {
    while(R < ns[i].r)
    {
      ++R;
      if (subk[R] != -1)
      {
        tot += cnt[subk[R]];
      }
      ++cnt[discid[R]];
    }
    while(L > ns[i].l)
    {
      --L;
      // if (cnt.find(presum[L-1] + k) != cnt.end())
      if (addk[L-1] != -1)
      {
        tot += cnt[addk[L-1]];
      }
      ++cnt[discid[L-1]];
    }
    while(L < ns[i].l)
    {
      --cnt[discid[L-1]];
      if (addk[L-1] != -1)
      {
        tot -= cnt[addk[L-1]];
      }
      ++L;
    }
    while(R > ns[i].r)
    {
      --cnt[discid[R]];
      if (subk[R] != -1)
      {
        tot -= cnt[subk[R]];
      }
      --R;
    }
    ans[ns[i].id] = tot;
  }
  for (int i = 0; i < q; i++)
  {
    printf("%lld\n",ans[i]);
  }
}
