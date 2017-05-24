#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int r, c;
int grid[maxn][maxn];
int rem[maxn][maxn];
int cpeak[maxn];
int rpeak[maxn];
int g[maxn][maxn];
int clinker[maxn];
bool used[maxn];
bool cused[maxn];
bool rused[maxn];
bool dfs(int u)
{
  for (int v = 0; v < c; v++)
  {
    if (g[u][v] && !used[v])
    {
      used[v] = true;
      if (clinker[v] == -1 || dfs(clinker[v]))
      {
        clinker[v] = u;
        return true;
      }
    }
  }
  return false;
}
int hungary()
{
  int res= 0;
  memset(clinker, -1, sizeof(clinker));
  for (int u = 0; u < r; u++)
  {
    memset(used, 0, sizeof(used));
    if (dfs(u)) res++;
  }
  return res;
}
int main()
{
  while(cin >> r >> c)
  {
    for (int i = 0 ;i  < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        cin >> grid[i][j];
        if (grid[i][j]) rem[i][j] = 1;
        else rem[i][j] = 0;
      }
    }

    for (int i = 0; i < r; i++) rpeak[i] = *max_element(grid[i], grid[i] + c);
    for (int j = 0; j < c; j++)
    {
      cpeak[j] = 0;
      for (int i =0; i < r; i++)
      {
        cpeak[j] = max(cpeak[j], grid[i][j]);
      }
    }
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (cpeak[j] == rpeak[i] && grid[i][j])
        {
          g[i][j] = 1;
        }
        else g[i][j] = 0;
      }
    }
    hungary();
    ll ans = 0;
    memset(cused, 0, sizeof(cused));
    memset(rused, 0, sizeof(rused));
    for (int j = 0; j < c; j++)
    {
      if (clinker[j] != -1)
      {
        rem[clinker[j]][j] = cpeak[j];
        rused[clinker[j]] = true;
        cused[j] = true;
      }
      else
      {
        for (int i = 0; i < r; i++)
        {
          if (rem[i][j] && cpeak[j] <= rpeak[i])
          {
            rem[i][j] = cpeak[j];
            cused[j] = true;
            break;
          }
        }
        if (!cused[j])
        {
          for (int i = 0; i < r; i++)
          {
            if (cpeak[j] <= rpeak[i])
            {
              rem[i][j] = cpeak[j];
              cused[j] = true;
              break;
            }
          }
        }
      }
    }

    for (int i = 0; i < r; i++)
    {
      if (rused[i]) continue;
      for (int j = c - 1; j >= 0; j--)
      {
        if (rem[i][j] && cpeak[j] >= rpeak[i])
        {
          rem[i][j] = rpeak[i];
          rused[i] = true;
          break;
        }
      }
      if (!rused[i])
      {
        for (int j = c - 1; j >= 0; j--)
        {
          if (cpeak[j] >= rpeak[i])
          {
            rem[i][j] = rpeak[i];
            rused[i] = true;
          }
        }
      }
    }

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
  //      cout << rem[i][j] <<" ";
        ans += grid[i][j] - rem[i][j];
      }
//      cout << endl;
    }
    cout << ans << endl;
  }
}
