#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
char s[maxn];
int vis[1000000 + 10];
int main()
{
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) s[i] -= '0';
  for (int m = 1; m < 30; m++)
  {
    int tar = 0;
    int mask = (1 << m) - 1;
    for (int i = 0; i < m; i++)
    {
      tar <<= 1;
      tar |= (int)s[i];
    }
    vis[tar] = true;
    for (int i = m; i < n; i++)
    {
      tar <<= 1;
      tar &= mask;
      tar |= (int)s[i];
      vis[tar] = true;
    }
    for (int i = (m!=1)?(1 << (m-1)):0; i <= mask; i++)
    {
      if (!vis[i])
      {
        printf("%d\n", m);
        return 0;
      }
    }
  }
  assert(false);
}
