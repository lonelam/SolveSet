#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string line;
  map<string, int> cnt;
  while(getline(cin, line))
  {
    if (line == "####")
    {
      int m = 0;
      string mi;
      for (auto x : cnt)
      {
        if (x.second > m)
        {
          mi = x.first;
          m = x.second;
        }
      }
      cout << mi <<":" << m << endl;
      cnt.clear();
    }
    string p1, p2;
    for (int i = 0; i < line.size(); i++)
    {
      if (line[i] == ' ')
      {
        if (p1 != "" && p2 != "")
        {
          cnt[p1 + ' ' + p2] += 1;
        }
        if (p2 != "")
        {
          p1 = p2;
          p2 = "";
        }
      }
      else if (line[i] == ',' || line[i] == '.')
      {
        if (p1 != "" && p2 != "")
        {
          cnt[p1 + ' ' + p2] += 1;
        }
        p1 = p2 = "";
      }
      else
      {
        p2.push_back(line[i]);
      }
    }
    if (p1 != "" && p2 != "")
    {
      cnt[p1 + ' ' + p2] += 1;
    }
  }
}
