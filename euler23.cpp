#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int d[maxn];
bool is_ab[maxn];
int ab[maxn];
int abtot = 0;
void init()
{
  for (int i = 1; i < maxn; i++)
  {
    for (int j = 2; i * j < maxn; j++)
    {
      d[i * j] += i;
    }
  }
  for (int i = 1; i < maxn; i++)
  {
    if (d[i] > i)
    {
      ab[abtot++] = i;
    }
  }
  sort(ab, ab + abtot);
}
bool solve(int n)
{
    for (int i = 0; ab[i] < n && i < abtot; i++)
    {
      if (binary_search(ab, ab + abtot, n - ab[i]))
      {
        return true;
      }
    }
    return false;
}
int main()
{
  int T,n;
  init();
  cin >> T;
  while(T--)
  {
    cin >> n;
    if (solve(n))
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}
