#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 17, chsize = 26;
int n;
bool good[chsize];
string goods, pat;
bool mat(string pat, string s)
{
  if (pat.size() != s.size()) return 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (pat[i] != '?')
    {
      if (s[i] != pat[i])
      {
        return 0;
      }
    }
    else if (!good[s[i] - 'a']) return 0;
  }
  return 1;
}
int main()
{
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> goods >> pat >> n;
  for (auto c : goods)
  {
    good[c - 'a'] = 1;
  }
  auto p = pat.find('*');
  for (string s; n --;)
  {
    cin >> s;
    if (s.size() < pat.size() - 1)
    {
      cout << "NO\n";
    }
    else if (p == string ::npos)
    {
      cout << (mat(pat, s) ? "YES": "NO") << endl;

    }
    else
    {
      bool ok = 1;
      ok &= mat(pat.substr(0, p), s.substr(0, p));
      reverse(pat.begin(), pat.end());
      reverse(s.begin(), s.end());
      p = pat.size() - p - 1;
      ok &= mat(pat.substr(0, p), s.substr(0, p));
      reverse(pat.begin(), pat.end());
      reverse(s.begin(), s.end());
      p = pat.size() - p - 1;
      for (int i = p; i < s.size() - (pat.size() - p - 1) ; i++)
      {
        ok &= !good[s[i] - 'a'];
      }
      cout << (ok?"YES":"NO") << endl;
    }
  }
  return 0;
}
