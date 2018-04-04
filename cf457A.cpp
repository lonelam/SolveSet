#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
string s;
int a[maxn];
int n;
int main()
{
  while(cin >> n)
  {
    int hh, mm;
    cin >> hh >> mm;
    int ans = 0;
    while(hh / 10 != 7 && hh % 10 != 7 && mm / 10 != 7 && mm % 10 != 7)
    {
      int k = n;
      while(k--)
      {
        mm--;
        if (mm < 0)
        {
          hh--;
          mm = 59;
        }
        if (hh < 0)
        {
          hh = 23;
        }
      }
      ans++;
    }
    cout << ans << endl;
  }
}
