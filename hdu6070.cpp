#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ld eps = 1e-5;
int n;
int a[maxn];
ld mid, L, R;
ld seg_min[maxn <<2], seg_lazy[maxn << 2];
void pushup(int x)
{
  seg_min[x] = max(seg_min[x << 1], seg_min[x << 1 | 1]);
}
void update(int x, int tar)
{
  seg_lazy[x] += tar;
  seg_min[x] += tar;
}
void pushdown(int x)
{
  if (seg_lazy[x] != 0)
  {
    update(x << 1, seg_lazy[x]);
    update(x << 1 | 1, seg_lazy[x]);
    seg_lazy[x] = 0;
  }
}
void add(int ql, int qr, int tar, int L = 0, int R = n + 1, int o = 1)
{
  if (ql <= L && R <= qr)
  {
    update(o, tar);
    return;
  }
  const int md = (L + R) / 2;
  pushdown(o);
  if (ql < md) add(ql, qr, tar, L, md, o << 1);
  if (md < qr) add(ql, qr, tar, md, R, o << 1 | 1);
  pushup(o);
}
void init(int L = 0, int R = n + 1, int o = 1)
{
  seg_lazy[o] = 0;
  if (L + 1 == R)
  {
    seg_min[o] = -L*mid;
    return;
  }
  const int md = (L + R) / 2;
  init(L, md, o << 1);
  init(md, R, o << 1 | 1);
  pushup(o);
}
ld query(int ql, int qr, int L = 0, int R = n + 1, int o = 1)
{
  if (ql <= L && R <= qr)
  {
    return seg_min[o];
  }
  const int md = (L + R) / 2;
  pushdown(o);
  ld ret = - n - 1;
  if (ql < md)
  {
    ret = query(ql, qr, L, md, o << 1);
  }
  if (md < qr)
  {
    ret = max(ret, query(ql,qr,md,R,o << 1 | 1));
  }
  return ret;
}
int pre[maxn];
bool check()
{
  init();
  memset(pre,-1,sizeof(pre));
  for (int i = 1; i <= n; i++)
  {
    if (pre[a[i]] != -1)
    {
      add(pre[a[i]], i, -1);
    }
    else
    {
      add(i, n + 1, 1);
    }
    pre[a[i]] = i;
    // if (n == 50)
    //     cout << "query i" << query(i,i+1) << " query j: "<< query(0, i) << endl;
    if (query(i, i + 1)<= query(0, i))
    {
      return true;
    }
  }
  return false;
}
int main()
{
  // freopen("C:\\hdsummer_data\\r4\\data\\1004.in", "r", stdin);
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d", &n);
      L = 0, R = 1;
      for (int i = 1; i <= n; i++)
      {
        scanf("%d", a + i);
      }
      while(R - L > eps)
      {
        mid = (L + R) / 2;
        if (check())
        {
          R = mid;
        }
        else
        {
          L = mid;
        }
      }
      printf("%.10lf\n", (double)mid);
    }
  }
}
