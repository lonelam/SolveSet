#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxL = 200 + 50;
const int maxn = 6 + 1;
const ll moder = 998244353;
int sup;
int n, L;
char s[maxn][maxL];
int slen[maxn];
vector<pair<int,int> > trail[maxn];
ll p_m(ll base, ll index)
{
  ll ret = 1;
  while(index)
  {
    if (index & 1)
    {
      ret *= base;
      ret %= moder;
    }
    index >>= 1;
    base *= base;
    base %= moder;
  }
  return ret;
}
//y 作为x的后缀能走多远
bool check(int x, int y)
{
  for (int i = 0; i < slen[x]; i++)
  {
    bool flg = true;
    for (int j = 0; j + i < slen[x] && j < slen[y]; j++)
    {
      if (s[x][i + j] != s[y][j])
      {
        flg = false;
        break;
      }
    }
    if (flg)
    {
      if (i + slen[y] <= slen[x])
      {
        trail[x].push_back({y, slen[y]});
      }
      else
      {
        trail[x].push_back({y, slen[x] - i});
      }
      return true;
    }
  }
  return false;
}
char cs[maxL];
ll dfs(int st, int d, bool tracing = false, int last = -1)
{
  if (tracing)
  {
    last = 0;
  }
  ll appsum = 0;
  for (int i = 0; i < n; i++)
  {
    if (st >> i & 1)
    {
      continue;
    }
    else
    {
      appsum += slen[i];
    }
  }
  if (d + appsum < 2 * L)
  {
    return 0;
  }
  s[d] = '?';
  if (st == sup - 1)
  {
    if (d <= L)
    {
      int cnt = L - d;
      for (int i = 0; i < d; i++)
      {
        if (cs[i] == '?')
        {
          cnt++;
        }
      }
      return p_m(2, cnt);
    }
    else
    {
      int cnt = 0;
      for (int i = L; i < d; i++)
      {
        if (cs[i] == '?' && cs[2 * L - 1 - i] == '?')
        {
          cnt++;
        }
      }
      for (int i = d; i < 2 * L; i++)
      {
        if (cs[2 * L - 1 - i] == '?')
        {
          cnt++;
        }
      }
      return p_m(2, cnt);
    }
  }
  ll ret = dfs(st, d + 1);
  for (int i = 0; i < n; i++)
  {
    if (st >> i & 1)
    {
      continue;
    }
    int tst = st | (1 << i);
    bool check = true;
    for (int j = 0; j < slen[i]; j++)
    {
      cs[j + d] = s[i][j];
      if (j + d >= L)
      {
        if (cs[2 * L - 1 - j - d] == '?' || ((cs[2*L - 1 - j - d] - '0')^1) == (cs[j + d] - '0'))
        {
          continue;
        }
        else
        {
          check = false;
          break;
        }
      }
    }
    if (check)
    {
      for (const pair<int,int> & j : trail[i])
      {
        if (j.second == slen[j])
        {
          tst |= (1 << j.first);
        }
      }
    }
  }
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &L);
    sup = 1 << n;
    for (int i = 0; i < n; i++)
    {
      scanf("%s", s[i]);
      slen[i] = strlen(s[i]);
      trail[i].clear();
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i != j)
        {
          check(i, j);
        }
      }
    }
    ll ans = dfs(0, 0);
  }
}
