#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int main()
{
  int a, b, c;
  while(cin >> a >> b >> c)
  {
    int rem = a % b;
    int flg = -1;
    for (int i = 1; i < 5e7; i++)
    {
      rem *= 10;
      int d = rem / b;
      if (d == c)
      {
        flg = i;
        break;
      }
      rem %= b;
    }
    cout << flg << endl;
  }
}
