#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
struct state
{
  int s[6][6];
  int zx, zy;
  void output()
  {
    for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        cout << s[i][j] << " ";
      }
      cout << endl;
    }
  }
  bool operator< (const state & rhs) const
  {
    if (zx != rhs.zx) return zx < rhs.zx;
    if (zy != rhs.zy) return zy < rhs.zy;
    for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        if (s[i][j] != rhs.s[i][j])
        {
          return s[i][j] < rhs.s[i][j];
        }
      }
    }
    return false;
  }
  bool operator==(state & rhs)
  {
    if (zx != rhs.zx || zy != rhs.zy) return false;
    for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        if (s[i][j] != rhs.s[i][j])
        {
          return false;
        }
      }
    }
    return true;
  }
} tar;
int ans;
int dx[] = {1, 1, -1, -1};
int dy[] = {0, 1, 0, -1};
map<state, bool> vis;
void dfs(state & s, int d)
{
  if (vis[s]) return;
  if (d > 20)
  {
    return;
  }
  // if (rand() & 1) return;
  vis[s] = true;
  // s.output();
  if (s == tar)
  {
    ans = min(ans, d);
    return;
  }
  if (d >= ans)
  {
    return;
  }
  bool flg = false;
  for (int i = s.zx + 1; i < 6; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (s.s[i][j] != i)
      {
        flg = true;
      }
    }
  }
  for (int dir = flg?0:2; dir < 4; dir++)
  {
    int tx = s.zx + dx[dir];
    int ty = s.zy + dy[dir];
    if (tx >= 6 || ty > tx) continue;
    state t = s;
    t.zx = tx;
    t.zy = ty;
    swap(t.s[tx][ty], t.s[s.zx][s.zy]);
    dfs(t, d + 1);
  }
}
int main()
{
  srand(time(0));
  state init;
  int T;
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      tar.s[i][j] = i;
    }
  }
  tar.zx = tar.zy = 0;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      vis.clear();
      for (int i = 0; i < 6; i++)
      {
        for (int j = 0; j <= i; j++)
        {
          scanf("%d", &init.s[i][j]);
          if (init.s[i][j] == 0)
          {
            init.zx = i;
            init.zy = j;
          }
        }
      }
      ans = inf;
      dfs(init, 0);
      if (ans == inf)
      {
        printf("too difficult\n");
      }
      else
      {
        printf("%d\n", ans);
      }
    }
  }
}
