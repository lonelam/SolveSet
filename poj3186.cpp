#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 10;
int dp[maxn][maxn];

int a[maxn];
int n;
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a + i);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
      dp[i][i] = a[i] * n;
    }
    for (int len = 1; len < n; len++)
    {
      for (int i = 0; i + len < n; i++)
      {
        dp[i][i + len] = max(dp[i][i + len - 1] + a[i + len] * (n - len), dp[i + 1][i + len] + a[i] * (n - len));
      }
    }
    printf("%d\n", dp[0][n - 1]);
  }
}
/*

5
1
3
1
5
2

*/
