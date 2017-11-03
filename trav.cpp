#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 31;
int n;
int G[maxn][maxn];
int ans = inf;
int tar;
int s;
void dfs(int cur, int d, set<int> & rem)
{
  if (tar >= ans) return;
  if (d == n)
  {
    if (G[cur][s] != -1)
    ans = min(ans, tar + G[cur][s]);
    return;
  }
  for (int i : rem)
  {
    if (G[cur][i] != -1)
    {
  //vis[cur] = true;
      set<int> tmp = rem;
      tar += G[cur][i];
      tmp.erase(i);
      dfs(i, d+1, tmp);
      tar -= G[cur][i];
  //vis[cur] = false;
    }
  }
}
int main()
{
  int kase = 1;

  while(cin >> n)
  {
    set<int> rem;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> G[i][j];
      }
      rem.insert(i);
    }
    ans = inf;
    tar = 0;
    for (int i = 0; i < n; i++)
    {
      //vis[i] = true;
      rem.erase(i);
      s = i;
      dfs(i, 1, rem);
      rem.insert(i);
      //vis[i] = false;
    }
    cout << "Case " << kase++ << endl;
    if (ans == inf)
    {
      cout << "No loop" << endl;
    }
    else
    {
      cout << ans << endl;
    }
  }
}
