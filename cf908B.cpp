#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;
typedef pair<int,int> pii;
int n, m;
int dmap[4];
char grid[maxn][maxn];
char ins[maxn * 2];
pii ss, tt;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int len;
bool check()
{
  pii cc = ss;
  for (int i = 0; i < len; i++)
  {
    cc.first += dx[dmap[ins[i]]];
    cc.second += dy[dmap[ins[i]]];
    if (cc == tt)
    {
      return true;
    }
    if (cc.first < 0 || cc.second < 0 || cc.first >= n || cc.second >= m || grid[cc.first][cc.second] == '#')
    {
      return false;
    }
  }
  return false;
}
int main()
{
  while(cin >> n >> m)
  {
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
      dmap[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%s", grid[i]);
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 'S')
        {
          ss = {i, j};
        }
        else if (grid[i][j] == 'E')
        {
          tt = {i, j};
        }
      }
    }
    scanf("%s", ins);
    len = strlen(ins);
    for (int i = 0; i < len; i++)
    {
      ins[i] -= '0';
    }
    do {
      if (check())
      {
        cnt++;
      }
    } while(next_permutation(dmap, dmap + 4));
    cout << cnt << endl;
  }
}
