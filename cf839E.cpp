#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll G[maxn];
int ans;
int n;
inline int ctz(ll s)
{
  return s ? __builtin_ctzll(s): 64;
}
void dfs(ll st, ll allow, ll forbid)
{
  if (!allow)
  {
    ans = max(ans, __builtin_popcountll(st));
    return;
  }
  int pivot = ctz(allow);
  ll z = allow & G[pivot];
  for (int u = ctz(z); ; )
}
