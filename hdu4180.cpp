#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll exgcd(ll a, ll b, ll & x, ll & y)
{
  if (b == 0)
  {
    x = 1; y = 0;
    return a;
  }
  ll g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;

}
char buffer[maxn];
int main()
{
  int k;
  ll a, b;
  while(scanf("%d", &k) != EOF)
  {
    while(k--)
    {
      scanf("%s", buffer);
      int m = strlen(buffer);
      int t = find(buffer, buffer + m, '/') - buffer;
      buffer[t] = '\0';
      a = atoll(buffer);
      b = atoll(buffer + t + 1);
      ll d, neg_c;
      ll g = exgcd(a, b, d, neg_c);
      ll u = (b-d) / (b / g);
      d += u * (b / g);
      neg_c -= u * (a / g);
      if (d >= b)
      {
        d -= (b/g);
        neg_c += a/g;
      }
      // cout << d << " "<< neg_c << endl;
      ll c, neg_d;
      g = exgcd(b,a,c,neg_d);
      ll v = (-b - neg_d) / (b/g);
      neg_d += v * (b / g);
      c -= v * (a / g);
      if (neg_d <= -b)
      {
        neg_d += b/g;
        c -= a/g;
      }
      // cout << neg_d << " "<< c << endl;
      if (g != 1)
      {
        printf("%lld/%lld\n", a/g, b/g);
      }
      else if (-neg_d >= d && c != 0 && c < -neg_d)
      {
        printf("%lld/%lld\n", c, -neg_d);
      }
      else
      {
        printf("%lld/%lld\n", -neg_c, d);
      }
    }
  }
}
