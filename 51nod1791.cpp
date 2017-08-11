#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1100000 + 100;
int cnt[maxn * 2];
bool vis[maxn * 2];
char s[maxn];
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%s", s);
      int n = strlen(s);
      int level = maxn;
  //    memset(cnt + maxn, 0, sizeof(int) * (n + 1));
      memset(cnt + maxn - n - 1, 0, sizeof(int) * (n+1) * 2);
      memset(vis + maxn - n - 1, 0, sizeof(int) * (n+1) * 2);
      int r = maxn;
      ll ans = 0;
      for (int i = 0; i < n;i ++)
      {
        if (s[i] == '(')
        {
          vis[level] = true;
          level++;
          cnt[level] = 0;
          r = max(level, r);
        }
        else if (s[i] == ')')
        {
          level--;
          if (level < maxn)
          {
            r -= maxn;
            memset(cnt + maxn - r - 1, 0, sizeof(int) * (r+1) * 2);
            memset(vis + maxn - r - 1, 0, sizeof(int) * (r+1) * 2);
            level = maxn;
            r = maxn;
          }
          if (vis[level])
          {
            ans += cnt[level] + 1;
            cnt[level]++;
            vis[level] = false;
          }
        }
      }
      printf("%lld\n", ans);
    }
  }
}
