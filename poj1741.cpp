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
const int maxn = 10000 + 100;
int n, q;
int tot, pre[maxn], ch[maxn][2], key[maxn], sz[maxn], root;
void pushdown(int r)
{
  if (!r) return;
}
void pushup(int x)
{
  if (!x) return;
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}
void rotate(int x, int d)
{
  const int y = pre[x];
  ch[y][!d] = ch[x][d];
  if (ch[x][d]) pre[ch[x][d]] = y;
  pre[x] = pre[y];
  if (ch[pre[y]][0] == y) ch[pre[x]][0] = x;
  else if (ch[pre[y]][1] == y) ch[pre[x]][1] = x;
  pre[y] = x;
  ch[x][d] = y;
  pushup(y);
}
bool _splay_parent(int x, int &y, int goal)
{
  return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}
void splay(int x, int goal)
{
  //pushdown(x);
  for (int y, z; _splay_parent(x, y, goal);)
  {
    if (_splay_parent(y, z, goal))
    {
      //pushdown(z);
      //pushdown(y);
      //pushdown(x);
      int d = y == ch[z][0];
      if (x == ch[y][d])
      {
        rotate(x, d ^ 1), rotate(x, d);
      }
      else
      {
        rotate(y, d), rotate(x, d);
      }
    }
    else
    {
      //pushdown(y), pushdown(x);
      rotate(x, x == ch[y][0]);
      break;
    }
  }
  pushup(x);
  if (goal == 0) root = x;
}
void newnode(int & pos, int father, int k)
{
  pre[tot] = father;
  ch[tot][0] = ch[tot][1] = 0;
  key[tot] = k;
  sz[tot] = 1;
  pos = tot++;
}
void init()
{
  tot = 0;
  newnode(root, 0, 0);
  sz[root] = 0;
  root = 1;
}
