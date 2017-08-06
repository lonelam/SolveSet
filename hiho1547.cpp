
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 10;

char grid[maxn * 2][maxn * 2];
int n, m;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
map<char, int> dirmap = {{'l', 0}, {'u', 1}, {'r', 2}, {'d', 3}};
int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        grid[i << 1][j << 1] = '+';
        grid[i << 1 | 1][j << 1 | 1] = ' ';
        grid[i << 1][j << 1 | 1] = '-';
        grid[i << 1 | 1][j << 1] = '|';
      }
    }
    grid[0][1] = ' ';
    // for (int i = 0; i < 2 * n + 1; i++)
    // {
    //   for (int j = 0; j < 2 * m + 1; j++)
    //   {
    //     putchar(grid[i][j]);
    //   }
    //   putchar('\n');
    // }
    int curx = 1, cury = 1;
    char cmd[5] = "d";
    int l, f, r;
    while(curx > 0 && cury > 0 && scanf("%d%d%d",&l, &f, &r) != EOF)
    {
      if (!f) grid[curx + dx[dirmap[cmd[0]]]][cury + dy[dirmap[cmd[0]]]] = ' ';
      if (!l) grid[curx + dx[(dirmap[cmd[0]] + 3) % 4]][cury + dy[(dirmap[cmd[0]] + 3) % 4]] = ' ';
      if (!r) grid[curx + dx[(dirmap[cmd[0]] + 1) % 4]][cury + dy[(dirmap[cmd[0]] + 1) % 4]] = ' ';
      scanf("%s", cmd);
      curx = curx + 2 * dx[dirmap[cmd[0]]];
      cury = cury + 2 * dy[dirmap[cmd[0]]];
    }
    for (int i = 0; i < 2 * n + 1; i++)
    {
      for (int j = 0; j < 2 * m + 1; j++)
      {
        putchar(grid[i][j]);
      }
      putchar('\n');
    }
  }
}
