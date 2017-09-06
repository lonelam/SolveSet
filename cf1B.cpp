#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int base[maxn];
string s;
string trans(int x)
{
  string ret;
  int bs;
  for (int i = 1; i < 10; i++)
  {
    if (base[i] > x)
    {
      bs = i-1;
      x -= base[i - 1];
      break;
    }
  }
  while(x)
  {
    ret.push_back(x % 26 + 'A');
    x /= 26;
  }
  while(ret.size() < bs)
  {
    ret.push_back('A');
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
int trans(string x)
{
  int ret = 0;
  // reverse(x.begin(), x.end());
  for (char c: x)
  {
    ret *= 26;
    ret += c - 'A';
  }
  return ret + base[x.size()];
}
int main()
{
  int n;
  ios::sync_with_stdio(0);
  cin.tie(0);
  base[1] = 1;
  for (int i = 2; i < 10; i++)
  {
    base[i] = base[i - 1] + pow(26, i-1);
  }
  while(cin >> n)
  {
    while(n--)
    {
      cin >> s;
      vector<string> nums;
      for (int i = 0; i < s.size(); i++)
      {
        if (isdigit(s[i]))
        {
          string tmp;
          for (int j = i; j < s.size() && isdigit(s[j]); j++)
          {
            tmp.push_back(s[j]);
          }
          nums.push_back(tmp);
          // cout << tmp << endl;
          i += tmp.size() ;
        }
      }
      if (nums.size() == 2)
      {
        int R = stoi(nums[0]);
        int C = stoi(nums[1]);
        cout << trans(C) << R << endl;
      }
      else if (nums.size() == 1)
      {
        int R = stoi(nums[0]);
        string C;
        for (int i = 0; i < s.size(); i++)
        {
          if (isalpha(s[i]))
          {
            C.push_back(s[i]);
          }
          else
          {
            break;
          }
        }
        cout << "R" << R << "C" << trans(C) << endl;
      }
    }
  }
}
