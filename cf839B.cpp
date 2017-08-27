
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int ra[maxn];
int n, k;
int rem[maxn];
int main()
{
  while(cin >> n >> k)
  {
    int a;
    for (int i = 0; i < k; i++)
    {
      cin >> a;
      ra[a]++;
    }
    memset(rem,0,sizeof(rem));
    rem[2] = n * 2;
    rem[4] = n;
    for (int i = maxn - 1; i > 0; i--)
    {
      while(ra[i]--)
      {
        int j, t;
        for (j = 4; j > 0; j--)
        {
          t = min(i, j);
          if (rem[j])
          {
            rem[j]--;
            ra[i - t]++;
            break;
          }
        }
          if (!j)
          {
            printf("NO\n");
            return 0;
          }
        if (j - t > 1)
        {
          rem[j - t - 1]++;
        }
      }
    }
    printf("YES\n");
  }
}
