#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;

char s[maxn];
int main()
{
  scanf("%s", s);
  int n = strlen(s);
  reverse(s, s + n);
  s[n++] = '0';
  s[n] = '\0';
  int con = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
    {
      con++;
    }
    else if (s[i] == '0')
    {
      if (con > 1)
      {
        ans++;
        for (int j = i - con; j < i; j++)
        {
          s[j] = '0';
        }
        s[i] = '1';
        con = 1;
      }
      else con = 0;
    }
  }
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        ans++;
      }
    }
  printf("%d\n", ans * 2 - 1);
}
