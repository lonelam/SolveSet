#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int c[maxn];
int main()
{
  int n;
  while(cin >> n)
  {
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> c[i];
      if (c[i] <= 35)
      {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
