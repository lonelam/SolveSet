#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
int n;
int main()
{
  int k, x;
  while(cin >> n >> k >> x)
  {
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a, a + n);
    for (int i = n-1, j = 0; i >= 0 && j < k; j++, i--)
    {
      if (a[i] > x)
      {
        a[i] = x;
      }
    }
    cout << accumulate(a, a+ n, 0) << endl;
  }
}
