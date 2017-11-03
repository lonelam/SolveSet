#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ld a[maxn], c[maxn];
pair<ld,ld> b[maxn];
int n;
int main()
{
  while(cin >> n)
  {
    cin >> a[0] >> a[n+1];
    b[0] = {a[0], 0};
    b[1] = {0, 1};
    for (int i = 1; i <= n; i++)
    {
      cin >> c[i];
    }
    for (int i = 2; i <= n + 1; i++)
    {
      b[i] = {b[i-1].first * 2 - b[i-2].first + 2 * c[i-1], b[i-1].second * 2 - b[i-2].second};
    }
    a[1] = (a[n+1] - b[n+1].first) / b[n+1].second;
    printf("%.2Lf\n", a[1]);
    // cout << a[1] << endl;
  }
}
