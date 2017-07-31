#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n, m;
int main()
{
  while(cin >> n >> m && n != -1)
  {
    if (__gcd(n, m) == 1)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "POOR Haha\n";
    }
  }
}
