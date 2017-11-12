#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int a[maxn];
int vis[maxn];
int main()
{
  while(~scanf("%d", &n))
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
    }
    int ans = -1;
    for (int i = n-1; i >= 0; i--)
    {
      if(!vis[a[i]])
      {
        ans = a[i];
        vis[a[i]] = 1;
      }
    }
    printf("%d\n",ans);

  }
}
