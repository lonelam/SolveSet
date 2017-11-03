#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
ld x[maxn], y[maxn], r[maxn];
bool in[maxn][maxn];
int n;
int deg[maxn];
int fa[maxn];
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%Lf%Lf%Lf", x + i, y + i, r + i);
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = i+1; j <= n; j++)
    {
      ld dis = sqrtl((x[i]-x[j])*(x[i]-x[j]) + (y[i]- y[j])*(y[i]-y[j]));
      if (dis <= abs(r[i]- r[j]))
      {
        if (r[i] < r[j])
        {
          // cout << i << " " << j << endl;
          in[i][j] = 1;
          deg[i]++;
        }
        else
        {
          // cout <<j << " " << i << endl;
          in[j][i] = 1;
          deg[j]++;
        }
      }
    }
  }
  queue<int> Q;
  for (int i = 1; i <= n; i++)
  {
    if (!deg[i]) Q.push(i), fa[i] = 0;
  }
  // while(!Q.empty())
  {
    while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      for (int i = 1; i <= n; i++)
      {
        if (in[i][u])
        {
          if (--deg[i] == 0)
          {
            // cout << i << endl;
            Q.push(i);
            fa[i] = u;
          }
        }
      }
    }
  }
  // cout << endl;
  for (int i = 1; i <= n; i++)
  {
    printf("%d\n", fa[i]);
  }
}
