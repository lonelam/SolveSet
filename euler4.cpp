#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;
int table[maxn];
int tot = 0;
int digit[60];
bool ispalindrome(int x)
{
  int d = 0;
  while(x)
  {
    digit[d++] = x % 10;
    x /= 10;
  }
  for (int i = 0, j = d - 1; i < j; i++, j--)
  {
    if (digit[i] != digit[j])
    {
      return false;
    }
  }
  return true;
}
int main()
{
  for (int i = 100; i <= 999; i++)
  {
    for (int j = 100; j <= 999; j++)
    {
      if (i * j > 100000 && i * j <= 999999 && ispalindrome(i * j))
      {
      //  cout << i * j << endl;
        table[tot++] = i * j;
      }
    }
  }
  sort(table, table + tot);
  int n;
  int T;
  cin >> T;
  while(T--)
  {
    cin >> n;
    cout << table[lower_bound(table, table + tot, n) - table - 1] << endl;
  }
}
