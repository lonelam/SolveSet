#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
int add(int x)
{
  int sum = x;
  while(x)
  {
    sum += x % 10;
    x /= 10;
  }
  return sum + x;
}
int main()
{
  while(cin >> n)
  {
    set<int> s;
    for (int i = 0; i <= 81 && n - i > 0; i++)
    {
      if (add(n - i) == n)
      {
        s.insert(n-i);
      }
    }
    cout << s.size() << endl;
    for (int x: s)
    {
      cout << x << endl;
    }
  }
}
