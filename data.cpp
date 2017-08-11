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
  freopen("data.in", "w", stdout);
  cout << 10000 << endl;
  srand(time(0));
  for (int i = 0; i < 10000; i++)
  {
    for (int k = 0; k < 2; k++)
    {
      for (int j = 0; j < 4; j++)
    {
      cout << rand() % 100 << " ";
    }
    cout << endl;
  }
  }
}
