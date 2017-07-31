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
  while(scanf("%s",s)!=EOF)
  {
    int level = 0;
    int n = strlen(s);
    map<int,int> leftone;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
      {
        if (leftone.find(level) == leftone.end()) leftone[level] = i;
        level++;
      }
      else if (s[i] == ')')
      {
        if (leftone.find(level) != leftone.end())
        {
          //cout << leftone[level] << endl;
          leftone.erase(level);
        }
        level--;
        if (leftone.find(level) != leftone.end())
        {
          int len = i - leftone[level] + 1;
          if (len > a)
          {
            a = len;
            b = 1;
          }
          else if (len == a)
          {
            b++;
          }
        //  leftone.erase(level);
        }
      }
    }
    printf("%d %d\n", a, b);
  }
}
