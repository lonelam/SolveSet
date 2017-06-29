#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

int x1save[maxn], x2save[maxn], y1save[maxn], y2save[maxn];
int lsb(int x)
{
  return x & (-x);
}
void add(int c[], int x)
{
  while(x < maxn)
  {
    c[x]++;
    x += lsb(x);
  }
}
int query(int c[], int x)
{
  int ans = 0;
  while(x)
  {
    ans += c[x];
    x -= lsb(x);
  }
  return ans;
}
int xi1[maxn], xi2[maxn], yi1[maxn], yi2[maxn];
int main()
{
  int d;
  int n, m;
  scanf("%d", &d);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < d; i++)
  {
    scanf("%d%d%d%d", xi1+i, yi1+i, xi2+i, yi2+i);
    if (xi1[i] > xi2[i]) swap(xi1[i], xi2[i]);
    if (yi1[i] > yi2[i]) swap(yi1[i], yi2[i]);
    add(x1save, xi1[i]);
    add(x2save, xi2[i]);
    add(y1save, yi1[i]);
    add(y2save, yi2[i]);
  }
  int tarl, tarr, tart, tarb;
  scanf("%d%d%d%d", &tarl, &tarr, &tart, &tarb);
  int ans = -1;
  for (int i = 0; i < d; i++)
  {
    int cntl = query(x1save, xi2[i]-1);
    int cntr = query(x2save, n) - query(x2save, xi1[i]);
    int cntt = query(y1save, yi2[i] - 1);
    int cntb = query(y2save, m) - query(y2save, yi1[i]);
    if (xi1[i] < xi2[i])
    {
      cntl--;
      cntr--;
    }
    if (yi1[i] < yi2[i])
    {
      cntt--;
      cntb--;
    }
  //  cout << cntl << " "<< cntr <<" "<< cntt <<" "<< cntb<<endl;
    if (cntl == tarl && cntr == tarr && cntt == tart && cntb == tarb)
    {
      ans = i + 1;
      break;
    }
  }
  printf("%d\n", ans);
}
