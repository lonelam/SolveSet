#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 50;
char S[maxn];
int m;
int n;
bool check(int len)
{
  for (int i = len; i + len <= n; i++)
  {
    int dis = 0;
    int L = i - len, R = i + len - 1;
    for (int j = 0; j < len; j++)
    {
      dis += abs(S[i - j - 1] - S[i + j]);
    }
    if (dis <= m)
    {
      return true;
    }
    L--;
    R++;
    while(L >= 0 && R < n)
    {
      dis -= abs(S[L + len]-S[R - len]);
      dis += abs(S[L] - S[R]);
      if (dis <= m)
      {
        return true;
      }
      L--;
      R++;
    }
    L = i - len, R = i + len;
    dis = 0;
    for (int j = 0; j < len; j++)
    {
      dis += abs(S[L + j] - S[R - j]);
    }
    if (dis <= m)
    {
      return true;
    }
    L--;
    R++;
    while(L >= 0 && R < n)
    {
      dis -= abs(S[L + len]-S[R - len]);
      dis += abs(S[L] - S[R]);
      if (dis <= m)
      {
        return true;
      }
      L--;
      R++;
    }
  }
  return false;
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &m);
    scanf("%s", S);
    n = strlen(S);
    int L = 0, R = n / 2 + 1;
    while(L + 1 < R)
    {
      const int mid = (L + R) / 2;
      if (check(mid))
      {
        L = mid;
      }
      else
      {
        R = mid;
      }
    }
    printf("%d\n", L);
  }
}
