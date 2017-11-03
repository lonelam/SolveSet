#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
char t[maxm], s[maxn];
int n, m;
int T;
int nex[maxn];
void get_nex()
{
  int j;
  nex[0] = j = -1;
  for (int i = 1; i < n; i++)
  {
    while(j >= 0 && s[j + 1] != s[i]) j = nex[j];
    if (s[j+1] == s[i]) j++;
    nex[i] = j;
  }
}
int fnd()
{
  int j = -1;
  int cnt = 0;
  for (int i = 0; i < m; i++)
  {
    while(j >= 0 && s[j+1] != t[i]) j = nex[j];
    if (s[j+1] == t[i]) j++;
    if (j == n - 1) cnt++;
  }
  return cnt;
}
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    get_nex();

    printf("%d\n", fnd());
  }
}
