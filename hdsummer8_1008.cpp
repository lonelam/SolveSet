#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int a[maxn];
char b[maxn][10];
int n, k;
int maxsum[maxn];
int minsum[maxn];
bool solve()
{
      minsum[n] = maxsum[n] = 0;
      for (int i = n - 1; i >= 0; i--)
      {
        if (b[i][0] != 'D')
        {
          maxsum[i] = maxsum[i + 1] + a[i];
        }
        else
        {
          maxsum[i] = maxsum[i+1];
        }
        if (b[i][0] != 'L')
        {
          minsum[i] = minsum[i + 1] - a[i];
        }
        else
        {
          minsum[i] = minsum[i+1];
        }
      }
      if (minsum[0] <=k && maxsum[0] >= k)
      {
        return true;
      }
      return false;
}
int main()
{
  int T;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d", &n, &k);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", a + i);
      }
      for (int i = 0; i < n; i++)
      {
        scanf("%s", b[i]);
      }
      if (solve())
      {
        printf("yes\n");

      }
      else
      {
        printf("no\n");
      }
    }
  }
}
