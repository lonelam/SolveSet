#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int p_m(int base, int index)
{
  base = base % 10;
  int ans = 1;
  while(index)
  {
    if (index & 1)
    {
      ans *= base;
      ans %= 10;
    }
    index >>= 1;
    base *= base;
    base %= 10;
  }
  return ans;
}
int main()
{
  int n;
  int T;
  while(cin >> T)
  {
    while(T--)
    {
      cin >> n;
      cout << p_m(n, n) << endl;
    }
  }
}
