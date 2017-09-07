#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
struct node
{
  int L, R;
  int l, r;
  int val;
  node() : L(-1), R(-1), l(-1), r(-1), val(0) {}
  node (int _l, int _r) : L(-1), R(-1),l(_l), r(_r), val(0) {}
};
const int S = (int) 7e6;
node tree[S];
int tot;
//range : left inclusive right exclusive
int build(int l, int r)
{
  int v = tot++;
  tree[v] = node(l, r);
  //leaf
  if (l + 1 == r) return v;
  //get child range
  int mid = (l + r) / 2;
  //restore children
  tree[v].L = build(l, mid);
  tree[v].R = build(mid, r);
  return v;
}
int setVal(int v, int p, int x)
{
  //not in the chain
  if (p < tree[v].l || tree[v].r <= p) return v;
  //new node
  int u = tot++;
  tree[u] = tree[v];
  //leaf
  if (tree[v].L == -1)
  {
    tree[u].val = x;
    return u;
  }
  tree[u].L = setVal(tree[v].L, p, x);
  tree[u].R = setVal(tree[v].R, p, x);
  //sum
  tree[u].val = tree[tree[u].L].val + tree[tree[u].R].val;
  return u;
}
int getSum(int v, int l, int r)
{
  //in range
  if (l <= tree[v].l && tree[v].r <= r)
  {
    return tree[v].val;
  }
  //out of range
  if (l >= tree[v].r || tree[v].l >= r)
  {
    return 0;
  }
  return getSum(tree[v].L, l, r) + getSum(tree[v].R, l, r);
}
//the only difference between cols is a chain
int roots[maxn];
int n, q;
int main()
{
  scanf("%d%d", &n, &q);
  roots[0] = build(0, n);
  for (int i = 0; i < n; i++)
  {
    int p;
    scanf("%d", &p);
    p--;
    // no two marked squares share the same row or the same col
    roots[i+1] = setVal(roots[i], p, 1);
  }
  while(q--)
  {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--;
    y1--;
    ll ans = (ll)n * (n - 1);
    ans -= (ll)x1 * (x1 - 1);
    ans -= (ll) y1 * (y1 - 1);
    ans -= (ll) (n - x2 - 1) * (n - x2);
    ans -= (ll) (n - y2 - 1) * (n - y2);
    ll cnt = getSum(roots[x1], 0, y1);
    ans += cnt *( cnt - 1);
    cnt = getSum(roots[x1], y2, n);
    ans += cnt *( cnt - 1);
    cnt = y1 - getSum(roots[x2], 0, y1);
    ans += cnt *( cnt - 1);
    cnt = (n - y2) - getSum(roots[x2], y2, n);
    ans += cnt *( cnt - 1);
    printf("%lld\n", ans / 2LL);
  }
}
