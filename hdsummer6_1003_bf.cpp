#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int A[maxn];
int tmp[maxn];
int B[maxn];
bool cmp(int i, int j)
{
  return A[i] > A[j];
}
int main()
{
  int T;
  int n;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", A + i);
      tmp[i] = A[i];
    }
    sort(tmp + 1, tmp + n + 1);
    reverse(tmp + 1, tmp + n + 1);
    for (int i = 2; i <= n; i++)
    {
      int k = 1;
      int up = tmp[k];
      int tot = 0;
      for (int j = i; j <= n; j+=i)
      {
        B[tot++] = j;
      }
      sort(B, B + tot, cmp);
      for (int j = 0; j < tot; j++)
      {
        if (A[B[j]] >= tmp[k])
        {
          k++;
        }
      }
      printf("%d%c", tmp[k], i==n?'\n':' ');
    }
  }
}
