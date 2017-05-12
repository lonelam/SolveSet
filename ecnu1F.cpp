#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
inline int lsb(int x)
{
  return x & (-x);
}
int n, m, k, T;
int cnt[maxn];
bool vis[maxn];
int query(int x)
{
  int ret = 0;
  while(x)
  {
    ret += cnt[x];
    x -= lsb(x);
  }
  return ret;
}

void add(int x)
{
  while(x <= n)
  {
    cnt[x] ++;
    x += lsb(x);
  }
}

struct seg
{
  int l, r, t;
  bool operator<(const seg & rhs ) const
  {
    return r < rhs.r;
  }
} ss[maxn];
int main()
{
  while(scanf("%d", &T) != EOF)
  {
    for (int kase = 1; kase <= T; kase++)
    {
      scanf("%d%d%d", &n, &m, &k);
      memset(cnt, 0, sizeof(cnt));
      memset(vis, 0, sizeof(vis));
      int tmp;
      bool possible = true;
      for (int i = 0; i < k; i++)
      {
        scanf("%d", &tmp);
        add(tmp);
        vis[tmp] = true;
      }
      for (int i = 0; i < m; i++)
      {
        scanf("%d%d%d", &ss[i].l, &ss[i].r, &ss[i].t);
        if (ss[i].r - ss[i].l + 1 < ss[i].t)
        {
          possible = false;
        }
      }
      printf("Case %d: ", kase);
      if (!possible)
      {
        printf("-1\n" );
        continue;
      }
      sort(ss, ss + m);
      int ans = 0;
      set<int> pool;
      int pp = 1;
      for (int i = 0; i < m; i++)
      {
        while(pp <= ss[i].r)
        {
          if (!vis[pp])
          {
            pool.insert(pp++);
          }
          else
          {
            pp++;
          }
        }
        int within = query(ss[i].r) - query(ss[i].l - 1);
        if (within < ss[i].t)
        {
          int need = ss[i].t - within;
          while(need--)
          {
            vis[*pool.rbegin()] = true;
            add(*pool.rbegin());
            pool.erase(*pool.rbegin());
            ans++;
          }
        }
      }
      printf("%d\n", ans);
    }
  }
}
