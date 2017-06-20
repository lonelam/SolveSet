#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
bool check(int x, int y)
{
  if (x < 0 || x > 23 || y < 0 || y > 59) return false;
  return x / 10 == y % 10 && x % 10 == y / 10;
}
int rev(int x)
{
  return x / 10 + x % 10 * 10;
}
int main()
{
  int x, y;
  while(scanf("%d:%d", &x, &y))
  {
    int ans = 0;
  if (check(x, y)) cout << 0 << endl;
  else
  {
    if (x < 5 || (x >= 10 && x <= 22))
    {
      if (y < rev(x))
      {
        cout << rev(x) - y  << endl;
      }
      else
      {
        cout << 70 - (y - rev(x)) << endl;
      }
    }
    else if (x == 5)
    {
      if (y < rev(x))
      {
        cout << rev(x)- y << endl;
      }
      else
      {
        cout << 301 - y << endl;
      }
    }
    else if (x == 23)
    {
      if (y < 32)
      {
        cout << 32 - y << endl;

      }
      else
      {
        cout << 60 - y << endl;
      }
    }
    else
    {
      int s = (10 - x) * 60 + 1;
      cout << s - y << endl;
    }
  }
}
}
