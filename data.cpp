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
  cout << 20 << endl;
  srand(time(0));
  for (int i = 0; i < 19; i++)
  {
    cout << rand() % 10 <<" "<< rand() % 10  << " " << rand() % 2<< endl;
  }
  cout << "1 1 0\n";
}
