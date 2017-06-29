#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
  ll n,k;
  cin >> n >> k;
  ll x = n / (2 * (k+1));
  cout << x << " "<< k * x << " " << n - (k+1) * x << endl;
}
