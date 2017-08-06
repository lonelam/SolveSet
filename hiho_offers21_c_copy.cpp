#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
typedef pair<int, pair<int, int> > pii;
int n, m, k,q;
pair<int, int> Q[10], S, T;
int d[8][2] ={0,1,1,0,0,-1,-1,0,1,1,-1,1,1,-1,-1,-1};

int dis(pair<int,int > P)
{
  return abs(P.X - T.X) + abs(P.Y - T.Y);
}
int ok(pair<int, int> P)
{
  if (P.X < 0 || P.X > n || P.Y < 0 || P.Y > m)
  {
    return 0;
  }
  for (int i = 0; i < q; i++)
  {
    if (abs(P.X - Q[i].X) + abs(P.Y - Q[i].Y) < k) return 0;
  }
  return 1;
}
bool BFS()
{
  priority_queue<pii> Q;
  if (ok(S) == 0 || ok(T) == 0) return 0;
  if (S == T) return 1;
  set<pair<int,int> > vis;
  Q.push({-dis(S), S});
  vis.insert(S);
  int cnt = 0;
  while(!Q.empty())
  {
    pii tmp = Q.top();
    Q.pop();
    cnt++;
    if (cnt > 1e4) return 0;
    for (int i=  0; i < 8; i++)
    {
      pii nex = MP
    }
  }
}
