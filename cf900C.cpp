#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
int p[maxn];
int a[maxn];
int b[maxn];
// int inline lsb(int x)
// {
//   return x & (-x);
// }
// void inline add(int x)
// {
//   while(x <= n)
//   {
//     a[x]++;
//     x += lsb(x);
//   }
// }
// int inline query(int x)
// {
//   int ret = 0;
//   while(x)
//   {
//     ret += a[x];
//     x -= lsb(x);
//   }
//   return ret;
// }

int main()
{
  while(~scanf("%d", &n))
  {
    for (int i = 1; i <= n; i++)
      scanf("%d", p + i);
    int ok = 1;
    set<int> pre = {p[1]};
    memset(a, 0, sizeof(a));
    b[p[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
      if (*pre.rbegin() < p[i])
      {
        ok++;
        b[p[i]] = 1;
      }
      else
      {
        b[p[i]] = 0;
        int tmp = *pre.rbegin();
        pre.erase(tmp);
        if (pre.empty() || *pre.rbegin() < p[i])
        {
          a[tmp]++;
        }
        pre.insert(tmp);
      }
      pre.insert(p[i]);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
      if (a[i] - b[i]> a[ans] - b[ans])
      {
        ans = i;
      }
    }
    printf("%d\n", ans);
  }
}
