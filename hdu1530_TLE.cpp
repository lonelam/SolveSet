
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 55;
bool adj[maxn][maxn];
int n;
int ans;
void dfs(vector<int> & s, int d)
{
  ans = max(ans, d);
  for (int i = 0; i < s.size(); i++)
  {
    vector<int> ts;
    for (int j = i + 1; j < s.size(); j++)
    {
      if (adj[s[i]][s[j]])
      {
        ts.push_back(s[j]);
      }
    }
    if (d + ts.size() + 1> ans)
    {
      dfs(ts, d + 1);
    }
  }
}
int main()
{
  while(scanf("%d", &n) != EOF && n)
  {
    ans = 0;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        scanf("%d", adj[i] + j);
      }
      a.push_back(i);
    }
    dfs(a, 0);
    printf("%d\n", ans);
  }
}
