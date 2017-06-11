#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1500 + 10;
char s[maxn];
int n, q;
int m;
int ans[26][maxn];
int dp[2][maxn];
char qc[10];
int main()
{
  while(scanf("%d%s", &n, s) != EOF)
  {
    n = strlen(s);
    scanf("%d", &q);
    for (int k = 0; k < 26; k++)
    {
      const char ch = k + 'a';
      int tail = 0;
      int flip = 0;
      int head = 0;
      memset(dp, 0, sizeof(dp));
      for (int i = 0; i <= n; i++)
      {
        dp[1][i] = i;
        ans[k][i] = i;
      }
      for (int i = 1; i < n; i++)
      {
        if (s[i] == ch && s[i - 1] != ch)
        {
          head = i;
        }
        else if (s[i] != ch && s[i - 1] == ch)
        {
          for (int i = 0; i <= n; i++)
          {
            dp[flip][i] = i;
          }
          for (int j = head - tail; j <= n; j++)
          {
            dp[flip][j] = max(dp[flip][j], dp[flip ^ 1][j - head + tail] + i - tail);
          }
          for (int j = 0; j <= n; j++)
          {
            dp[flip][j] = max(dp[flip][j], i - head + j);
            ans[k][j] = max(ans[k][j], dp[flip][j]);
          }
          flip ^= 1;
          tail = i;
        }
      }
      if (s[n - 1] == ch)
      {
          for (int i = 0; i <= n; i++)
          {
            dp[flip][i] = i;
          }
          for (int j = head - tail; j <= n; j++)
          {
            dp[flip][j] = max(dp[flip][j], dp[flip ^ 1][j - head + tail] + n - tail);
          }
          for (int j = 0; j <= n; j++)
          {
            dp[flip][j] = max(dp[flip][j], n - head + j);
            ans[k][j] = max(ans[k][j], dp[flip][j]);
          }
          flip ^= 1;
          tail = n;
      }
      for (int i = 0; i <= n; i++)
      {
        ans[k][i] = min(n, ans[k][i]);
      }
    }
    for (int i = 0; i < q; i++)
    {
      scanf("%d%s", &m, qc);
      printf("%d\n", ans[qc[0] - 'a'][m]);
    }
  }
}
/*
7
abccbab
3
3 b

7
abbbccc
10
9 a


12
abaabbababaa

*/
