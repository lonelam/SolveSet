#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int c[maxn];

int main()
{
  int n, A, B;
  map<int, set<int> > rcnt;
  scanf("%d%d", &n, &A);
int cntA = 0;
map<int, int> cnt;
set<int> out;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", c + i);
    if (c[i] != A)rcnt[0].insert(c[i]);
  }
  for (int i = 0; i < n; i++)
  {
    if (c[i] == A)
    {
      cntA++;
      auto ed = rcnt.lower_bound(cntA);
      vector<int> to_erase;
      for (auto it = rcnt.begin(); it != ed; it++)
      {
        for (int x : it->second)
        {
          out.insert(x);
          //cnt.erase(x);
        }
        to_erase.push_back(it->first);
      }
      for (int x : to_erase)
      {
        rcnt.erase(x);
      }
    }
    else if (out.find(c[i]) == out.end())
    {
      int & tmp = cnt[c[i]];
      rcnt[tmp].erase(c[i]);
      if (rcnt[tmp].empty())
      {
        rcnt.erase(tmp);
      }
      tmp++;
      rcnt[tmp].insert(c[i]);
    }
  }
  if (rcnt.empty())
  {
    printf("-1\n");
  }
  else
    printf("%d\n", *rcnt.begin()->second.begin());
}
