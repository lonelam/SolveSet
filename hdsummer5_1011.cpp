#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int T;
int n, a[maxn];
int main()
{
  scanf("%d", &T);

  while(T--)
  {
    int K;
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    int cnt = 1;
    for (int i = n - 1; i > 0; i--)
    {
      if (a[i] - a[i - 1] > K)
      {
        break;
      }
      cnt++;
    }
    printf("%d\n",cnt);
  }
}
