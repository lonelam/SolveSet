#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
struct node
{
  int x, y;
}ns[maxn];
int n, m, k;
int dis[maxn];
int start = -1;
struct edge
{
  int v, w;
} es[maxn * 2];
int etot = 0;
vector<int> G[maxn];
void addedge(int u, int v, int w)
{
  es[etot] = {v, w};
  G[u].push_back(etot++);
}
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int inq[maxn];
void spfa()
{
  dis[start] = 0;
  inq[start] = 1;
  queue<int> Q;
  Q.push(start);
  while(!Q.empty())
  {
    int cur = Q.front();
    Q.pop();
    inq[cur] = 0;
    for (int i = 0; i < G[cur].size(); i++)
    {
      edge & e = es[G[cur][i]];
      if (dis[e.v] > dis[cur] + e.w)
      {
        dis[e.v] = dis[cur] + e.w;
        if (!inq[e.v])
        {
          inq[e.v] = 1;
          Q.push(e.v);
        }
      }
    }
  }
}
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  memset(dis, inf, sizeof(dis));
  int row_begin = k;

  int col_begin = k + n * 2;
  int tot = col_begin + m * 2;
  map<pair<int, int> ,int> mid;
  for (int i = 0; i < k; i++)
  {
    scanf("%d%d", &ns[i].x, &ns[i].y);
    ns[i].x--;
    ns[i].y--;
    if (ns[i].x == 0 && ns[i].y == 0) start = i;
    addedge(row_begin + ns[i].x, i, 0);
    addedge(i, row_begin + ns[i].x + n, 0);
    addedge(col_begin + ns[i].y, i, 0);
    addedge(i, col_begin + ns[i].y + m, 0);
    mid[{ns[i].x, ns[i].y}] = i;
  }
  if (start == -1)
  {
    printf("-1\n");

    return 0;
  }
  for (int i = 0; i < k; i++)
  {
    for (int d = 0; d < 4; d++)
    {
      int tx = ns[i].x + dx[d];
      int ty = ns[i].y + dy[d];
      if (tx >= 0 && tx < n && ty >= 0 && ty < m)
      {
        if (mid.find({tx, ty}) != mid.end())
        {
          int tar = mid[{tx,ty}];
          addedge(i, tar, 0);
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int d = -2; d <= 2; d++)
    {
      //if (!d) continue;
      int tar = i + d;
      if (tar >= 0 && tar < n)
      {
        addedge(row_begin + i + n, row_begin + tar, 1);
      }
    }
  }
  for (int i = 0; i < m; i++)
  {
    for (int d = -2; d <= 2; d++)
    {
      //if (!d) continue;
      int tar = i + d;
      if (tar >= 0 && tar < m)
      {
        addedge(col_begin + i + m, col_begin + tar, 1);
      }
    }
  }
  spfa();
  int ans = inf;
  for (int i = n - 1; i >= 0 && i >= n - 2; i--)
  {
    for (int j = 0; j < m; j++)
    {
      if (mid.find({i, j}) != mid.end())
      {
        ans = min(ans, dis[mid[{i,j}]] + 1);
  //      cout << i <<" "<< j <<" "<< dis[mid[{i,j}]] << endl;
      }
    }
  }
//  cout << ans << endl;
  for (int j = m - 1; j >= 0 && j >= m - 2; j--)
  {
    for (int i = 0; i < n; i++)
    {
      if (mid.find({i, j}) != mid.end())
      {
        ans = min(ans, dis[mid[{i,j}]] + 1);
      }
    }
  }
  //cout << ans << endl;
/*  for (int i = 0; i < k; i++)
  {
    cout << ns[i].x << " "<< ns[i].y <<" "<< dis[i] << endl;
  }*/
  if (mid.find({n-1,m-1}) != mid.end())
  {
    ans =min(ans, dis[mid[{n-1,m-1}]]);
  }
  else {if (mid.find({n-1,m-2}) != mid.end())
  {
    ans = min(ans,dis[mid[{n-1,m-2}]] + 1);
  }
  if (mid.find({n-2,m-1}) != mid.end())
  {
    ans = min(ans,dis[mid[{n-2,m-1}]] + 1);
  }}

  if(ans == inf) ans = -1;
  printf("%d\n", ans);
}
