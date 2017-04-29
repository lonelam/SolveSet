#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
struct dir
{
  string dname;
  int deep;
  map<string, dir> subd;
  set<string> subbook;
  dir() {}
  dir(const string & nm, int dp): dname(nm), deep(dp) {}
  void show()
  {
    for (int i = 1; i < deep; i++)
    {
      cout <<"    ";
    }
    cout << dname << endl;
    for (auto sd : subd)
    {
      sd.second.show();
    }
    for (string s : subbook)
    {
      for (int i = 0; i < deep; i++)
      {
        cout << "    ";
      }
      cout <<s << endl;
    }
  }
  void insert(string s)
  {
    string::iterator slash = find(s.begin(), s.end(), '/');
    if (slash == s.end())
    {
      subbook.insert(s);
    }
    else
    {
      string name = s.substr(0, slash - s.begin());
      if (subd.find(name) == subd.end())
      {
        subd[name] = dir(name, deep + 1);
      }
      subd[name].insert(s.substr(slash - s.begin() + 1, s.size() - (slash - s.begin() + 1)));
    }
  }
} root;

int main()
{
  int kase = 1;
  root = dir("Case " + to_string(kase++) + ":", 0);
  string line;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while(getline(cin, line))
  {
    if (line == "0")
    {
      root.show();
      root = dir("Case " + to_string(kase++) + ":", 0);
    }
    else
    {
      root.insert(line);
    }
  }

  //root.show();
}
