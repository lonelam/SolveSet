#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 110;
int N, M, C, E;
struct character{
  int hp, at, mv, ad1, ad2, stx, sty, gr;
};
struct node
{
  int x, y, mv;
  node(int dx, int dy, int dmv): x(dx), y(dy), mv(dmv){}
  bool operator< (const node & A)const
  {
    return mv < A.mv;
  }
};

priority_queue<node> pq;
int dir[4][2] = {{1,0}, {0, 1}, {0, -1}, {-1, 0}};
bool vis[maxn][maxn];
int G[maxn][maxn];
int OC[maxn][maxn];
int dp[maxn][maxn];
bool inq[maxn][maxn];
character cs[maxn];
char cmd[200];
int cha = 0;
int ans;

bool zeromv(int x, int y, int i)
{
  if (x - 1 >= 1 && OC[x - 1][y] != cs[i].gr && OC[x - 1][y] != -1)
  {
    return true;
  }
  if (x + 1 <= N && OC[x + 1][y] != cs[i].gr && OC[x + 1][y] != -1)
  {
    return true;
  }
  if (y - 1>= 1 && OC[x][y - 1] != cs[i].gr && OC[x][y - 1] != -1)
  {
    return true;
  }
  if (y+ 1 <= M && OC[x][y + 1] != cs[i].gr && OC[x][y + 1] != -1)
  {
    return true;
  }
  return false;
}

bool spfa(int x, int y)
{
  if (cs[cha].stx == x && cs[cha].sty == y)
  {
    ans = cs[cha].mv;
    return true;
  }
  if (OC[x][y] != -1) return false;
  memset(vis, 0, sizeof(vis));
  memset(dp, -1, sizeof(dp));
  memset(inq, 0, sizeof(inq));
  queue<pair<int, int> > Q;
  Q.push({cs[cha].stx, cs[cha].sty});
  dp[cs[cha].stx][cs[cha].sty] = cs[cha].mv;
  inq[cs[cha].stx][cs[cha].sty] = true;
  while(!Q.empty())
  {
    int cx = Q.front().first, cy = Q.front().second;
    Q.pop();
    inq[cx][cy] = false;
    for (int i = 0; i < 4; i++)
    {
      int tx = cx + dir[i][0];
      int ty = cy + dir[i][1];
      if (tx >= 1 && tx <= N && ty >= 1 && ty <= M && OC[tx][ty] == -1 && dp[cx][cy] >= G[tx][ty])
      {
        if (zeromv(tx, ty, cha))
        {
          dp[tx][ty] = 0;
        }
        else if (dp[cx][cy] - G[tx][ty] > dp[tx][ty])
        {
          dp[tx][ty] = dp[cx][cy] - G[tx][ty];
          if (!inq[tx][ty])
          {
            inq[tx][ty] = true;
            Q.push({tx, ty});
          }
        }
      }
    }
  }
  if (dp[x][y] != -1)
  {
    OC[cs[cha].stx][cs[cha].sty] = -1;
    cs[cha].stx = x;
    cs[cha].sty = y;
    OC[x][y] = cs[cha].gr;
    ans = dp[x][y];
    return true;
  }
  return false;
}
bool bfs(int x, int y)
{
  if (cs[cha].stx == x && cs[cha].sty == y)
  {
    ans = cs[cha].mv;
    return true;
  }
  if (OC[x][y] != -1) return false;
  memset(vis, 0, sizeof(vis));
  while(!pq.empty())
  {
    pq.pop();
  }
  pq.push(node(cs[cha].stx, cs[cha].sty, cs[cha].mv));
  vis[cs[cha].stx][cs[cha].sty] = 1;
  while(!pq.empty())
  {
    node nd = pq.top(); pq.pop();
    if (nd.x == x && nd.y == y)
    {
      if (nd.mv >= 0)
      {
        OC[cs[cha].stx][cs[cha].sty] = -1;
        cs[cha].stx = x;
        cs[cha].sty = y;
        OC[x][y] = cs[cha].gr;
        ans = nd.mv;
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      for (int i = 0; i < 4; i++)
      {
        int dx = nd.x + dir[i][0];
        int dy = nd.y + dir[i][1];
        int dmv;
        if ((!vis[dx][dy]) && OC[dx][dy] == -1 && (nd.mv - G[dx][dy] >= 0) && dx >= 1 && dx <= N && dy >= 1 && dy <= M)
        {
          if (zeromv(dx, dy, cha))
          {
            dmv = 0;
          }
          else
          {
            dmv = nd.mv - G[dx][dy];
          }
          pq.push(node(dx, dy, dmv));
          vis[dx][dy] = 1;
        }
      }
    }
  }
  return false;
}
int manhat(int x1, int y1, int x2, int y2)
{
  return abs(x1 - x2) + abs(y1 - y2);
}
int main()
{
  while(scanf("%d%d%d%d", &N, &M, &C, &E)!= EOF)
  {
    memset(G, 0, sizeof(G));
    memset(OC, -1, sizeof(OC));
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= M; j++)
      {
        scanf("%d", &G[i][j]);
        OC[i][j] = -1;
      }
    }
    for (int i = 1; i <= C; i++)
    {
      scanf("%d%d%d%d%d%d%d%d", &cs[i].hp, &cs[i].at, &cs[i].mv, &cs[i].ad1, &cs[i].ad2, &cs[i].stx, &cs[i].sty, &cs[i].gr);
      OC[cs[i].stx][cs[i].sty] = cs[i].gr;
    }
    scanf("\n");
    for (int i = 0; i < E; i++)
    {
      fgets(cmd, 199, stdin);
      if (cmd[0] == 'A' && cmd[1] == 'c')
      {
        sscanf(cmd, "Action of character %d", &cha);
      }
      else if (cmd[0] == 'M')
      {
        int x, y;
        sscanf(cmd, "Move to (%d,%d)", &x, &y);
        //bool ok = bfs(x, y);
        bool ok = spfa(x, y);
        if (!ok)
        {
          printf("INVALID\n");

        }
        else
        {
          printf("%d\n", ans);
        }

      }
      else if (cmd[0] == 'A')
      {
        int id;
        sscanf(cmd, "Attack %d", &id);
        int dis = manhat(cs[id].stx, cs[id].sty, cs[cha].stx, cs[cha].sty);
        if (dis >= cs[cha].ad1 && dis <= cs[cha].ad2 && cs[id].hp > cs[cha].at)
        {
          cs[id].hp -= cs[cha].at;
          printf("%d\n", cs[id].hp);
        }
        else
        {
          printf("INVALID\n");
        }
      }
      else if (cmd [0] == 'D')
      {
        int id;
        sscanf(cmd, "Drive out %d", &id);
        int dis = manhat(cs[id].stx, cs[id].sty, cs[cha].stx, cs[cha].sty);
        if (dis >= cs[cha].ad1 && dis <= cs[cha].ad2 && cs[id].hp <= cs[cha].at)
        {
          cs[id].hp -= cs[cha].at;
          printf("%d\n", cs[id].hp);
          OC[cs[id].stx][cs[id].sty] = -1;
        }
        else
        {
          printf("INVALID\n");
        }
      }

    }
  }
}
