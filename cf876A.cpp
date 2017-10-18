#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, a, b, c;
int main()
{
  while(cin >> n >> a >> b >> c)
  {
    if (n == 1)
    {
      cout << "0" << endl;
      continue;
    }
    int sum = min(a, b);
    n -= 2;
    cout << (sum + n * min({a, b, c})) << endl;
  }
}
