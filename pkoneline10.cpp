#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10;
string s1, s2;
int ans;
set<int> r;
set<pair<string, int> > vis;
void dfs(string cur, set<int> rem, int k, int d = 0)
{
  if (d + abs(cur.size() - s2.size()) >= ans)
  {
    return;
  }
  if (cur == s2)
  {
    ans = d;
    return;
  }
  if (vis.find({cur, k}) == vis.end())
  {
    return;
  }
  vis.insert({cur, k});
  string tmp;
  if (k > 0 && k <= cur.size())
  {
    dfs(cur, rem, k -1, d+1);
    tmp = cur;
    tmp.erase(k-1);
    r.insert(k-1);
  }
  if (k >= 0 && k < cur.size())
  {
    dfs(cur, rem, k + 1, d + 1);
  }
}
