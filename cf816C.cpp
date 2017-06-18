#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
int grid[maxn][maxn];
int tmp[maxn][maxn];
int n, m;
int cnt;
bool check()
{
  for (int i = 1; i < n; i++)
  {
    int diff = grid[i - 1][0] - grid[i][0];
    for (int j = 1; j < m; j++)
    {
      if (grid[i - 1][j] - grid[i][j] != diff) return false;
    }
  }
  for (int j = 1; j < m; j++)
  {
    int diff = grid[0][j - 1] - grid[0][j];
    for (int i = 1; i < n; i++)
    {
      if (grid[i][j - 1] - grid[i][j] != diff) return false;
    }
  }

  return true;
}
vector<pair<int, int> > ans;
int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    ans.clear();
    int zerorow = -1;
    int least = inf;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        scanf("%d", grid[i] + j);
        least = min(grid[i][j], least);
        if (grid[i][j] == 0) zerorow = i;
      }
    }
    if (!check())
    {
      printf("-1\n");
      continue;
    }
    if (least)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          grid[i][j] -= least;
          if (grid[i][j] == 0) zerorow = i;
        }
      }
      if (n > m)
      {
        for (int i = 1; i <= m; i++)
        {
          for (int j = 0; j < least; j++)
          ans.push_back({1, i});
//          printf("col %d\n", i);
        }
      }
      else
      {
        for (int i = 1; i <= n; i++)
        {
          for (int j = 0; j < least; j++)
          {
            ans.push_back({0, i});
//            printf("row %d\n", i);
          }
        }
      }
    }
    for (int i = 0;i < n; i++)
    {
      int diff = grid[i][0] - grid[zerorow][0];
      for (int j = 0; j < m; j++)
      {
        grid[i][j] -= diff;
      }
      for (int k = 0; k < diff; k++)
      {
        ans.push_back({0, i + 1});
        //printf("row %d\n", i + 1);
      }
    }
    for (int j = 0; j < m; j++)
    {
      if (grid[0][j])
      {
        int diff = grid[0][j];
        for (int i = 0; i < n; i++)
        {
          grid[i][j] -= diff;
        }
        for (int k = 0; k < diff; k++)
        {
          ans.push_back({1, j + 1});
//          printf("col %d\n", j + 1);
        }
      }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%s %d\n",ans[i].first ? "col": "row", ans[i].second);
    }
  }

}
