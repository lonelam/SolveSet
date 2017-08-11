#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string reduce(string r)
{
  string ret;
  bool isok=true;
  for (int i = 0; i < r.size(); i++)
  {
    if (i == r.size() -1 || r[i] != r[i + 1])
    {
      ret.push_back(r[i]);
    }
    else
    {
      i++;
      isok = false;
      while(i < r.size() && r[i] == r[i-1])
      {
        i++;
      }
      i--;
    }
  }
  if (isok) return ret;
  return reduce(ret);
}
int main()
{
  int T;
  while(cin >> T)
  {
    while(T--)
    {
      string s;
      cin >> s;
      int ans = 0;
      for (int i = 0; i <= s.size(); i++)
      {
        for (char j = 'A'; j <= 'C'; j++)
        {
          string tmp = s;
          tmp.insert(i, {j});
          // cout << tmp << "->"<<reduce(tmp) << endl;
          ans = max(ans, (int)tmp.size() - (int)reduce(tmp).size());
        }
      }
      cout << ans << endl;
    }
  }
}
