#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string cmd;
set<string> p;
int main()
{
  int cnt = 0;
  while(getline(cin, cmd) && cmd[0] != '!')
  {
    if (cmd[0] == '+')
    {
      // cout << cmd.substr(1, cmd.size() - 1) << endl;
      p.insert(cmd.substr(1, cmd.size() - 1));
    }
    else if (cmd[0] == '-')
    {
      p.erase(cmd.substr(1, cmd.size() - 1));
    }
    else
    {
      // cout << p.size() << endl;
      // cout << (cmd.size() - cmd.find(':') - 1) << endl;
      cnt += p.size() * (cmd.size() - cmd.find(':') - 1);
    }
  }
  cout << cnt << endl;
}
