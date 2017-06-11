#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  int n, m;
  int ai;
  while(cin >> n)
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> ai;
      sum += ai;
    }
    cin >> m;
    int l, r;
    int ans = -1;
    for (int i = 0; i < m; i++)
    {
      cin >> l >> r;
      if (ans != -1) continue;
      if (l <= sum && sum <= r)
      {
        ans = sum;
      }
      else if (l > sum)
      {
        ans = l;
      }
    }
    if (ans != -1)
    {
      cout << ans << endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }
}
