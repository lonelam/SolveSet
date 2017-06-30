#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  int n,a;
  while(cin >> n >> a)
  {
    double ang = (180.0/n);
    int b = round((double)a / ang);
    if (!b) b=1;
    cout << 1 << " "<< 2 <<" "<< max(n-b+1, 3) << endl;
  }
}
