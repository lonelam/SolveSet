#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 5;
vector<int> G[maxn];
bool ans;
bool used[maxn];
int n, k;
void dfs(int cur, int parent)
{
  used[cur] = false;
  for (int v : G[cur])
  {
    if (v != parent)
    {
      dfs(v, cur);
      if (!used[v])
      {
        if (used[cur])
        {
          ans = false;
        }
        else
        {
          used[v] = used[cur] = true;
        }
      }
      else if(k)
      {
        k--;
      }
      else
      {
        ans = false;
      }
    }
  }
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &k);
    ans = true;
    for (int i = 1; i <= n; i++)
    {
      G[i].clear();
    }
    for (int i = 2; i <= n; i++)
    {
      int fa;
      scanf("%d", &fa);
      G[fa].push_back(i);
      G[i].push_back(fa);
    }
    dfs(1,1);
    if (!used[1]) ans = false;
    if (ans)
    {
      printf("Bob\n");
    }
    else
    {
      printf("Alice\n");
    }
  }
}
