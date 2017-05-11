#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  int n, t, k, d;
  cin >> n >> t >> k >> d;
  if (d < ((n + k - 1)/ k - 1)* t)
  {
    cout << "YES\n";
  }
  else
  {
    cout << "NO\n";
  }
}
