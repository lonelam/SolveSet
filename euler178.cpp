#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
struct BigInteger {
    typedef unsigned long long LL;

    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger& clean(){while(!s.back()&&s.size()>1)s.pop_back(); return *this;}
    BigInteger(LL num = 0) {*this = num;}
    BigInteger(string s) {*this = s;}
    BigInteger& operator = (long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger& operator = (const string& str) {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return (*this).clean();
    }

    BigInteger operator + (const BigInteger& b) const {
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if (i < s.size()) x += s[i];
            if (i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator - (const BigInteger& b) const {
        assert(b <= *this); // 减数不能大于被减数
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = s[i] + g;
            if (i < b.s.size()) x -= b.s[i];
            if (x < 0) {g = -1; x += BASE;} else g = 0;
            c.s.push_back(x);
        }
        return c.clean();
    }
    BigInteger operator * (const BigInteger& b) const {
        int i, j; LL g;
        vector<LL> v(s.size()+b.s.size(), 0);
        BigInteger c; c.s.clear();
        for(i=0;i<s.size();i++) for(j=0;j<b.s.size();j++) v[i+j]+=LL(s[i])*b.s[j];
        for (i = 0, g = 0; ; i++) {
            if (g ==0 && i >= v.size()) break;
            LL x = v[i] + g;
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c.clean();
    }
    BigInteger operator / (const BigInteger& b) const {
        assert(b > 0);  // 除数必须大于0
        BigInteger c = *this;       // 商:主要是让c.s和(*this).s的vector一样大
        BigInteger m;               // 余数:初始化为0
        for (int i = s.size()-1; i >= 0; i--) {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return c.clean();
    }
    BigInteger operator % (const BigInteger& b) const { //方法与除法相同
        BigInteger c = *this;
        BigInteger m;
        for (int i = s.size()-1; i >= 0; i--) {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return m;
    }
    // 二分法找出满足bx<=m的最大的x
    int bsearch(const BigInteger& b, const BigInteger& m) const{
        int L = 0, R = BASE-1, x;
        while (1) {
            x = (L+R)>>1;
            if (b*x<=m) {if (b*(x+1)>m) return x; else L = x;}
            else R = x;
        }
    }
    BigInteger& operator += (const BigInteger& b) {*this = *this + b; return *this;}
    BigInteger& operator -= (const BigInteger& b) {*this = *this - b; return *this;}
    BigInteger& operator *= (const BigInteger& b) {*this = *this * b; return *this;}
    BigInteger& operator /= (const BigInteger& b) {*this = *this / b; return *this;}
    BigInteger& operator %= (const BigInteger& b) {*this = *this % b; return *this;}

    bool operator < (const BigInteger& b) const {
        if (s.size() != b.s.size()) return s.size() < b.s.size();
        for (int i = s.size()-1; i >= 0; i--)
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }
    bool operator >(const BigInteger& b) const{return b < *this;}
    bool operator<=(const BigInteger& b) const{return !(b < *this);}
    bool operator>=(const BigInteger& b) const{return !(*this < b);}
    bool operator!=(const BigInteger& b) const{return b < *this || *this < b;}
    bool operator==(const BigInteger& b) const{return !(b < *this) && !(b > *this);}
};
typedef BigInteger ll;
ostream& operator << (ostream& out, const BigInteger& x) {
    out << x.s.back();
    for (int i = x.s.size()-2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}

istream& operator >> (istream& in, BigInteger& x) {
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 100;
ll dp[2][1 << 10][10];
char k[maxn];
int K[maxn];
int n;
ll up[2][1 << 10];
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

  for (int i = 0; i < 10; i++)
  {
    dp[1][1 << i][i] = 1;
  }
  up[1][1 << K[0]] = 1;
  ll ans = 0;
  for (int i = 1; i < n; i++)
  {
//    memset(dp[i & 1 ^ 1], 0, sizeof(dp[i & 1]));
    for (int st = 0; st < (1 << 10); st++)
    {
      for (int j = 0; j < 10; j++)
      {
        dp[i & 1 ^ 1][st][j] = 0;
      }
      up[i & 1 ^ 1][st] = 0;
    }
    //memset(up[i & 1 ^ 1], 0, sizeof(up[i & 1]));
    for (int st = 0; st < (1 << 10) ; st++)
    {
      for (int j = 0; j < 10; j++)
      {
        if (j + 1 < 10) dp[i & 1 ^ 1][st | (1 << (j + 1))][j + 1] += dp[i & 1][st][j];
        if (j - 1 >= 0) dp[i & 1 ^ 1][st | (1 << (j - 1))][j - 1] += dp[i & 1][st][j];
      }
      if (K[i] >= 1)
      {
        if (K[i] - 1 < K[i - 1])
        {
          up[i & 1 ^ 1][st | (1 << K[i])] += dp[i & 1][st][K[i] - 1];
        }
        else if (K[i] - 1 == K[i - 1])
        {
          up[i & 1 ^ 1][st | (1 << K[i])] += up[i & 1][st];
        }
      }
      if (K[i] < 9)
      {
        if (K[i] + 1 < K[i - 1])
          up[i & 1 ^ 1][st | (1 << K[i])] += dp[i & 1][st][K[i] + 1];
        else if (K[i] + 1 == K[i - 1])
          up[i & 1 ^ 1][st | (1 << K[i])] += up[i & 1][st];
      }
    }
    for (int j = 1; j < 10; j++)
    {
      ans += dp[i & 1][(1 << 10) - 1][j];
//      cout <<j<<"  "<< dp[i&1][(1<<10)-1][j]<<endl;
    }

//    cout << ans << endl;
  }
  ans += up[n & 1][(1 << 10) - 1];
//  cout << up[n&1][(1<<10)-1]<<endl;
  for (int i = 1; i < K[n - 1]; i++)
  {
    ans += dp[n & 1][(1 << 10) - 1][i];
  }
  cout << ans << endl;
}
/*
*/
