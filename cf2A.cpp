#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
  map<string, int> ans;
  int n;
  cin >> n;
  string name[1005];
  set<string> st;
  int score[1005];
  string winner;
  int m = -inf;
  for (int i = 0; i < n; i++)
  {
    cin >> name[i] >> score[i];
    ans[name[i]] += score[i];
    // if (score > 0 || last.find(name) == last.end())
  }
  for (auto p : ans)
  {
    if (p.second > m)
    {
      m = p.second;
    }
  }
  for (auto p: ans)
  {
    if (p.second == m)
    {
      st.insert(p.first);
    }
  }
  ans.clear();
  for (int i = 0; i < n; i++)
  {
    ans[name[i]] += score[i];
    if (ans[name[i]] >= m && st.find(name[i]) != st.end())
    {
      winner = name[i];
      break;
    }
  }
  cout << winner << endl;
}
