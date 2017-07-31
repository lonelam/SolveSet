#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000000 + 100;
unsigned a[maxn];
unsigned x, y, z;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}
int b[maxn];
int ans[maxn];
set<int> qs;
int n,m;
void quick_sort(int L = 0, int R = n)
{
  if (qs.lower_bound(L) == qs.lower_bound(R) || L + 1 >= R)
  {
    return;
  }
  const int pi = ((unsigned)rand() * 10000 + (unsigned)rand()) % (R - L) + L;
  const unsigned pivot = a[pi];
  swap(a[pi], a[R - 1]);
  int s = L;
  for (int i = L; i < R - 1; i++)
  {
    if (a[i] < pivot)
    {
      swap(a[s++], a[i]);
    }
  }
  swap(a[s], a[R-1]);
  quick_sort(L, s);
  quick_sort(s + 1, R);
}
int main()
{
  int kase = 1;
  while(scanf("%d%d%u%u%u", &n, &m, &x, &y, &z) != EOF)
  {
    qs.clear();
    for (int i = 0; i < m; i++)
    {
      scanf("%d", b + i);
      qs.insert(b[i]);
    }
    for (int i = 0; i < n; i++)
    {
      a[i] = rng61();
    }
    quick_sort();
    printf("Case #%d:", kase++);
    for (int i = 0; i < m; i++)
    {
      printf(" %u", a[b[i]]);
    }
    printf("\n");
  }
}
