#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n, k, m, a;
int g[maxn];
int last[maxn];
int cnt[maxn];
int r[maxn];
int s[maxn];
int bound;
bool cmp(const int lhs, const int rhs)
{
  if (cnt[lhs] != cnt[rhs]) return cnt[lhs] < cnt[rhs];
  return last[lhs] > last[rhs];
}
int get1(int tar)
{
  if (n == 1) return 1;
  int rem = m - a;
  int tmp = cnt[s[tar]] + 1;
  if (k == n) return 1;
  for (int i = tar + 1; i <= k + 1; i++)
  {
    rem -= tmp - cnt[s[i]];
  }
  if (rem >= 0)
  {
    return 2;
  }
  return 1;
}
int get2(int tar)
{
  int rem = m - a;
  if (rem + cnt[s[tar]] > bound) return 2;
  return 3;
  // int tmp = cnt[s[tar]] + 1;
}
int main()
{
  scanf("%d%d%d%d", &n, &k, &m, &a);
  for (int i = 0; i < a; i++)
  {
    scanf("%d", g + i);
    cnt[g[i]]++;
    last[g[i]] = i;
  }
  for (int i = 1; i <= n; i++) s[i] = i;
  sort(s + 1, s + n + 1, cmp);
  reverse(s + 1, s + n + 1);
  bound = cnt[s[k]];
  for (int i = 1; i <= k; i++)
  {
    if (cnt[s[i]])
    {
      r[s[i]] = get1(i);
    }
    else if(m > a)
    {
      if (n == 1) r[s[i]] = 1;
      else r[s[i]] = 2;
    }
    else
    {
      r[s[i]] = 3;
    }
  }
  for (int i = k + 1; i <= n; i++)
  {
    if (m > a)
    {
      r[s[i]] = get2(i);
    }
    else
    {
      r[s[i]] = 3;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    printf("%d%c", r[i], i==n?'\n':' ');
  }
}
