#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n, m, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char grid[maxn][maxn];
int x1, x2, y1, y2;
pair<int,int> dis[4][maxn][maxn];
bool inq[4][maxn][maxn];
struct node
{
  int d, x, y;
};
void spfa()
{
  memset(dis, inf, sizeof(dis));
  queue<node> Q;
  for (int i = 0; i < 4; i++)
  {
    dis[i][x1][y1] = {1, 0};
    Q.push({i, x1, y1});
    inq[i][x1][y1] = true;
  }
  while(!Q.empty())
  {
    node cur = Q.front();
    Q.pop();
    inq[cur.d][cur.x][cur.y] = false;
    for (int i = 0; i < 4; i++)
    {
      node t = {i, cur.x + dx[i], cur.y + dy[i]};
      if (t.x >= 0 && t.x < n && t.y >= 0 && t.y < m && grid[t.x][t.y] != '#')
      {
        if (t.d == cur.d)
        {
          if (dis[t.d][t.x][t.y].first > dis[cur.d][cur.x][cur.y].first && dis[cur.d][cur.x][cur.y].second < k)
          {
            dis[t.d][t.x][t.y] = dis[cur.d][cur.x][cur.y];
            dis[t.d][t.x][t.y].second++;
            if (!inq[t.d][t.x][t.y])
            {
              inq[t.d][t.x][t.y] = true;
              Q.push(t);
            }
          }
          else if (dis[t.d][t.x][t.y].first == dis[cur.d][cur.x][cur.y].first && dis[cur.d][cur.x][cur.y].second < k && dis[cur.d][cur.x][cur.y].second + 1 < dis[t.d][t.x][t.y].second)
          {
            dis[t.d][t.x][t.y].second = dis[cur.d][cur.x][cur.y].second + 1;
            if (!inq[t.d][t.x][t.y])
            {
              inq[t.d][t.x][t.y] = true;
              Q.push(t);
            }
          }
        }
        if (dis[t.d][t.x][t.y].first > dis[cur.d][cur.x][cur.y].first + 1)
        {
          dis[t.d][t.x][t.y].first = dis[cur.d][cur.x][cur.y].first + 1;
          dis[t.d][t.x][t.y].second = 1;
          if (!inq[t.d][t.x][t.y])
          {
            inq[t.d][t.x][t.y] = true;
            Q.push(t);
          }
        }
      }
    }
  }
}
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", grid[i]);
  }
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  if (x1 == x2 && y1 == y2)
  {
    printf("0\n");
    return 0 ;
  }
  x1--;
  y1--;
  x2--;
  y2--;
  spfa();
  int ans = inf;
  for (int i = 0; i < 4; i++)
  {
    ans = min(ans, dis[i][x2][y2].first);
  }
  if (ans == inf) ans = -1;
  printf("%d\n", ans);
}
