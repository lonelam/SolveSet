#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n, m, k;
int a[100 + 5][100 + 5];
int main()
{
  while(cin >> n >> m >> k)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> a[i][j];
      }
    }
    int ans = 0, elim = 0;
    for (int j = 0; j < m; j++)
    {
      int tmp = 0, temp = 0;
      int ta = 0, tb = 0;
      for (int i = 0; i < k && i < n; i++)
      {
        tmp += a[i][j];
      }
      ta = tmp;
      tb = temp;
      for (int i = k; i < n; i++)
      {
        temp += a[i-k][j];
        tmp -= a[i-k][j];
        tmp += a[i][j];
        if (tmp > ta)
        {
          ta = tmp;
          tb = temp;
        }
      }
      //cout << ta <<" "<< tb <<endl;
      ans += ta;
      elim += tb;
    }
    cout << ans << " " << elim << endl;
  }
}
