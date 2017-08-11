#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int h[maxn];
int main()
{
  int n;
  bool st = false;
  while(cin >> n && n)
  {
    if (st)
    {
      cout << "\n";
    }
    else
    {
      st = true;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> h[i];
      sum += h[i];
    }
    int avg = sum / n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += abs(avg - h[i]);
    }
    cout << ans / 2 << endl;
  }
}
