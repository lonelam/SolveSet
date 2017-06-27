#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 20;
int grid[20][20];
int main()
{
  for (int i = 0; i < maxn; i++)
  {
    for (int j = 0; j < maxn; j++)
    {
      scanf("%d", grid[i] + j);
    }

  }
  int ans = 0;
  for (int i = 0; i < maxn; i++)
  {
    int window = 1;
    for (int j = 0; j < 4; j++)
    {
      window *= grid[i][j];
    }
    ans = max(window, ans);
    for (int j = 4; j < maxn; j++)
    {
      if (grid[i][j - 4])window /= grid[i][j - 4];
      else
      {
        window = 1;
        for (int k = 1; k <= 3; k++)
        {
          window *= grid[i][j - k];
        }
      }
      window *= grid[i][j];
      ans = max(window, ans);
    }
  }
  for (int j = 0; j < maxn; j++)
  {
    int window = 1;
    for (int i = 0; i < 4; i++)
    {
      window *= grid[i][j];
    }
    ans = max(window, ans);
    for (int i = 4; i < maxn; i++)
    {
      if (grid[i-4][j])window /= grid[i - 4][j];
      else
      {
        window = 1;
        for (int k = 1; k <= 3; k++)
        {
          window *= grid[i - k][j];
        }
      }
      window *= grid[i][j];
      ans = max(window, ans);
    }
  }
  for (int i = 0; i < maxn; i++)
  {
    int window = 1;
    for (int j = 0; j < 4 && i + j < maxn; j++)
    {
      window *= grid[i + j][j];
    }
    ans = max(window, ans);
    for (int j = 4; j + i < maxn; j++)
    {
      if (grid[i + j-4][j-4])window /= grid[i + j - 4][j-4];
      else
      {
        window = 1;
        for (int k = 1; k <= 3; k++)
        {
          window *= grid[i + j - k][j-k];
        }
      }

      window *= grid[i + j][j];
      //cout << window << endl;
      ans = max(window, ans);
    }
  }
  for (int i = 0; i < maxn; i++)
  {
    int window = 1;
    for (int j = 0; j < 4 && i + j < maxn; j++)
    {
      window *= grid[j][i + j];
    }
    ans = max(window, ans);
    for (int j = 4; j + i < maxn; j++)
    {
      if (grid[j-4][i + j - 4])window /= grid[j-4][i + j - 4];
      else
      {
        window = 1;
        for (int k = 1; k <4; k++)
        {
          window *= grid[j - k][j + i - k];
        }
      }
      window *= grid[j][i + j];
      ans = max(window, ans);
    }
  }
  for (int i = 0; i < maxn; i++)
  {
    int window = 1;
    for (int j = 0; j < 4 && i - j >= 0; j++)
    {
      window *= grid[i - j][j];
    }
    ans = max(window, ans);
    for (int j = 4; i - j >= 0; j++)
    {
      if (grid[i - j + 4][j - 4]) window /= grid[i - j + 4][j - 4];
      else
      {
        window =1;
        for (int k = 1; k <= 3; k++)
        {
          window *= grid[i - j + k][j - k];
        }
      }
      window *= grid[i - j][j];
      ans = max(window, ans);
    }
  }
  for (int i = 0; i < maxn; i++)
  {
    int window = 1;
    for (int j = 0; j < 4 && i - j >= 0; j++)
    {
      window *= grid[j][i - j];
    }
    ans = max(window, ans);
    for (int j = 4; i - j >= 0; j++)
    {
      if (grid[j-4][i - j + 4]) window /= grid[j - 4][i - j + 4];
      else{
        window = 1;
        for (int k = 1; k <= 3; k++) window *= grid[j - k][i-j+k];
      }
      window *= grid[j][i - j];
      ans = max(window, ans);
    }
  }
  printf("%d\n", ans);
}
