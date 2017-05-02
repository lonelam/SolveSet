#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int bound[4][2] = {{1, 1}, {3, 5}, {2, 5}, {1, 3}};
int M;
tuple<int, int, int> human[maxn];
const int Lup = (int)1e9;
int L;

struct Info{
  int value, way;
  Info() {}
  Info (int value, int way): value(value), way(way) {}
};

void update(Info & a, Info b)
{
  if (a.value < b.value)
  {
    a = b;
  }
  else if (a.value == b.value)
  {
    a.way += b.way;
    a.way = min(a.way, Lup);
  }
}

Info dp[1001][2][6][6][4];

void solve()
{
  sort(human, human + M);
  reverse(human, human + M);
  for (int i = 0; i <= 1000; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < 6; k++)
      {
        for (int r = 0; r < 6; r++)
        {
          for (int w = 0; w < 4; w++)
          {
            dp[i][j][k][r][w] = Info(-1, 0);
          }
        }
      }
    }
  }
  dp[0][0][0][0][0] = Info(0, 1);
  for (int q = 0; q < M; q++)
  {
    int v, c, tp;
    tie(v, c, tp) = human[q];
    for (int i = L - c; i >= 0; --i)
    {
      for (int j = 1; j >= 0; --j)
      {
        for (int k = 5; k>= 0; --k)
        {
          for (int r = 5; r >= 0; --r)
          {
            for (int w = 3; w >= 0; --w)
            {
              if (dp[i][j][k][r][w].value < 0) continue;
              if (j + k + r + w > 10) continue;
              int ni = i + c, nj = j, nk = k, nr = r, nw = w;
              if (tp == 0) ++nj;
              else if (tp == 1) ++nk;
              else if (tp == 2) ++nr;
              else if (tp == 3) ++ nw;
              if (nj > 1 || nk > 5 || nr > 5 || nw > 3) continue;
              Info tmp = dp[i][j][k][r][w];
              tmp.value += v;
              if (j + k + r + w == 0) tmp.value += v;
              update(dp[ni][nj][nk][nr][nw], tmp);
            }
          }
        }
      }
    }
  }
  int cost = 0, value = -1, way = 0;
  for (int i = 0; i <= L; ++i)
  {
    for (int j = bound[0][0]; j <= bound[0][1]; j++)
    {
      for (int k = bound[1][0]; k <= bound[1][1]; k++)
        for (int r = bound[2][0]; r <= bound[2][1]; r++)
        {
          for (int w = bound[3][0]; w <= bound[3][1]; w++)
          {
            if (j + k + r + w != 11) continue;
            if (dp[i][j][k][r][w].value < 0) continue;
            int c = i, v = dp[i][j][k][r][w].value, n = dp[i][j][k][r][w].way;
            if (v > value)
            {
              cost = c;
              value = v;
              way = n;
            }
            else if (v == value && c < cost)
            {
              cost = c;
              way = n;
            }
            else if (v == value && c == cost)
            {
              way += n;
              way = min(Lup, way);
            }
          }
        }
    }
  }
  printf("%d %d %d\n", value, cost, way);
}

int main()
{
  int cas;
  scanf("%d", &cas);
  while(cas--)
  {
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
      static char str[1000];
      int v, c;
      scanf("%s%d%d", str, &v, &c);
      int type;
      if (str[0] == 'G') type = 0;
      else if (str[0] == 'D') type = 1;
      else if (str[0] == 'M') type = 2;
      else if (str[0] == 'F') type = 3;
      human[i] = make_tuple(v, c, type);
    }
    scanf("%d", &L);
    solve();
  }
}
