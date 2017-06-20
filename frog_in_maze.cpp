#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 400 + 5;
int n, m, nm, k;
struct mat
{
  ld a[maxn][maxn];
  mat()
  {
    memset(a, 0, sizeof(a));
  }
  void init()
  {
    for (int i = 0; i < nm; i++)
    {
      a[i][i] = 1;
    }
  }
  mat operator*(mat & rhs)
  {
    mat ans;
    for (int k = 0; k < nm; k++)
    for (int i = 0; i < nm; i++)
    {
      for (int j = 0; j < nm; j++)
      {
        ans.a[i][j] += a[i][k] * rhs.a[k][j];
      }
    }
    return ans;
  }
} raw;
mat operator^(mat base, int t)
{
  mat mask = base;
  //mat ans;
  //ans.init();
  while(t--)
  {
  /*  if (t & 1)
    {
      ans = ans * mask;
    }*/
    mask = mask * mask;
  }
  return mask;
}
char grid[25][25];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  nm = n * m;
  for (int i = 0; i < n; i++)
  {
    scanf("%s", grid[i]);
  }
  vector<int> T;
  int S = -1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 'A') S = i * m + j;
      else if (grid[i][j] == '%')
      {
        T.push_back(i * m + j);
        raw.a[i * m + j][i * m + j] = 1;
      }
      if (grid[i][j] == 'O' || grid[i][j] == 'A')
      {
        int cnt = 0;
        for (int d = 0; d < 4; d++)
        {
          int tx = i + dx[d];
          int ty = j + dy[d];
          if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] != '#')
          {
            cnt++;
          }
        }
        if (cnt == 0) continue;
        ld poss = ((ld) 1) / cnt;
        for (int d = 0; d < 4; d++)
        {
          int tx = i + dx[d];
          int ty = j + dy[d];
          if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] != '#')
          {
            raw.a[i * m + j][tx * m + ty] = poss;
          }
        }
      }
    }
  }
  int x1, y1, x2, y2;
  for (int i = 0; i < k; i++)
  {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--;y1--;x2--;y2--;
    for (int j = 0; j < nm; j++)
    {
      swap(raw.a[j][x1 * m + y1], raw.a[j][x2 * m + y2]);
    }
  }
  /*
  for (int i = 0; i < nm; i++)
  {
    for (int j = 0; j < nm; j++)
    {
      cout << raw.a[i][j]<<"  ";
    }
    cout << endl;
  }*/
  mat ans = raw ^ 21;
  ld acc = 0;
  for (int i = 0; i < T.size(); i++)
  {
    acc += ans.a[S][T[i]];
  }
  printf("%.7lf", acc);
}
