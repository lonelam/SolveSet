#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int x[maxn + 100];
int main()
{
  for (int i = 1; i <= 9; i++)
  {
    string fext = ".in";
    string outext = ".out";
    string fname(1, '0' + i);
    string ffull = fname + fext;
    freopen(ffull.c_str(), "r", stdin);
    ffull = fname + outext;
    freopen(ffull.c_str(), "w", stdout);
    map<int, set<int> > mvp;
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
      cin >> x[i];
      mvp[x[i]].insert(i);
      int tar= *mvp.rbegin()->second.begin();
      mvp.rbegin()->second.erase(tar);
      if (mvp.rbegin()->second.empty())
      {
        mvp.erase(x[tar]);
      }
      x[tar]--;
      mvp[x[tar]].insert(tar);
    }
    for (int i = 0; i < n; i++)
    {
      cout << x[i] << (i == n- 1?"\n":" ");
    }
  }
}
