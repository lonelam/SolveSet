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
  int n;
  while(cin >> n)
  {
    if (n <= 3)
    {
      cout << -1 << endl;
      continue;
    }
    string line;
    if (n & 1)
    {
      cout << "164";
      for (int i = 3; i < n; i++) cout << '0';
      cout << endl;
    }
    else
    {
      cout << "1144";
      for (int i = 4; i < n; i++)
      {
        cout << '0';
      }
      cout << endl;
    }
  }
}
