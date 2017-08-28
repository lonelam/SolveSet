#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string s;
vector<string> v;
int main()
{
  int mx = 0;
  while(getline(cin,s) && s[0] != '!')
  {
    v.push_back(s);
    mx = max(mx, (int)s.size());
  }
  bool a = 0;
  for (int i = 0; i < mx + 2; i++)
  {
    putchar('*');
  }
  putchar('\n');
  for (string x: v)
  {
    putchar('*');
    int len = x.size();
    int lef = mx - len;
    if (lef & 1)
    {
      lef += a;
      a = !a;
    }
    lef /= 2;
    int righ = mx - len - lef;
    for (int j = 0; j < lef; j++)
    {
      putchar(' ');
    }
    printf("%s", x.c_str());
    for (int j = 0; j < righ; j++)
    {
      putchar(' ');
    }
    putchar('*');putchar ('\n');
  }
  for (int i = 0; i < mx + 2; i++)
  {
    putchar('*');
  }
  putchar('\n');

}
