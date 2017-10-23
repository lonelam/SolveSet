#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n, m;
string r, tmp;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> r;
  cin >> m;
  set<char> rem, nex, reveal;
  for (char c = 'a'; c <= 'z'; c++)
  {
    rem.insert(c);
  }
  for (int i = 0; i < n; i++)
  {
    if (r[i] != '*')
    {
      reveal.insert(r[i]);
    }
    if (r[i] != '*' && rem.find(r[i]) != rem.end())
    {
      rem.erase(r[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    cin >> tmp;
    bool isvalid = true;
    for (int j = 0; j < n; j++)
    {
      if (r[j] != '*')
      {
        if (tmp[j] != r[j])
        {
          isvalid = false;
          break;
        }
      }
      else
      {
        if (reveal.find(tmp[j]) != reveal.end())
        {
          isvalid = false;
          break;
        }
      }
    }
    if (isvalid)
    {
        nex.clear();
      for (int j = 0; j < n; j++)
      {
        if (r[j] == '*')
        {
          if (rem.find(tmp[j]) != rem.end())
          {
            nex.insert(tmp[j]);
          }
        }
      }
      swap(nex, rem);
    }
  }
  cout << rem.size() << endl;
}
