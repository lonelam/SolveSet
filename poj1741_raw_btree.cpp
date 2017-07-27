#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 100;
int tot, sz[maxn], key[maxn], ch[maxn][2];//, pre[maxn];
int n, k;
int ans;
int dis[maxn];
void newnode(int & pos, int _key)
{
  key[tot] = _key;
  sz[tot] = 1;
  ch[tot][0] = ch[tot][1] = 0;
//  pre[tot] = fa;
  pos = tot++;
}
void pushup(int x)
{
  if (!x) return;
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}
void rotate(int x,int & xpos, int d)
{
  const int y = ch[x][d], z = ch[y][d^1];
  xpos = y;
  ch[y][d^1] = x;
  ch[x][d] = z;
  pushup(x);
  pushup(y);
}
void insert_node(int & tree, int node)
{
  if (tree == 0)
  {
    tree = node;
    return;
  }
  if (key[tree] >= key[node])
  {
    insert_node(ch[tree][0], node);
  }
  else
  {
    insert_node(ch[tree][1], node);
  }
  pushup(tree);
}
void acc_less(int r, int t)
{
  if (!r) return;
  if (key[r] <= t)
  {
    ans += sz[ch[r][0]] + 1;
    //cout << sz[ch[r][0]] << endl;
    acc_less(ch[r][1], t);
  }
  else
  {
    acc_less(ch[r][0], t);
  }
}
///trail equals double dis to current root
void insert_tree(int raw, int tar, int trail)
{
  if (tar == 0) return;
  insert_tree(raw, ch[tar][0], trail);
  insert_tree(raw, ch[tar][1], trail);
  sz[tar] = 1;
  ch[tar][0] = ch[tar][1] = 0;
  acc_less(raw, k + trail - key[tar]);
  //cout << k + trail - key[tar] << endl;
  insert_node(raw, tar);
}
vector<int> G[maxn];
int ecnt;
void init()
{
  tot = 1;
  sz[0] = ch[0][0] = ch[0][1] = 0;
  ans = 0;
  ecnt = 0;
  for (int i = 0; i < n; i++)
  {
    G[i].clear();
  }
}
struct edge
{
  int u, v, w;
} es[maxn * 2];

void addedge(int u, int v, int w)
{
  es[ecnt] = {u,v,w};
  G[u].push_back(ecnt++);
  es[ecnt] = {v, u, w};
  G[v].push_back(ecnt++);
}
int dfs(int cur, int parent)
{
  vector<int> trees;
  //for (int e: G[cur])
  for (int i = 0; i < G[cur].size(); i++)
  {
    const int e = G[cur][i];
    if (es[e].v != parent)
    {
      dis[es[e].v] = dis[cur] + es[e].w;
      trees.push_back(dfs(es[e].v, cur));
    }
  }
  int main_tree = 0;
  int cur_t;
  newnode(cur_t, dis[cur]);
  trees.push_back(cur_t);
//  for (int t : trees)
//cout << "***" << cur << " ";
  for (int i = 0; i < trees.size(); i++)
  {
    const int t = trees[i];
    if (sz[t] > sz[main_tree])
    {
      main_tree = t;
    }
 //   cout << t << " ";
  }
//  cout << "----" << k + 2 * dis[cur] << endl;
  //
//  for (int t: trees)
  for (int i = 0; i < trees.size(); i++)
  {
    const int t = trees[i];
    if (t != main_tree)
    {
      insert_tree(main_tree, t, 2 * dis[cur]);
    }
  }
  return main_tree;
}
int main()
{
  int u, v, l;
  while(scanf("%d%d", &n, &k) != EOF && n && k)
  {
    init();
    for (int i = 1; i < n;i ++)
    {
      scanf("%d%d%d", &u, &v, &l);
      u--;v--;
      addedge(u,v,l);
    }
    dis[0] = 0;
    dfs(0, 0);
    //for (int i = 0; i < n; i++) cout << dis[i] << endl;
    printf("%d\n", ans);
  }
}
