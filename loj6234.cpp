#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
int n;
int c[maxn];
map<int,deque<int> > trail;
int mm[maxn << 2], lazy[maxn << 2];
void pushup(int r)
{
  mm[r] = min(mm[r << 1], mm[r << 1 | 1]);
}
void pushdown(int r)
{
  if (lazy[r])
  {
    lazy[r << 1] += lazy[r];
    mm[r << 1] += lazy[r];
    lazy[r << 1 | 1] += lazy[r];
    mm[r << 1 | 1] += lazy[r];
    lazy[r] = 0;
  }
}
void add(int ql, int qr, int a, int L = 0, int R = n + 1, int o = 1)
{
  if (ql <= L && R <= qr)
  {
    lazy[o] += a;
    mm[o] += a;
    return;
  }
  pushdown(o);
  const int mid = (L + R) / 2;
  if (ql < mid) add(ql, qr, a, L, mid, o << 1);
  if (mid < qr) add(ql, qr, a, mid, R, o << 1 | 1);
  pushup(o);
}

int query(int ql, int qr, int L = 0, int R = n + 1, int o = 1)
{
  if (ql <= L && R <= qr)
  {
    return mm[o];
  }
  pushdown(o);
  const int mid = (L + R) / 2;
  int ret = inf;
  if (ql < mid) ret = min(ret, query(ql, qr, L, mid, o << 1));
  if (mid < qr) ret = min(ret, query(ql, qr, mid, R, o << 1 | 1));
  return ret;
}

int main()
{
  while(~scanf("%d", &n))
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", c + i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      if (!trail[c[i]].empty())
      {
        // cout << "d1"<<endl;
        add(trail[c[i]][0], n + 1, -2);
        if (trail[c[i]].size() > 1)
        {
          // cout << "d2"<<endl;
          add(trail[c[i]][1], n + 1, 1);
          trail[c[i]].pop_back();
        }
      }
      trail[c[i]].push_front(i);
      add(i, n + 1, 1);
      // for (int j = 0; j <= i ; j++)
      // {
      //   cout << query(j, j + 1) << " ";
      // }
      // cout << endl;
      ans = max(ans, query(i, i + 1) - query(0, i + 1));
      // cout << query(i, i + 1) - query(0, i + 1) << endl;
    }
    printf("%d\n", ans);
  }
}
