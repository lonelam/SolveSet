#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
set<ll> ans[11];
bool vis[10];
int pass[10][10];
ll pow10[20];
void init()
{
  pow10[0] = 1;
  for (int i = 1; i <= 11; i++)
  {
    pow10[i] = pow10[i-1]*10LL;
  }
  pass[1][3] = pass[3][1] = 2;
  pass[4][6] = pass[6][4] = pass[1][9] = pass[9][1] = pass[3][7] = pass[7][3] = pass[2][8] = pass[8][2] = 5;
  pass[1][7] = pass[7][1] = 4;
  pass[3][9] = pass[9][3] = 6;
  pass[7][9] = pass[9][7] = 8;
}
void dfs(ll cur = 0LL, int d = 0, int pre = 0)
{
  ans[d].insert(cur);
  for (int i = 1; i <= 9; i++)
  {
    if (!vis[i] && (pass[pre][i] == 0 || vis[pass[pre][i]]))
    {
      vis[i] = true;
      dfs(cur + pow10[d] * i, d + 1, i);
      vis[i] = false;
    }
  }
}
int main()
{
  init();
  dfs();
  ll output = 0LL;
  for (int i = 4; i <= 9; i++) output += ans[i].size();
  for (int i = 0; i < 10; i++)
  {
    cout << "The count of patterns of length "<< i << " is "<< ans[i].size() << endl;
  }
  cout << "Count of patterns length 4-9 is " << output << endl;
}
