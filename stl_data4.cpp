
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  for (int i = 1; i <= 9; i++)
  {
    string fext = ".in";
    string fname(1, '0' + i);
    string ffull = fname + fext;
    freopen(ffull.c_str(), "w", stdout);
    random_device rd;
    uniform_int_distribution<int> xrand(1, 100000);
    cout << 100000 << endl;
    for (int i = 0; i < 100000; i++)
    {
      cout << xrand(rd) << (i == 99999 ? "\n" : " ");
    }
  }

}
