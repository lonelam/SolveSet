#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300 + 100;
int n, a, b, k, f;
char from[maxn];
char to[maxn];
string pre = "";
map<pair<string,string>, int> cnt;
vector<int> to_do;
void update(string f, string t)
{
  int g = a;
  if (f == pre)
  {
    g = b;
  }
  pre = t;
  if (f > t) swap(f, t);
  cnt[{f, t}] += g;
}
int main()
{
  scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
  for (int i = 0; i < n; i++)
  {
    scanf("%s%s", from, to);
    update(from, to);
  }
  int ans = 0;
  for (auto p: cnt)
  {
    ans += p.second;
    if (p.second > f)
    {
      to_do.push_back(p.second - f);
    }
  }
  sort(to_do.begin(), to_do.end());
  reverse(to_do.begin(), to_do.end());
  for (int i = 0; i < k && i < to_do.size(); i++)
  {
    ans -= to_do[i];
  }
  printf("%d\n", ans);
}
