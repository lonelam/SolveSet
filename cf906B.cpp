#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n, m;
typedef pair<int,int> pii;
map<pii, int> grid;
map<pii, int> raw;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
  while(~scanf("%d%d", &n, &m))
  {
    grid.clear();
    bool trans = false;
    if (n > m)
    {
      trans = true;
      swap(n, m);
    }
    int up = n * m;
    int x = 0;
    int y = (m ) / 2;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        raw[{i, j}] = i * m + j + 1;
      }
    }
    for (int k = 1; k <= up; k++)
    {
      if (grid.find({x, y}) == grid.end())
      {
        grid[{x, y}] = k;
      }
      else
      {
        x = (x + 1) % n;
        y = (y - 2 + m) % m;
        grid[{x, y}] = k;
      }
      x = (x - 1 + n) % n;
      y = (y + 1) % m;
    }
    bool ok = true;
    for (int i = 0; i < n && ok; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int c = grid[{i, j}];
        int rx = (c - 1) / m;
        int ry = (c - 1) % m;
        set<int> adj;
        set<int> radj;
        for (int d = 0; d < 4; d++)
        {
          int tx = rx + dx[d];
          int ty = ry + dy[d];
          if (tx >= 0 && tx < n && ty >= 0 && ty < m)
          {
            radj.insert(raw[{tx, ty}]);
          }
          tx = i + dx[d];
          ty = j + dy[d];
          if (tx >= 0 && tx < n && ty >= 0 && ty < m)
          {
            adj.insert(grid[{tx, ty}]);
          }
        }
        for (int aa: adj)
        {
          if (radj.find(aa) != radj.end())
          {
            ok = false;
            break;
          }
        }
      }
    }
        // for (int i = 0; i < n; i++)
        // {
        //   for (int j = 0; j < m; j++)
        //   {
        //     printf("%d%c", grid[{i, j}], j==(m-1)?'\n':' ');
        //   }
        // }
    if (ok)
    {
      printf("YES\n");
      if (!trans)
      {
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < m; j++)
          {
            printf("%d%c", grid[{i, j}], j==(m-1)?'\n':' ');
          }
        }
      }
      else
      {
        for (int i = 0; i < m; i++)
        {
          for (int j = 0; j < n; j++)
          {
            printf("%d%c", (grid[{j, i}] -1) % m * n + (grid[{j, i}] -1) / m + 1, j==(n-1)?'\n':' ');
          }
        }
      }
    }
    else
    {
      printf("NO\n");
    }
  }
}
