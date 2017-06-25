#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
//o white, 1 black;
int color[maxn];
int grasp[maxn];
int k[maxn];
int fa[maxn];
vector<int> G[maxn];
typedef pair<int, int> pii;
int depth[maxn];
int tip[maxn];
int opt[maxn];
int optreach[maxn];
void dfs(int cur)
{
  tip[cur] = cur;//depth[cur] - k[cur];
  depth[cur] = depth[fa[cur]] + 1;
  for (int i = 0; i < G[cur].size(); i++)
  {
    dfs(G[cur][i]);
    int tmp = tip[G[cur][i]];
    if (depth[tmp] - k[tmp] < depth[tip[cur]] - k[tip[cur]])
    {
      tip[cur] = tmp;
    }
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
  {
    scanf("%d", fa + i);
    fa[i]--;
    G[fa[i]].push_back(i);
  }
  fa[0] = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", k + i);
    optreach[i] = fa[i];
  }
  queue<int> Q;
  int ans = 0;
  Q.push(0);
  depth[0] = 0;
  priority_queue< pii, vector<pii> ,less<pii> > pQ;
  dfs(0);
  for (int i = 0; i < n; i++)
  {
    pQ.push({depth[i], i});
  }
  while(!pQ.empty())
  {
    int cur = pQ.top().second;
    pQ.pop();
    if (color[cur] == 0)
    {
      grasp[cur] = 1;
      ans++;
      int p = tip[cur];
      while(depth[p] + k[tip[cur]] > depth[tip[cur]])
      {
        //cout << p << endl;
        color[p] = 1;
        p = optreach[p];
        if (!p && depth[p] + k[tip[cur]] > depth[tip[cur]])
        {
          color[p] = 1;
          break;
        }
      }
      int end = p;
      p = tip[cur];
      while(depth[p] + k[tip[cur]] > depth[tip[cur]] && p)
      {
      //  cout << p << endl;
        int tmp = optreach[p];
        optreach[p] = end;
        p = tmp;
      }
    }
  }
  printf("%d\n", ans);
}
