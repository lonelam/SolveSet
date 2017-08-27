#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int T;
char tar[maxn];
char op[maxn];
int ans;
int n;
void dfs(int i, int d)
{
  if (n - i + d >= ans) return;
  if (i == n)
  {
    ans = min(ans, d);
  }
  int mc = 0;
  int ms = -1;
  for (int j = 0; j < i; j++)
  {
    for (int k = 0;; k++)
    {
      if (tar[j  + k] != tar[i + k] || i + k == n || j + k == i)
      {
        if(k > mc)
        {
          ms = j;
          mc = k;
        }
        break;
      }
    }
  }
  if (mc <= 1)
  {
    dfs(i + 1, d + 1);
  }
  else
  {
    for
  }
}
int main()
{
  while(~scanf("%d", &T))
  {
    while(T--)
    {
      scanf("%s", tar);
    }
  }
}
