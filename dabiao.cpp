#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
set<ll> ans[maxn];
ll F[maxn];
int main()
{
  F[0] = 0;
  F[1] = 1;
  ans[0].insert(0);
  for (int i = 1; i < 10; i++)
  {
    ans[i].insert(0);
    ans[i].insert(1);
  }
  for (int i = 2; i < 20; i++)
  {
    F[i] = F[i-1] + F[i-2];
    for (int j = 1; j < 10; j++)
    {
      for (int k = 1; k <= j; k++)
      {
        for (ll s : ans[j - k])
        {
          ans[j].insert(s + k * F[i]);
        }
      }
    }
  }
  for (int i = 1; i < 10; i++)
  {
    ll p = 1;
    while(ans[i].find(p) != ans[i].end()) p++;
    cout << p << endl;
  }
}
