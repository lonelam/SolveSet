#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;
int grid[maxn][maxn];
int n;
bool isvalid(int x, int y)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (grid[x][y] == grid[i][y] + grid[x][j]) return true;
    }
  }
  return false;
}
bool solve()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (grid[i][j] != 1 && !isvalid(i, j))
      {
        return false;
      }

    }
  }

  return true;
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", grid[i] + j);
    }
  }
  if (solve())
  {
    printf("Yes\n");
  }
  else
  {
    printf ("No\n");
  }

}
