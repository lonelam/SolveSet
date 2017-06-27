#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 20;
int grid[maxn][maxn];
int dx[] = {1,1,0,1};
int dy[] = {0,1,1,-1};
int main()
{
  for (int i = 0; i < maxn; i++)
  {
    for (int j = 0; j < maxn; j++)
    {
      cin >> grid[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < maxn; i++)
  {
    for (int j = 0; j < maxn; j++)
    {
      for (int d = 0; d < 4; d++)
      {
        int tmp = grid[i][j];
        for (int k = 1; k < 4 && i + dx[d] * k>= 0 && i + dx[d] * k < maxn && j + dy[d] * k >= 0 && j + dy[d] * k < maxn; k++)
        {
          tmp *= grid[i + dx[d] * k][j + dy[d] * k];
        }
        ans = max(ans, tmp);
      }
    }
  }
  cout << ans <<endl;
}
