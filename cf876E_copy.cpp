#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 +10;
vector<int> a[maxn], x[maxn];
int n, m, f[maxn], p;
inline void dfs(int i)
{
  int j;
  for (j = 0; j < a[i].size(); j++)
  {
    if (f[a[i][j]] == 2)
    {
      p = 1;
    }
    else if (!f[a[i][j]])
    {
      f[a[i][j]] = 1;
      dfs(a[i][j]);
    }
  }
}
int main()
{
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &k);
    while(k--)
    {
      scanf("%d", &j);
      x[i].push_back(j);
    }
  }
  for (i = 1; i < n; i++)
  {
    for (j = 0; j < x[i].size() && j < x[i+1].size(); j++)
    {
      if (x[i][j] != x[i+1][j]) break;
    }
    // cout << i << endl;
    // cout << x[i][j]  << " "<< x[i+1][j] << endl;
    if (j == x[i].size() || j == x[i+1].size())
    {
      if (x[i].size() > x[i+1].size())
      {
        p = 1;
      }
    }
    else if (x[i][j] < x[i+1][j])
    {
      a[x[i+1][j]].push_back(x[i][j]);
    }
    else if (f[x[i][j]] == 2 || f[x[i+1][j]] == 1)
    {
      p = 1;
    }
    else
    {
      f[x[i][j]] = 1;
      f[x[i+1][j]] = 2;
    }

  }

    for (i = 1; i <= m; i++)
    {
      if (f[i] == 1)
      {
        dfs(i);
      }
    }
    if (p)
    {
      printf("No\n");
    }
    else{
      printf("Yes\n");
      for (i = 1, k = 0; i <= m; i++)
      {
        if (f[i]== 1)k++;
      }
      printf("%d\n", k);
      for (i = 1; i <= m; i++)
      {
        if (f[i] == 1)
        {
          printf("%d ", i);
        }
      }
    }
}
