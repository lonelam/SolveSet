#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
string s[maxn];
int L[500], R[500];
char line[maxn];
bool vis[500];
string ans;
bool check()
{
  for (int i = 0; i < n; i++)
  {
    set<char> st;
    for (int j = 0; j < s[i].size(); j++)
    {
      vis[s[i][j]] = true;
      if (st.find(s[i][j]) != st.end()) return false;
      st.insert(s[i][j]);
    }
    for (int j = 1; j < s[i].size(); j++)
    {
      if (L[s[i][j]] == -1 && R[s[i][j-1]] == -1)
      {
        L[s[i][j]] = s[i][j-1];
        R[s[i][j-1]] = s[i][j];
      }
      else if (L[s[i][j]] != s[i][j-1] || R[s[i][j-1]] != s[i][j])
      {
        return false;
      }
    }
  }
  int cnt = 0;
  for (char c = 'a'; c <= 'z'; c++ )
  {
    if (L[c] == -1 && R[c] != -1)
    {
      int p = c;
      while(p != -1)
      {
        ans.push_back(p);
        p = R[p];
      }
    }
    else if (L[c] == -1 && R[c] == -1 && vis[c])
    {
      ans.push_back(c);
    }
    if (vis[c])
    {
      cnt++;
    }
  }
  if (ans.size() != cnt) return false;
  return true;
}
int main()
{
  scanf("%d", &n);
  memset(L, -1, sizeof(L));
  memset(R, -1, sizeof(R));
  for (int i = 0; i < n; i++)
  {
    scanf("%s", line);
    s[i] = line;
  }
  sort(s, s + n);
  if (check())
  {
    printf("%s\n", ans.c_str());
  }
  else
  {
    printf("NO\n");
  }
}
