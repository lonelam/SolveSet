#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;
ll a[maxn];
int main()
{
  /*
  for (int i = 2; i < 1000; i++)
  {
    cout << i <<"  ";
    memset(a, 0, sizeof(a));
    for (int j = 1; j <= i; j++)
    {
      for (int k = j; k <= i; k += j)
      {
        a[k] ^= 1;
      }
    }
    int cnt = 0;
    for (int j = 1; j <= i; j++)
    {
      if (a[j]) cnt++;
    }
    cout << cnt << endl;
  }
*/
  int n;
  cin >> n;
    ll ans = sqrt(n);
    cout << n - ans << endl;
}
