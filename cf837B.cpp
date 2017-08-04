#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 120;
int n, m;
char s[maxn][maxn];
char s2[maxn][maxn];
int check(int n, int m)
{
  if (n % 3 != 0)
  {
    return 0;
  }
  int d = n / 3;
  if (s[0][0] == s[d][0] || s[0][0] == s[2 * d][0] || s[d][0] == s[2 * d][0])
  {
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (s[i][j] != s[(i / d) * d][0])
      {
        return 0;
      }
    }
  }
  return 1;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    for (int j = 0; j < m; j++)
    {
      s2[i][j] = s[i][j];
    }
  }
  int ans = check(n,m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      s[j][i] = s2[i][j];
    }
  }
  swap(n, m);
  ans |= check(n, m);
  if (ans) printf("YES\n");
  else printf("NO\n");
}
