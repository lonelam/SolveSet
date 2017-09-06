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
  int T;
  int N;
  while(cin >> T)
  while(T-- && cin >> N)
  {
    ll n = floor(sqrt(N / 2.0));
    // ll low = 2 * (ll)n * (ll)n;
    // ll up = 2LL * (ll)(n + 1) * (ll)(n + 1);
    if (N == 2 * n * n)
    {
      cout << 4 * n << endl;
    }
    else if (N <= 2 *n * n + n - 1)
    {
      cout << 4 * n + 1 << endl;
    }
    else if (N <= 2 * n * n + 2 * n)
    {
      cout << 4 * n + 2 << endl;
    }
    else if (N <= 2 * n * n + 3 * n)
    {
      cout << 4  * n + 3 << endl;
    }
    else
    {
      cout << 4 * n + 4 << endl;
    }
  }
}
