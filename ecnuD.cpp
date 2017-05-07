#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;
const int chsize = 26;
inline int idx(char x)
{
  return x - 'a';
}

char s[maxn];
int dp[2][chsize][chsize];
bool trie[chsize][chsize][chsize];
int n;
char inv[1900];
int main()
{
  while(scanf("%s", s) != EOF)
  {
    scanf("%d", &n);
    memset(trie, 0, sizeof(trie));
    for (int i = 0; i < n; i++)
    {
      scanf("%s", inv);
      trie[idx(inv[0])][idx(inv[1])][idx(inv[2])] = true;
    }
    int r = 0;
    memset(dp, inf, sizeof(dp));
    int len = strlen(s);
    dp[r][idx(s[0])][idx(s[1])] = 0;
    for (int i = 2; i < len; i++)
    {
      int now = idx(s[i]);
      memset(dp[r ^ 1], inf, sizeof(dp[r ^ 1]));
      dp[r ^ 1][idx(s[i - 1])][idx(s[i])] = i - 1;
      for (int j = 0; j < chsize; j++)
      {
        for (int k = 0; k < chsize; k++)
        {
           dp[r ^ 1][j][k] = min(dp[r ^ 1][j][k], dp[r][j][k] + 1);
           if (!trie[j][k][now])dp[r ^ 1][k][now] = min(dp[r^1][k][now], dp[r][j][k]);
        }
      }
      r ^= 1;
    }
    int ans = len - 2;
    for (int i = 0; i < chsize; i++)
    {
      for (int j = 0; j < chsize; j++)
      {
        ans = min(dp[r][i][j], ans);
      }
    }
    printf("%d\n", ans);
  }
}
