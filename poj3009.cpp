#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 25;
int grid[maxn][maxn];
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans = 0;
void dfs(int cx, int cy, int depth)
{
  if (depth > 10)
  {
    return;
  }
  for (int d = 0; d < 4; d++)
  {
    int tx = cx, ty = cy;
  }
}
