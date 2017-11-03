#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int A[maxn];
int n;
int main()
{
  cin >> n;
  ll ans1 = 1;
  ll ans2 = 1;
  for (int i = 0; i < n; i++)
  {
    ans1 *= 3;
    cin >> A[i];
    if (A[i] & 1)
    {
      ans2 *= 1LL;
    }
    else
    {
      ans2 *=  2LL;
    }
  }
  cout << (ans1 - ans2) << endl;
}
