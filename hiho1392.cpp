#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 105;
int G[maxn][maxn];
int Cp[maxn][maxn];
struct character
{
  int id, hp, at, mv, ad_1, ad_2, x, y, gr;
  bool valid ;
} cs[maxn * maxn];
int N, M, C, E;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dp[maxn][maxn];
bool inq[maxn][maxn];
bool mov(int ch_no, int s_x, int s_y, int e_x, int e_y)
{
  if (e_x < 1 || e_x > N || e_y < 1 || e_y > M || Cp[e_x][e_y] && Cp[e_x][e_y] != ch_no)
  {
    return false;
  }
  memset(dp, -1, sizeof(dp));
  memset(inq, 0, sizeof(inq));
  queue<pair<int, int> > Q;
  Q.push({s_x, s_y}) ;
  dp[s_x][s_y] = cs[ch_no].mv;
  inq[s_x][s_y] = true;
  while(!Q.empty())
  {
    int c_x = Q.front().first, c_y = Q.front().second;
    Q.pop();
    inq[c_x][c_y] = false;
    for (int dd = 0; dd < 4; dd++)
    {
      int t_x = c_x + dx[dd], t_y = c_y + dy[dd];
      int mv_left = dp[c_x][c_y] - G[t_x][t_y];
      //cout << t_x << " "<< t_y << endl;
      if (t_x >= 1 && t_x <= N && t_y >= 1 && t_y <= M && mv_left >= 0 && !Cp[t_x][t_y])
      {
        bool is_control = false;
        for (int dir = 0; dir < 4; dir++)
        {
          int ox = t_x + dx[dir], oy = t_y + dy[dir];
          if (ox >= 1 && ox <= N && oy >= 1 && oy <= M && Cp[ox][oy] && cs[Cp[ox][oy]].gr != cs[ch_no].gr)
          {
            is_control = true;
            break;
          }
        }
        if (is_control) dp[t_x][t_y] = mv_left = 0;
        else if (dp[t_x][t_y] < mv_left)
        {
          dp[t_x][t_y] = mv_left;
          if (!inq[t_x][t_y])
          {
            inq[t_x][t_y] = true;
            Q.push({t_x, t_y});
          }
        }
      }
    }
  }
  /*
  for (int i = 1;i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      cout << dp[i][j] <<" ";
    }
    cout << endl;
  }
  */
  if(dp[e_x][e_y] != -1)
  {
    Cp[s_x][s_y] = 0;
    Cp[e_x][e_y] = ch_no;
    cs[ch_no].x = e_x;
    cs[ch_no].y = e_y;
    return true;
  }
  return false;
}
int main()
{
  while(scanf("%d%d%d%d", &N, &M, &C, &E)!= EOF)
  {
    memset(G, 0, sizeof(G));
    memset(Cp, 0, sizeof(Cp));
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= M; j++)
      {
        scanf("%d", G[i] + j);
      }
    }
    for (int i = 1; i <= C; i++)
    {
      scanf("%d%d%d%d%d%d%d%d", &cs[i].hp, &cs[i].at, &cs[i].mv, &cs[i].ad_1, &cs[i].ad_2, &cs[i].x, &cs[i].y, &cs[i].gr);
      cs[i].id = i;
      Cp[cs[i].x][cs[i].y] = i;
      cs[i].valid = true;
    }
    char cmd[maxn];
    int cur_id;
    int gnow;
    for (int k = 0; k < E; k++)
    {
      scanf("%s", cmd);
      if (strcmp(cmd, "Round") == 0)
      {
        scanf("%s%d", cmd, &gnow);
      }
      else if (strcmp(cmd, "Action") == 0)
      {
        scanf("%s%s%d", cmd,cmd, &cur_id);
      }
      else if (strcmp(cmd, "Drive") == 0)
      {
        int tar;
        scanf("%s%d", cmd, &tar);
        int mdis = abs(cs[tar].x - cs[cur_id].x) + abs(cs[tar].y - cs[cur_id].y);
        //cout << mdis << " " << cs[cur_id].ad_1 <<" " << cs[cur_id].ad_2<< endl;

        if (mdis >= cs[cur_id].ad_1 && mdis <= cs[cur_id].ad_2 && cs[tar].hp <= cs[cur_id].at)
        {
          cs[tar].hp -= cs[cur_id].at;
          printf("%d\n", cs[tar].hp);
          Cp[cs[tar].x][cs[tar].y] = 0;
        }
        else
        {
          printf("INVALID\n");
        }
      }
      else if (strcmp(cmd, "Move") == 0)
      {
        int ox, oy;
        scanf("%s (%d,%d)", cmd, &ox, &oy);
        //cout << cmd << ox <<" "<< oy << endl;
        if (cs[cur_id].valid && mov(cur_id, cs[cur_id].x, cs[cur_id].y, ox, oy))
        {
          printf("%d\n", dp[ox][oy]);
        }
        else
        {
          printf("INVALID\n");
        }
      }
      else if (strcmp(cmd, "Attack")== 0)
      {
        int tar;
        scanf("%d", &tar);
        int mdis = abs(cs[tar].x - cs[cur_id].x) + abs(cs[tar].y - cs[cur_id].y);
        //cout << mdis << " " << cs[cur_id].ad_1 <<" " << cs[cur_id].ad_2<< endl;

        if (cs[cur_id].gr == gnow && tar >= 1 && tar <= C && cs[cur_id].valid && cs[tar].gr != cs[cur_id].gr && mdis >= cs[cur_id].ad_1 && mdis <= cs[cur_id].ad_2 && cs[tar].hp -cs[cur_id].at > 0 && cs[tar].valid)
        {
          cs[tar].hp -= cs[cur_id].at;
          printf("%d\n", cs[tar].hp);
        }
        else
        {
          printf("INVALID\n");
        }
      }
    }
  }
}
