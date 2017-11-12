#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
int n;
int t[maxn];
vector<int> G[maxn];
int leaf = 0;
void dfs(int u = 0)
{
  if (G[u].size() == 0) leaf++;
  for (int v: G[u])
  {
    dfs(v);
  }
}
int main()
{
  while(~scanf("%d", &n))
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", t + i);
      G[t[i]].push_back(i);
    }
    dfs();
    printf("%d\n", leaf);
  }
}
