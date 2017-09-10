#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 100;
const int maxk = 200;
//0 refers Alice turn, 1 refers Bob turn
// int dp[maxk][maxn][2];
map<int, int> dp;
int n;
int V[maxn];
int presum[maxn];
int sgn[2] = {1, -1};
int dfs(int k, int i, int s)
{
  // tuple<int,int,int> st = make_tuple(k,i,s);
  int st = k * maxn * 2 + i * maxk * 2 + s;
  if (dp.find(st) != dp.end())
  {
    return dp[st];
  }
  if (i + k > n)
  {
    return dp[st] = 0;
  }
  if (i + k + 1 > n)
  {
    return dp[st] = dfs(k, i + k, s ^ 1) +sgn[s] * (presum[i + k] - presum[i]);
  }
  if (s)
  {
    return dp[st] = min(dfs(k, i + k, s ^ 1)+ sgn[s] * (presum[i + k] - presum[i]), dfs(k + 1, i + k + 1, s ^ 1) + sgn[s] * (presum[i + k + 1] - presum[i]));
  }
  else
  {
    return dp[st] = max(dfs(k, i + k, s ^ 1)+ sgn[s] * (presum[i + k] - presum[i]), dfs(k + 1, i + k + 1, s ^ 1) + sgn[s] * (presum[i + k + 1] - presum[i]));
  }
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    dp.clear();
    scanf("%d", &n);
    presum[0] = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", V + i);
      presum[i + 1] = presum[i] + V[i];
    }
    int ans = dfs(1, 0, 0);
    printf("%d\n", ans);
  }
}
