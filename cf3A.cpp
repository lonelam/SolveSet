#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string dname[] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};
int dx[] = { -1,1, 0, 0,-1,-1,1,1};
int dy[] = { 0, 0, 1,-1, 1,-1,1,-1};
int tarx, tary;
int F(int x, int y)
{
  return abs(x-tarx) + abs(y - tary);
}
int main()
{
  string sp, ep;
  cin >> sp >> ep;
  int x = sp[0] - 'a';
  int y = sp[1] - '1';
  tarx = ep[0] - 'a';
  tary = ep[1] - '1';
  int cnt = 0;
  vector<string> path;
  while(x != tarx || y != tary)
  {
    int tx = x, ty = y;
    string tname;
    for (int d = 0; d < 8; d++)
    {
      int ttx = x + dx[d];
      int tty = y + dy[d];
      if (F(ttx, tty) < F(tx, ty))
      {
        tx = ttx;
        ty = tty;
        tname = dname[d];
      }
    }
    x = tx;
    y = ty;
    path.push_back(tname);
    cnt++;
  }
  cout << cnt << endl;
  for (string step: path)
  {
    cout << step << endl;
  }
}
