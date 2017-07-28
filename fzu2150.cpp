#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 15;
char grid[maxn * maxn][maxn][maxn];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;
bool new_fire;
int ans;
bool is_burned(int t)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[t][i][j] == '#')
      {
        return false;
      }
    }
  }
  return true;
}
bool set_fire(int t)
{
  new_fire = false;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[t - 1][i][j] == '*')
      {
        grid[t][i][j] = '*';
      }
      else if (grid[t - 1][i][j] == '.')
      {
        grid[t][i][j] = '.';
      }
      else if (grid[t - 1][i][j] == '#')
      {
        grid[t][i][j] = '#';
        for (int d = 0; d < 4; d++)
        {
          int tx = i + dx[d], ty = j + dy[d];
          if (tx < n && tx >= 0 && ty < m && ty >= 0 && grid[t-1][tx][ty] == '*')
          {
            new_fire = true;
            grid[t][i][j] = '*';
          }
        }
      }
    }
  }
  /*
  cout << "round " << t << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << grid[t-1][i][j];
    }
    cout << endl;
  }
  */

  return new_fire;
}
int main()
{
  int T;
  int kase = 1;
  while(cin >> T)
  {
    while(T--)
    {
      cin >> n >> m;
      ans = n * m;
      for (int i = 0; i < n; i++)
      {
        cin >> grid[0][i];
      }
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          for (int k = i; k < n; k++)
          {
            for (int s = k == i ? j : 0; s < m; s++)
            {
              if (grid[0][i][j] == '#' && grid[0][k][s] == '#')
              {
                grid[0][i][j] = grid[0][k][s] = '*';
                int t = 0;
                while(set_fire(++t));
                t--;
                if (is_burned(t))
                {
                  ans = min(ans, t);
                //  cout << t << endl;
                }
                grid[0][i][j] = grid[0][k][s] = '#';
              }
            }
          }
        }
      }
      if (ans == m * n) ans = -1;
      cout <<"Case "<< kase++<<": "<< ans << endl;
    }
  }
}
