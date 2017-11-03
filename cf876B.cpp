#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int n, m, k;
int a[maxn];
int b[maxn];
vector<int> G[maxn];
int main()
{
  while(~scanf("%d%d%d", &n, &k, &m))
  {
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
      b[i] = a[i] % m;
      G[b[i]].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
      if (G[i].size() >= k)
      {
        ans = i;
        break;
      }
    }
    if (ans == -1)
    {
      printf("No\n");
    }
    else
    {
      printf("Yes\n");
      for (int i = 0; i < k; i++)
      {
        printf("%d%c", a[G[ans][i]], (i==k-1)?'\n':' ');
      }
    }
  }
}
