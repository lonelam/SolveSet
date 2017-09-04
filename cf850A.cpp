#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
set<int> rem;
int x[maxn][5];
// is acute
bool check(int a, int b, int c)
{
  int sum = 0;
  for (int i = 0; i < 5; i++)
  {
    sum += (x[b][i] - x[a][i]) * (x[c][i] - x[a][i]);
  }
  return sum > 0;
}
void elim()
{
  for (int a: rem)
  {
    for (int b: rem)
    {
      if (a == b) continue;
      for (int c : rem)
      {
        if (a == c || b == c) continue;
        set<int> out;
        if (check(a, b, c)) out.insert(a);
        if (check(b, a, c)) out.insert(b);
        if (check(c, a, b)) out.insert(c);
        for (int o : out)
        {
          rem.erase(o);
        }
        return;
      }
    }
  }
}
int n;
bool check2(int t)
{
    for (int i = 0; i < n; i++)
    {
      if (i == t) continue;
      for (int j = i + 1; j < n; j++)
      {
        if (j == t) continue;
        if (check(t, i, j))
        {
          return false;
        }
      }
    }
    return true;
}
void solve()
{
  while(rem.size() >= 3)
  {
    elim();
  }
  set<int> ans;
  for (int t: rem)
  {
    if (check2(t))
    {
      ans.insert(t);
    }
  }
  printf("%d\n", (int)ans.size());
  for (int o: ans)
    printf("%d\n", o + 1);
}
int main()
{
  while(~scanf("%d", &n))
  {
    rem.clear();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        scanf("%d", x[i] + j);
      }
      rem.insert(i);
    }
    solve();
  }
}
