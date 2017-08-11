#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int n;
struct dnum
{
  int ds[5];
  int val()
  {
    int base = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += base * ds[i];
      base *= 10;
    }
    return ans;
  }
  void get(int x)
  {
    for (int i = 0; i < n; i++)
    {
      ds[i] = x % 10;
      x /= 10;
    }
  }
  void cancel(int i)
  {
    for (int j = i; j + 1< n; j++)
    {
      ds[j] = ds[j+1];
    }
    ds[n-1] = 0;
  }
};
dnum down, up;
bool is_valid(int a, int b)
{

}
int main()
{
  while(cin >> n)
  {
    ll sumup = 0, sumdown = 0;
    ll lb = 1, ub = 1;
    for (int i = 1; i < n; i++) lb *= 10;
    for (int i = 0; i < n; i++) ub *= 10;
    for (int b = lb; b < ub; b++)
    {
      for (int a = lb; a < b; a++)
      {
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < n; j++)
          {

          }
        }
      }
    }
  }
}
