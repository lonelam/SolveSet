#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n;
int lsb(int x)
{
  return x & (-x);
}
struct leg
{
  int l, d, id;
}legs[maxn];
bool cmp(leg &lhs, leg & rhs)
{
  return lhs.l > rhs.l;
}
int query(int a[], int x)
{
  int ret = 0;
  while(x)
  {
    ret += a[x];
    x -= lsb(x);
  }
  return ret;
}
void add(int a[], int x, int adder)
{
  while(x <= n)
  {
    a[x] += adder;
    x += lsb(x);
  }
}
bool dcmp(leg &lhs, leg & rhs)
{
  return lhs.d < rhs.d;
}
int dsum[maxn];
int drank[maxn];
int dcnt[maxn];
int lcnt[maxn];
int firstkth(int k)
{
  int L = 1, R = n + 1;

  while(L + 1 < R)
  {
    const int mid = (L + R) / 2;
    if (query(dcnt, mid) <= k)
    {
      L = mid;
    }
    else
    {
      R = mid;
    }
  }
  //cout << L << endl;
  return query(dsum, L);
}
void delleg(leg & tar)
{
  add(dcnt, drank[tar.id], -1);
  add(dsum, drank[tar.id], -tar.d);

}
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    int ans = 0;
    memset(lcnt,0,sizeof(lcnt));
    memset(dsum,0,sizeof(dsum));
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &legs[i].l);
      legs[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &legs[i].d);
      lcnt[legs[i].l]++;
    }
    sort(legs + 1, legs + n + 1, dcmp);
    for (int i = 1; i <= n; i++)
    {
      drank[legs[i].id] = i;
      add(dsum, i, legs[i].d);
      add(dcnt, i, 1);
    }
    ans = firstkth(n-1);
    sort(legs + 1, legs + n + 1, cmp);
    int pre = 1;
    int rem = n;
    int acc = 0;
    int nex = 0;
    //legs[0].l = legs[1].l;
    for (int i = 1; i <= n; i++)
    {
      if (legs[i].l != legs[pre].l)
      {
        int sz = i - pre;
        pre = i;
        if (sz > rem)
        {
          ans = min(ans,acc);
          break;
        }
        else ans = min(ans, firstkth((rem - sz + 1)) + acc);
        acc += nex;
        nex = 0;
        //nex += acc;
      }
      delleg(legs[i]);
      nex += legs[i].d;
      rem--;
    }
    int sz = n + 1 - pre;
    if (sz > 0)
    {
      ans = min(ans, acc);
    }
    printf("%d\n", ans);
  }
}
