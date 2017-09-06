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
    int a = 1, b = n - 1;
    for (int i = 1; i < n - i; i++)
    {
      if (__gcd(i, n - i) == 1)
      {
        a = i;
        b = n - i;
      }
    }
    cout << a << " "<< b << endl;
  }
}
