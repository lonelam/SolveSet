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
//i len, 0=zero not occupied 1=zero occupied 2=fulloccupied, first digit
ll dp[maxn][4][10];
ll up[maxn][4];
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
  ll ans = 0;
  dp[1][1][0] = 1;
  for (int i = 1; i < 9; i++)
  {
    dp[1][0][i] = 1;
  }
  dp[1][2][9] = 1;
  if (K[0] == 0) up[1][1] = 1;
  else if (K[0] == 9) up[1][2] = 1;
  else up[1][0] = 1;
  for (int i = 1; i < n; i++)
  {
    for (int st = 0; st < 4; st++)
    {
      for (int j = 0; j < 10; j++)
      {
        if (j + 1 < 10)
        {
          if (j == 8) dp[i+1][st|2][j+1] += dp[i][st][j];
          else dp[i + 1][st][j + 1] += dp[i][st][j];
        }
        if (j - 1 >= 0)
        {
          dp[i + 1][(j-1)?st:st|1][j - 1] += dp[i][st][j];
        }
      }
      if (K[i] >= 1)
      {
        if (K[i] - 1 < K[i - 1])
        {
          if(K[i]==9) up[i+1][st|2] += dp[i][st][K[i]-1];
          else up[i + 1][st] += dp[i][st][K[i] - 1];
        }
        else if (K[i] - 1 == K[i - 1])
        {
          if (K[i]==9) up[i+1][st|2] += up[i][st];
          else up[i + 1][st] += up[i][st];
        }
      }
      if (K[i] + 1 < 10)
      {
        if (K[i] + 1 < K[i - 1])
        {
          up[i + 1][K[i]?st:st|1] += dp[i][st][K[i] + 1];
        }
        else if (K[i] + 1 == K[i-1])
        {
          up[i + 1][K[i]?st:st|1] += up[i][st];
        }
      }
    }
    for (int j = 1; j < 10; j++)
    {
      ans += dp[i][3][j];
      //cout << j<<"  "<<dp[i][3][j] << endl;
    }
  //  cout << ans << endl;
  }
  ans += up[n][3];
  //cout << up[n][2] << endl;
  for (int i = 1; i < K[n-1]; i++)
  {
    ans += dp[n][3][i];
  }
  cout << ans << endl;
}
/*
1000000000000
*/
