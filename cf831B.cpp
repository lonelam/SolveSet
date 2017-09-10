#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
char a[maxn], b[maxn], c[maxn];
int main()
{
  scanf("%s%s%s", a,b,c);
  map<char, char> t;
  for (int i = 0; i < 26; i++)
  {
    t[a[i]] = b[i];
    t[toupper(a[i])] = toupper(b[i]);
  }
  int n = strlen(c);
  for (int i = 0; i < n; i++)
  {
    if (isalpha(c[i]))
    {
      c[i] = t[c[i]];
    }
  }
  printf("%s\n", c);
}
