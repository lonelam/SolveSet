#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n, m;
int vis[maxn];
int s[2][maxn];
vector<int> G[maxn];
int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    for (int i = 0; i <= n; i++)
    {
      scanf("%d", s[i & 1]);
      for (int j = 1; j <= s[i & 1][0]; j++) scanf("%d", s[i & 1] + j);
      if (i)
      {
        for (int j = 1; j <= s[0][0] && j <= s[1][0]; j++)
        {
          if (s[i&1][j] == s[i & 1 ^ 1][j])
          {
            continue;
          }
          else
          {
            G[s[i & 1][j]].push_back(s[i & 1 ^ 1][j]);
          }
        }
      }
    }
  }
}
