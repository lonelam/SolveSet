#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
map<string, string> fa;
map<string, int> rnk;
string fnd(string x)
{
  if (fa[x] == x)
  {
    return x;
  }
  return fa[x] = fnd(fa[x]);
}
void join(string u, string v)
{
  string fu = fnd(u);
  string fv = fnd(v);
  if (fu == fv) return;
  if (rnk[fu] == rnk[fv])
  {
    rnk[fu]++;
    fa[fv] = fu;
    return;
  }
  if (rnk[fu] < rnk[fv])
  {
    swap(fu,fv);
  }
  fa[fv] = fu;
  return;
}
int main()
{
  int cmd;
  int n;
  while(cin >> n)
  {
    fa.clear();
    rnk.clear();
    for (int i = 0; i < n;i ++)
    {
      string u,v;
      cin >> cmd >> u >> v;
      if (fa.find(u) == fa.end())
      {
        fa[u] = u;
        rnk[u] = 1;
      }
      if (fa.find(v) == fa.end())
      {
        fa[v] = v;
        rnk[v] = 1;
      }
      if (cmd == 0)
      {
        join(u,v);
      }
      else if (cmd == 1)
      {
        if (fnd(u) == fnd(v))
        {
          cout << "yes\n";
        }
        else
        {
          cout << "no\n";
        }
      }
    }
  }
}
