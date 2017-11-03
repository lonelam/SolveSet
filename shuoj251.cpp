#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
double a[maxn];
double b[maxn];
int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  string s;
  int kase = 1;
  while(getline(cin, s))
  {
    stringstream ss(s);
    int n = 0;
    while(ss >> a[n])
    {
      b[n] = a[n];
      ++n;
    }
    sort(b, b + n, greater<double>());
    cout << "Case " << kase++ << ":\n";
    for (int i = 0; i < n; i++)
    {
      cout << (lower_bound(b, b + n, a[i], greater<double>()) - b + 1);
      if (i == n-1) cout << endl;
      else cout << ", ";
    }
  }
}
