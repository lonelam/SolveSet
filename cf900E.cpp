#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
pair<int,int> dp[maxn][2];
int tail[maxn];
char s[maxn];
int main()
{
  int n, m;
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%d", &m);
  if (m == 1)
  {
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '?')
      {
        cnt++;
      }
    }
    printf("%d\n", cnt);
    return 0;
  }
  tail[0] = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '?') tail[i + 1] = tail[i] + 1;
    else if (i == 0) tail[i + 1] = 1;
    else if (s[i] == 'a')
    {
      if (s[i-1] == 'a') tail[i+1] = 1;
      else tail[i+1] = tail[i] + 1;
    }
    else if (s[i] == 'b')
    {
      if (s[i-1] == 'b') tail[i+1] = 1;
      else tail[i+1] = tail[i] + 1;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (tail[i+1] >= m)
    {
      if (s[i] != 'b')
      {
        dp[i+1][0] = {dp[i][1].first + 1, dp[i][1].second};
      }
      if (s[i] != 'a')
      {
        dp[i+1][1] = {dp[i][0].first + 1, dp[i][0].second};
      }
    }
  }
}
