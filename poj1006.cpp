#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 10;
int a[maxn], m[maxn];
void ex_gcd(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return;
  }
  ex_gcd(b, a % b, y, x);
  y -= (a / b) * x;
}
int CRT(int a[], int m[], int n)
{
  int M = 1;
  int ans = 0;
  for(int i=1; i<=n; i++)
    M *= m[i];
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    int Mi = M / m[i];
    ex_gcd(Mi, m[i], x, y);
    ans = (ans + Mi * x * a[i]) % M;
  }
  if (ans < 0) ans += M;
  return ans;
}
int main()
{
  int T;
  int p, i, e, d, kase = 1;
  m[1] = 23;
  m[2] = 28;
  m[3] = 33;
  const int lcm = 23 * 33 * 28;
  scanf("%d", &T);
  while(T--)
  {
kase = 1;
    while(scanf("%d%d%d%d", a+1, a+2, a+3, &d) != EOF && a[1] != -1)
    {
    m[1] = 23;
    m[2] = 28;
    m[3] = 33;
      int ans = CRT(a,m,3);
      if (ans <= d) ans += lcm;
  		printf("Case %d: the next triple peak occurs in %d days.\n", kase++, ans-d);

    }
    if (T) printf("\n");
  }
}
