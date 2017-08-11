#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n,m,k;
struct socket
{
  int x, y;
  int type;
  socket(){}
  socket(int _x, int _y):x(_x),y(_y)
  {
    if (x == 0 && y != n)
    {
      type = 0;
    }
    else if (y == n && x != n)
    {
      type = 1;
    }
    else if (x == n && y != 0)
    {
      type = 2;
    }
    else if (y == 0 && x != 0)
    {
      type = 3;
    }
  }
  bool operator<(const socket & rhs) const
  {
    if (type != rhs.type)
    {
      return type < rhs.type;
    }
    if (type == 0)
    {
      return y < rhs.y;
    }
    if (type == 1)
    {
      return x < rhs.x;
    }
    if (type == 2)
    {
      return y > rhs.y;
    }
    if (type == 3)
    {
      return x > rhs.x;
    }
    return false;
  }
};
//default clockwise
int dist(socket & lhs, socket & rhs)
{
  if (lhs.type == rhs.type)
  {
    if (lhs.x != rhs.x)
    {
      return abs(lhs.x - rhs.x);
    }
    return abs(lhs.y - rhs.y);
  }
  int ret = ((rhs.type + 4 - lhs.type) % 4 - 1) * n;
  if (lhs.type == 0)
  {
    ret += n - lhs.y;
  }
  else if (lhs.type == 1)
  {
    ret += n - lhs.x;
  }
  else if (lhs.type == 2)
  {
    ret += lhs.y;
  }
  else if (lhs.type == 3)
  {
    ret += lhs.x;
  }
  if (rhs.type == 0)
  {
    ret += rhs.y;

  }
  else if (rhs.type == 1)
  {
    ret += rhs.x;
  }
  else if (rhs.type == 2)
  {
    ret += n - rhs.y;
  }
  else if (rhs.type == 3)
  {
    ret += n - rhs.x;
  }
  return ret;
}
socket S[maxn];
int main()
{
  while(scanf("%d%d%d", &n, &m, &k) != EOF)
  {
    for (int i = 0; i < m; i++)
    {
      static int tmpx, tmpy;
      scanf("%d%d", &tmpx, &tmpy);
      S[i] = socket(tmpx, tmpy);
    }
    sort(S, S + m);
    int fin = inf;
    int ans = 0;
    for (int i = 1; i < k; i++)
    {
      ans += dist(S[i-1], S[i]);
    }
    fin = min(ans, fin);
    for (int j = 0; j < m; j++)
    {
      // cout << j<<":" << dist(S[j] , S[(j + 1) % m]) <<endl;
      ans -= dist(S[j], S[(j + 1)% m]);
      ans += dist(S[(j + k - 1) % m], S[(j + k) % m]);
      fin = min(ans, fin);
      // cout << ans << endl;
    }
    printf("%d\n", fin);
  }
}
/*

5 2 2
5 1
0 4
*/
