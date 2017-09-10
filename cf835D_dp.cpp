#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 19;
int k[maxn][maxn];
bool palin[maxn][maxn];
char s[maxn];
int cnt[maxn];
int main()
{
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++)
  {
    k[i][i+1] = 1;
    palin[i][i+1] = true;
    palin[i][i] = true;
    cnt[1]++;
  }
  for (int len = 2; len <= n; len++)
  {
    for (int i = 0; i + len <= n; i++)
    {
      if (palin[i + 1][i + len - 1] && s[i] == s[i + len - 1])
      {
        palin[i][i + len] = true;
      }
      else
      {
        palin[i][i + len] = false;
      }
      if (palin[i][i+len] && k[i][i + len / 2] && k[i + (len + 1) / 2][i + len])
      {
        k[i][i + len] = min(k[i][i + len / 2], k[i+(len+1) / 2][i + len]) + 1;
      }
      else
      {
        k[i][i + len] = 0;
      }
      if (palin[i][i+len])
      {
        k[i][i+len] = max(k[i][i + len], 1);
      }
      cnt[k[i][i+len]]++;
    }
  }
  for (int i = n-1; i>=1; i--)
  {
    cnt[i] += cnt[i+1];
  }
  for (int i = 1; i <= n; i++)
  {
    printf("%d ", cnt[i]);
  }
}
