#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m;
vector<pair<int,ll> > G[maxn];
int L, R, S;
ll presum[maxn];
bool dfs(int u, ll tar)
{
  if (presum[u] != -1)
  {
    if (presum[u] == tar)
    return true;
    return false;
  }
  presum[u] = tar;
  for (pair<int,ll> e: G[u])
  {
    if(!dfs(e.first, tar + e.second))
     return false;
  }
  return true;
}
bool check()
{
  for (int i = 0; i <= n; i++)
  {
    if (presum[i] == -1)
    {
      if (!dfs(i, 0))
       return false;
    }
  }
  return true;

}
int main()
{
 freopen("1.in", "r", stdin);
  while(cin >> n >> m)
  {
    memset(presum, -1, sizeof(presum));
    for (int i = 0; i <= n; i++) G[i].clear();
    for(int i = 0; i < m; i++)
    {
      cin >> L >> R >> S;
      G[L-1].push_back({R, S});
      G[R].push_back({L-1, -S});
    }
    if(check())
    {
      cout << "Unknown!" << endl;
    }
    else
    {
      cout << "Error!" << endl;
    }
  }
}
