#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  freopen("shu1790.in", "w", stdout);
  int n = 1000;
  cout << n << endl;
  random_device rd;
  uniform_int_distribution<int> ufw(1, 10001), ufs(1, 1000000001);
  for (int i = 0; i < n; i++)
  {
    cout << ufw(rd) <<" "<< ufs(rd) << endl;
  }
}
