#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int mx[maxn * 4];
void assign(int p, int v, int L = 0, int R = maxn, int o = 1)
{
  if (L + 1 == R)
  {
    mx[o] = max(mx[o], v);
    return;
  }
  const int mid = L + (R - L) / 2;
  if (p < mid)
  {
    assign(p, v, L, mid, o << 1);
  }
  else
  {
    assign(p, v, mid, R, o << 1 | 1);
  }
  mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}

int query(int ql, int qr, int L = 0, int R = maxn, int o = 1)
{
  if (R <= ql || qr <= L)
  {
    return -1;
  }
  if (ql <= L && R <= qr)
  {
    return mx[o];
  }
  int ret = -1;
  const int mid = (L + R) / 2;
  if (mid > ql)
  {
    ret = query(ql, qr, L, mid, o << 1);
  }
  if (mid < qr)
  {
    ret = max(query(ql, qr, mid, R, o << 1 | 1), ret);
  }
  return ret;
}
int n, c, d;
char tp[100];
int btmp, ptmp;
int Cp[maxn], Cb[maxn], Dp[maxn], Db[maxn];
int main()
{
  while(scanf("%d%d%d", &n, &c, &d) != EOF)
  {
    int ctot = 0;
    int dtot = 0;
    int cmb = 0;
    int dmb = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%s", &btmp, &ptmp, tp);
      if (tp[0] == 'C' && c >= ptmp)
      {
        cmb = max(cmb, btmp);
        Cp[ctot] = ptmp;
        Cb[ctot++] = btmp;
      }
      else if (tp[0] == 'D' && d >= ptmp)
      {
        dmb = max(dmb, btmp);
        Dp[dtot] = ptmp;
        Db[dtot++] = btmp;
      }
    }
    int ans = cmb + dmb;
    if (cmb == 0 || dmb == 0)
    {
      ans = 0;
    }
    memset(mx, -1, sizeof(mx));
    for (int i = 0; i < ctot; i++)
    {
      if (Cp[i] < c)
      {
        int qq = query(0, c - Cp[i] + 1);
        assign(Cp[i], Cb[i]);
        if (qq != -1)
        ans = max(ans, Cb[i] + qq);
      }
    }
    memset(mx, -1, sizeof(mx));
    for (int i = 0; i < dtot; i++)
    {
      if (Dp[i] < d)
      {
        int qq = query(0, d- Dp[i] + 1);
        assign(Dp[i], Db[i]);
        if (qq != -1)
        ans = max(ans, Db[i] + qq);
      }
    }
    printf("%d\n", ans);
  }
}
