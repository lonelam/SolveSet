#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const ll moder = 1e9 + 7;
int n;
int A[maxn];
int cnt[31][maxn];

int lsb(int x)
{
  return x & (-x);
}

int query(int c[], int x)
{
  int ret = 0;
  while(x)
  {
    ret += c[x];
    x -= lsb(x);
  }
  return ret;
}

void add(int c[], int x, int a)
{
  while(x <= n)
  {
    c[x] += a;
    x += lsb(x);
  }
}
ll bipower[maxn];
void init()
{
  bipower[0] = 1LL;
  for (int i = 1; i < maxn; i++)
  {
    bipower[i] = (bipower[i-1] * 2LL) % moder;
  }
}
int main()
{
  int m;
  init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", A + i);
    for (int j = 0; j < 31; j++)
    {
      if (A[i] >> j& 1)add(cnt[j], i, 1);
    }
  }
  int cmd;
  int a, b;
  scanf("%d", &m);
  while(m--)
  {
    scanf("%d%d%d", &cmd, &a, &b);
    if (cmd == 1)
    {
      for (int i = 0; i < 31; i++)
      {
        add(cnt[i], a, (b >> i & 1) - (A[a] >> i & 1));
      }
      A[a] = b;
    }
    else if (cmd == 2)
    {
      ll ans = 0;
      for (int i = 0; i < 31; i++)
      {
        int u = query(cnt[i], b) - query(cnt[i], a-1);
        ans += (bipower[u]  +  moder- 1) % moder * (1LL << i) % moder;
        ans %= moder;
      }
      printf("%lld\n", ans);
    }
  }
}
