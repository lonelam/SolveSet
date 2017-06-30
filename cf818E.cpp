#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int fcnt[20][maxn];
int ftot;
int facs[20];
int fneed[20];
int n, k;
int lsb(int x)
{
  return x & (-x);
}
void add(int c[], int x, int adder)
{
  while(x < maxn)
  {
    c[x]+=adder;
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
bool check(int x, int Y)
{
  for (int i = 0; i < ftot; i++)
  {
    if (query(fcnt[i], n - Y) - query(fcnt[i], x) < fneed[i])
    {
      return false;
    }
  }
  return true;
}
bool isprime(int x)
{
  for (int i = 2; i * i <= x; i++)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
int a[maxn];
int main()
{
  scanf("%d%d", &n, &k);
  int tk = k;
  for (int i = 2; i * i<= tk; i++)
  {
    if (tk % i == 0)
    {
      facs[ftot] = i;
      while(tk % i == 0)
      {
        tk /= i;
        fneed[ftot]++;
      }
      ftot++;
    }
  }
  if (tk != 1)
  {
    fneed[ftot] = 1;
    facs[ftot++] = tk;
  }
  for (int i = 0; i < n;i ++)
  {
    scanf("%d", a + i);
    for (int j = 0; j < ftot; j++)
    {
      int tmp = 0;
      while(a[i] % facs[j] == 0)
      {
        tmp++;
        a[i] /= facs[j];
      }
      if (tmp) add(fcnt[j], i + 1, tmp);
    }
  }
  ll ans = 0;
  for (int x = 0; x < n; x++)
  {
    int L = 0, R = n - x;

    while(L + 1 < R)
    {
      const int mid = (L + R + 1) / 2;
      if (check(x, mid))
      {
        L = mid;
      }
      else
      {
        R = mid;
      }
    }
    if (check(x, L)) ans += L+1;
  }
  printf("%lld\n", ans);
}
