#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 26;
int m, n;
char from[60], to[60];
inline size_t idx(char x)
{
  return x - 'a';
}
vector<int> G[maxn];
bool vis[maxn][maxn];
void dfs(int r, int cur)
{
  if (vis[r][cur]) return;
  vis[r][cur] = true;
  for (int i = 0; i < G[cur].size(); i++)
  {
    if (!vis[r][G[cur][i]]) dfs(r, G[cur][i]);
  }
}
bool check()
{
  int fn = strlen(from), tn = strlen(to);
  if (fn != tn) return false;
  for (int i =0; i < fn; i++)
  {
    if (!vis[idx(from[i])][idx(to[i])]) return false;
  }
  return true;
}
int main()
{
  while(cin >> m >> n)
  {
    for (int i = 0; i < maxn; i++) G[i].clear();
    for (int i = 0; i < m; i++)
    {
      cin >> from >> to;
      G[idx(from[0])].push_back(idx(to[0]));
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < maxn; i++)
    {
      dfs(i, i);
    }
    for (int i = 0; i < n; i++)
    {
      cin >> from >> to;
      if (check()) cout << "yes\n";
      else cout << "no" << endl;
    }
  }
}
