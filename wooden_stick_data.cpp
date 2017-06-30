#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
random_device rd;
int main()
{
  freopen("3.in", "w", stdout);
  int n = 5000;
  int T = 10;
  cout << T << endl;
  while(T--)
  {
    cout << n << endl;
    uniform_int_distribution<int> rndn(1, 10000);
    for (int i = 0; i < 2*n-1; i++)
    {
      cout << rndn(rd) << " ";
    }
    cout << rndn(rd) << endl;

  }
}
