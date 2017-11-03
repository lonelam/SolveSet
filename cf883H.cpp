#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 400000 + 5;
int n;
char s[maxn];
string table;
int main()
{
  for (char c = '0'; c <= '9'; c++)
  {
    table.push_back(c);
  }
  for (char c = 'a'; c <= 'z'; c++)
  {
    table.push_back(c);
  }
  for (char c = 'A'; c <= 'Z'; c++)
  {
    table.push_back(c);
  }
  while(~scanf("%d%s", &n, s))
  {
    int ans = 0;
    map<char,int> cnt;
    string odd;
    for (int i = 0; i < n; i++)
    {
      cnt[s[i]]++;
    }
    for (char c: table)
    {
      if (cnt.find(c) != cnt.end() && cnt[c] & 1)
      {
        odd.push_back(c);
        if (--cnt[c] == 0)
        {
          cnt.erase(c);
        }
      }
    }
    if (odd.size() == 0)
    {
      printf("1\n");
      string rev;
      for (char c: table)
      {
        if (cnt.find(c) != cnt.end())
        {
          int up = cnt[c] / 2;
          for (int i = 0; i < up; i++)
          {
            rev.push_back(c);
          }
        }
      }
      printf("%s", rev.c_str());
      reverse(rev.begin(), rev.end());
      printf("%s\n", rev.c_str());
    }
    else
    {
      while((n - odd.size()) % odd.size() != 0 || ((n - odd.size()) / odd.size() % 2 != 0) )
      {
        odd.push_back(cnt.begin()->first);
        odd.push_back(cnt.begin()->first);
        if ((cnt.begin()->second -= 2) == 0)
        {
          cnt.erase(cnt.begin());
        }
      }
      printf("%d\n", odd.size());
      int mm = (n - odd.size()) / odd.size() / 2;
      for (char c: table)
      {
        if (cnt.find(c) != cnt.end())
        {
          cnt[c] /= 2;
        }
      }
      for (int i = 0; i < odd.size(); i++)
      {
        string rev;
        for (int j = 0; j < mm; j++)
        {
          rev.push_back(cnt.begin()->first);
          if (--cnt.begin()->second == 0)
          {
            cnt.erase(cnt.begin());
          }
        }
        printf("%s%c", rev.c_str(), odd[i]);
        reverse(rev.begin(), rev.end());
        printf("%s%c", rev.c_str(), (i==odd.size()-1)?'\n':' ');
      }
    }
  }

}
