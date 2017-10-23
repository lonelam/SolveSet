#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int main()
{
  int x1, y2, x2, y1;
  while(cin >> x1 >> y1)
  {
    cin >> x2 >> y2;
    int dx = max(abs(x1 - x2) + 1, 2), dy = max(abs(y1 - y2) + 1, 2);
    cout << ((dx + dy) * 2) << endl;
  }
}
