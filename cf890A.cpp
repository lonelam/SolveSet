#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
bool check()
{
  do {
    int cnta = 0, cntb = 0;
    for (int i = 0; i < 3; i++)
    {
      cnta+=a[i];
      cntb += a[i+3];
    }
    if (cnta == cntb) return true;
    /* code */
  } while(next_permutation(a, a + 6));
  return false;
}
int main()
{
  for (int i = 0; i < 6; i++)
  {
    cin >> a[i];
  }
  sort(a, a + 6);
  if (check())
  {
    cout << "YES\n";
  }
  else
  {
    cout << "NO\n";
  }
}
