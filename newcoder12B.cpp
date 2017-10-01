#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, q;
int a[maxn];
int pos[maxn];
ll sum[maxn << 2];
void pushup(int x)
{
  sum[x] = sum[x << 1] + sum[x << 1 | 1];
}
void build(int L = 1, int R = n + 1, int o  = 1)
{
  if (L + 1 == R)
  {
    sum[o] = a[a[L]];
    return;
  }
  const int mid = (L + R)  / 2;
  build(L, mid, o << 1);
  build(mid, R, o << 1 | 1);
  pushup(o);
}
void update(int q, int L = 1, int R = n + 1, int o = 1)
{
  if (L + 1 == R)
  {
    sum[o] = a[a[L]];
    return;
  }
  const int mid = (L + R) / 2;
  if (q < mid)
  {
    update(q, L, mid, o << 1);
  }
  else
  {
    update(q, mid, R, o << 1 | 1);
  }
  pushup(o);
}
ll query(int ql, int qr, int L =1, int R = n + 1, int o = 1)
{
  if (ql <= L && R <= qr)
  {
    return sum[o];
  }
  const int mid = (L + R) / 2;
  ll ret = 0;
  if (ql < mid) ret += query(ql, qr, L, mid, o << 1);
  if (mid < qr) ret += query(ql, qr, mid, R, o << 1 | 1);
  return ret;
}
int main()
{
  int T;
  while(~scanf("%d", &T))
  {
    while(T--)
    {
      memset(sum, 0, sizeof(sum));
      scanf("%d", &n);
      for (int i = 1; i <= n; i++)
      {
        scanf("%d", a + i);
    //    a[i];
        pos[a[i]] = i;
      }
      build();
      scanf("%d", &q);
      for (int i = 0; i < q; i++)
      {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
          swap(a[l], a[r]);
          update(pos[l]);
          update(pos[r]);
          update(l);
          update(r);
          pos[a[l]] = l;
          pos[a[r]] = r;
          update(pos[l]);
          update(pos[r]);
        }
        else if (op == 2)
        {
          r++;
          printf("%lld\n", query(l, r));
        }
      }
    }
  }
}
