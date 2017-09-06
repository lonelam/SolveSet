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
  ll n, k;
  while(cin >> n >> k)
  {
     if (n == k || k == 0)
     {
       cout << "0"<< " ";
     }
     else
     {
       cout << "1 ";
     }
     if (k * 3 <= n)
     {
       cout << k * 2 << endl;
     }
     else
     {
       cout << n - k << endl;
     }
  }
}
