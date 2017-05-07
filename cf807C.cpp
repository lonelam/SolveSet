
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

void exgcd(ll a, ll b, ll & d, ll & x, ll & y)
{
  if (!b)
  {
    d = a;
    x = 1;
    y = 0;
  }
  else
  {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

ll gcd(ll a, ll b)
{
  return b == 0LL ? a : gcd(b, a % b);
}
ll x, y, p, q;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    cin >> x >>y >> p >> q;
    if (p == 0 && x != 0)
    {
      cout << -1 << endl;
      continue;
    }
    if (p == 1 && q == 1 && x != y)
    {
      cout << -1 << endl;
      continue;
    }
    ll py = p * y, xq = x * q;
    ll gg = py - xq;
    if (gg == 0)
    {
      cout << 0 << endl;
    }
    else if (gg > 0)
    {
      ll c = gcd(q, p);
      if (gg % c)
      {
        cout << -1 << endl;
      }
      else
      {
        ll a, negb;
        ll d;
        exgcd(q, p, d, a, negb);
        ll b = -negb;
        a *= (gg / c);
        b *= (gg / c);
        ll qs = q / c, ps = p / c;
        if (b < 0)
        {
          int k = (-b + qs) / qs;
          b += k * qs;
          a += k * ps;
        }
      //  cout << ps <<" "<< qs << endl;
        if (a < 0)
        {
          ll k = (-a + ps) / ps;
          b += k * qs;
          a += k * ps;
        }
        //cout << a <<"  "<< b << endl;
        ll k = min(b / qs, a / ps);
        a -= k * ps;
        b -= k * qs;
        if (ps < qs && a > b)
        {
          k = (a - b + qs - ps - 1) / (qs - ps);
          a += k * ps;
          b += k * qs;
        }
        else if (ps > qs && a > b)
        {
          k = (a - b + ps - qs - 1) / (ps - qs);
          a -= k * ps;
          b -= k * qs;
        }
        //cout << a <<"  "<< b << endl;
        if (a > b || a < 0 || b < 0)
        {
          cout << -1 << endl;
        //  cout <<"debug" <<endl;
        }
        else
        {
          cout << b << endl;
        }
      }
    }
    else
    {
      ll c = gcd(p, q);
      if ((-gg) % c)
      {
        cout << -1 << endl;
      }
      else
      {
        ll nega, b, d;
        exgcd(q, p, d, nega, b);
        ll a = -nega, qs = q / c, ps = p / c;
        a *= (-gg) / c;
        b *= (-gg) / c;
        if (b < 0)
        {
          ll k = (-b + qs ) / qs;
          b += k * qs;
          a += k * ps;
        }
        if (a < 0)
        {
          ll k = (-a + ps ) / ps;
          b += k * qs;
          a += k * ps;
        }
        ll k = min(b / qs, a / ps);
        a -= k * ps;
        b -= k * qs;
        if (ps < qs && a > b)
        {
          k = (a - b + qs - ps - 1) / (qs - ps);
          a += k * ps;
          b += k * qs;
        }
        else if (ps > qs && a > b)
        {
          k = (a - b + ps - qs - 1) / (ps - qs);
          a -= k * ps;
          b -= k * qs;
        }
        if (a > b || a < 0 || b < 0)
        {
          //cout <<"debug"<< endl;
          cout << -1 << endl;
        }
        else
        {
          cout << b << endl;
        }
      }
    }
  }
}
/*



1
5 14 7 9

*/
