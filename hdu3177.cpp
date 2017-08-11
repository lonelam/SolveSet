#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int T, V, n, a[maxn], b[maxn];
int rnk[maxn];
bool cmp(int lhs, int rhs)
{
  return b[lhs]-a[lhs] > b[rhs] - a[rhs];
}
bool check()
{
      sort(rnk, rnk + n, cmp);
      for (int i = 0; i < n; i++)
      {
        if (V < b[rnk[i]])
        {
          return false;
        }
        else
        {
          V -= a[rnk[i]];
        }
      }
      return true;

}
int main()
{
  while(cin >> T)
  {
    while(T--)
    {
      cin >>V>> n;
      for (int i = 0; i < n; i++)
      {
        rnk[i] = i;
        cin >> a[i] >> b[i];
      }
      if (check())
      {
        cout << "Yes\n";
      }
      else
      {
        cout << "No\n";
      }
    }
  }
}
