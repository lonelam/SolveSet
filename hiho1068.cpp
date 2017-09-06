#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
int n;
int weight[maxn];
int _min[maxn << 2];
void pushup(int x)
{
  _min[x] = min(_min[x << 1], _min[x << 1 | 1]);
}
void build(int L = 0, int R = n, int o = 1)
{
  if (L + 1 == R)
  {
    _min[o] = weight[L];
    return;
  }
  const int mid = (L + R) / 2;
  build(L, mid, o << 1);
  build(mid, R, o << 1 | 1);
  pushup(o);
}
int query(int ql, int qr, int L = 0, int R = n, int o = 1)
{
  if (ql <= L && R <= qr)
  {
    return _min[o];
  }
  const int mid = (L + R)/ 2;
  int ret = inf;
  if (ql < mid) ret = query(ql, qr, L, mid, o << 1);
  if (mid < qr) ret = min(ret, query(ql, qr, mid, R, o << 1 | 1));
  return ret;
}
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", weight + i);
    }
    build();
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
      static int a, b;
      scanf("%d%d", &a, & b);
      a--;
      printf("%d\n", query(a, b));
    }
  }
}
