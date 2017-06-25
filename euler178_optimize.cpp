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
//i len, zero occupied, first digit
ll dp[maxn][2][10];
ll up[maxn][2];
int n;
char k[maxn];
int K[maxn];
int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  scanf("%s", k);
  int n = strlen(k);
  for (int i = n - 1; i >= 0; i--)
  {
    if (k[i] != '0')
    {
      k[i]--;
      break;
    }
    else
    {
      k[i] = '9';
    }
  }
  int m = n;
  if (k[0] == '0')
  {
    n--;
  }
  for (int i = 0; i < n; i++)
  {
    K[m - i - 1] = k[i] - '0';
  }
  for (int i = 1; i < n; i++)
  {
    for (int st = 0; st < 2; st++)
    {
      for (int j = 0; j < 10; j++)
      {
        if (j + 1 < 10)
        {
          dp[i + 1][st][j + 1] += dp[i][st][j];
        }
        if (j - 1 >= 0)
        {
          dp[i + 1][(j-1)?st:1][j - 1] += dp[i][st][j];
        }
      }
      if (K[i] >= 1)
      {
        if (K[i] - 1 < K[i - 1])
        {
          up[i + 1][st] += dp[i][st][K[i] - 1];
        }
        else if (K[i] - 1 == K[i - 1])
        {
          up[i + 1][st] += up[i][st];
        }
      }
      if (K[i] + 1 < 10)
      {
        if (K[i] + 1 < K[i - 1])
        {
          up[i + 1][(K[i])?st:1] += dp[i][st][K[i] + 1];
        }
        else if (K[i] + 1 == K[i-1])
        {
          up[i + 1][K[i]?st:1] += up[i][st];
        }
      }
    }
  }
}
