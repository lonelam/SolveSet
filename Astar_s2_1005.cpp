#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const ll moder = 1e9 + 7;
const int chsize = 10;
int T, n;
ll incdp[chsize][maxn][2];
char num[maxn];
ll dfs(int head, int len, int inc, bool up)
{
  if (len == 1)
  {
    return 1;
  }
  if (up)
  {
    ll ans = 0;
    for (int i = 0; i < num[n-len+1] - '0'; i++)
    {
      if (i < head && !inc)
      {
        ans = (ans + dfs(i, len - 1, 0, false)) % moder;
      }
      else if (i == head)
      {
        ans = (ans + dfs(i, len - 1, inc, false)) % moder;
      }
      else if (i > head)
      {
        ans = (ans + dfs(i, len - 1, 1, false)) % moder;
      }
    }
    if (num[n-len+1] - '0' > head)
    {
      ans = (ans + dfs(num[n-len + 1] - '0', len - 1, 1, true)) % moder;
    }
    else if (num[n-len+1] - '0' == head)
    {
      ans = (ans + dfs(num[n-len + 1] - '0', len - 1, inc, true)) % moder;
    }
    else if (!inc)
    {
      ans = (ans + dfs(num[n-len+1] - '0', len - 1, 0, true))% moder;
    }
    return ans;
  }
  if (incdp[head][len][inc] != -1)
  {
    return incdp[head][len][inc];
  }
  incdp[head][len][inc] = 0;
  if (!inc)
    for (int i = 0; i < head; i++)
    {
      incdp[head][len][inc] = (incdp[head][len][inc] + dfs(i, len - 1, 0, false)) % moder;
    }
  incdp[head][len][inc] = (incdp[head][len][inc] + dfs(head, len - 1, inc, false)) % moder;
  for (int i = head + 1; i < chsize; i++)
  {
    incdp[head][len][inc] = (incdp[head][len][inc] + dfs(i, len - 1, 1, false)) % moder;
  }
  return incdp[head][len][inc];
}
int main()
{
  scanf("%d", &T);
  memset(incdp,-1,sizeof(incdp));
  while(T--)
  {
    scanf("%s", num);
    n = strlen(num);
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j < chsize; j++)
      {
        ans = (ans + dfs(j, i, 0, false));
      }
    }
    for (int i = 1; i < num[0] - '0'; i++)
    {
      ans = (ans + dfs(i, n, 0, false))% moder;
    }
    ans = (ans + dfs(num[0] - '0', n, 0, true)) % moder;
    printf("%d\n", (int) ans);
  }
}
