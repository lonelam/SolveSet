#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
typedef string Int;
Int operator+(Int & lhs, Int & rhs)
{
  Int res(max(lhs.size(), rhs.size()) + 1, '0');
  auto it = res.rbegin(), lt = lhs.rbegin(), rt = rhs.rbegin();
  int rem = 0;
  for (;it != res.rend(); it++)
  {
    int tmp = rem;
    if (lt != lhs.rend() && rt != rhs.rend())
        tmp = ((*lt - '0') + (*rt - '0') + rem);
    else if (lt != lhs.rend())
        tmp = ((*lt - '0') + rem);
    else if (rt != rhs.rend())
        tmp = ((*rt - '0') + rem);
    *it = tmp % 10 + '0';
    rem = tmp / 10
  }
  int stop = 0;
  for (int i = 0; i < res.size(); i++)
  {
    if (res[i] != '0')
    {
      stop = i;
      break;
    }
  }
  res.erase(0, stop);
  return res;
}
Int operator*(Int & lhs, Int & rhs)
{
  Int res(lhs.size() + rhs.size(), '0');
  for (int i = 0)
}
int main()
{
  int n;
  while(cin >> a >> n)
  {
    ld ans = 1;
    for (int i = 0; i < n; i++)
    {
      ans *= a;
    }
    cout << ans << endl;
  }
}
