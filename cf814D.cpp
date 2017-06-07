#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n;
struct circ
{
  int x, y, r;
  bool operator<(const circ & rhs) const
  {
    return r < rhs.r;
  }
  ld area()
  {
    return M_PI * (ld) r * (ld) r;
  }
} cs[maxn];
bool cover(circ & lhs, circ & rhs)
{
  int dx = lhs.x - rhs.x;
  int dy = lhs.y - rhs.y;
  ld dis = sqrt(ld((ld)dx * (ld)dx + (ld)dy * (ld)dy));
  return dis < (ld)lhs.r / 2.0 + rhs.r;
}
vector<int> G[maxn];
int fa[maxn];
int tag[maxn];
void bfs()
{
  queue<int> cur, nex;
  for (int i = 0; i < n; i++)
  {
    if (fa[i] == -1)
    {
      cur.push(i);
    }
  }
  int d = 0;
  while(!cur.empty())
  {
    int tmp;
    if (d <= 1)
    {
      tmp = 1;
    }
    else if (d & 1)
    {
      tmp = 1;
    }
    else
    {
      tmp = -1;
    }
    while(!cur.empty())
    {
      int c = cur.front();
      cur.pop();
      tag[c] = tmp;
      for (int x : G[c])
      {
        nex.push(x);
      }
    }
    d++;
    swap(cur, nex);
  }
}
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &cs[i].x, &cs[i].y, &cs[i].r);
    }
    memset(fa, -1, sizeof(fa));
    sort(cs, cs + n);
    for (int i = 0; i < n; i++)
    {
      G[i].clear();
      for (int j = 0; j < i; j++)
      {
        if (fa[j] == -1 && cover(cs[j], cs[i]))
        {
          fa[j] = i;
          G[i].push_back(j);
        }
      }
    }
    bfs();
    ld ans = 0;
    for (int i = 0; i < n; i++)
    {
      //cout << cs[i].r <<"  "<< tag[i] << endl;
      ans += cs[i].area() * tag[i];
    }
//    cout << ans << endl;
    printf("%.10Lf\n", ans);
  }
}
