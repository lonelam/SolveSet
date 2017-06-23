#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 100;
struct BigInteger
{
  typedef unsigned long long LL;
  static const int BASE = 100000000;
  static const int WIDTH = 8;
  vector<int> s;
  BigInteger & clean() { while(!s.back() && s.size() > 1) s.pop_back(); return *this;}
  BigInteger(LL num = 0) {*this = num;}
  BigInteger(string s) {*this = s;}
  BigInteger & operator= (long long num)
  {
    s.clear();
    do
    {
      s.push_back(num % BASE);
      num /= BASE;
    } while(num > 0);
    return *this;
  }
  BigInteger operator+(const BigInteger & b) const
  {
    BigInteger c; c.s.clear();
    for (int i = 0, g = 0; ; i++)
    {
      if (g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = g;
      if (i < s.size()) x += s[i];
      if (i < b.s.size()) x += b.s[i];
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c;
  }
  BigInteger & operator += (const BigInteger & b) {*this = *this + b; return *this;}
};
ostream & operator << (ostream & out, const BigInteger & x)
{
  out << x.s.back();
  for (int i = x.s.size() - 2; i >= 0; i--)
  {
    char buf[20];
    sprintf(buf, "%08d", x.s[i]);
    for (int j = 0; j < strlen(buf); j++) cout << buf[j];
  }
  return out;
}
typedef BigInteger ll;
ll dp[maxn][2][10];
ll up[maxn][2];
int n;
char k[maxn];
int K[maxn];
int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
}
