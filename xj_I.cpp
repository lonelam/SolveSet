#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 5;
int n;
int a[maxn][maxn];
int get(int n)
{
    if (n % 4 == 0)
    {
      int u = n / 4 - 1;
      return 4 * u * (u + 1) * (2 * u + 1) / 3;
    }
    else if (n % 4 == 1)
    {
      int u = n / 4 - 1;
      return  2 * u * (u + 1) * (4 * u + 5) / 3;
    }
    else if (n % 4 == 3)
    {
      int u = n / 4;
      return 2 * u * (u + 1) * (4 * u - 1) / 3;
    }
    else if (n % 4 == 2)
    {
      int u = n / 4;
      return 2 * u * (2 * u - 1) * (2 * u + 1) / 3;
    }
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    printf("%d\n", get(n));
    int m = n / 2;
    if (n % 2 == 0)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (i== j) a[i][j] = 0;
          else if (2 * i < n &&  2 * j < n || 2 * i >= n && 2 * j >= n)
          {
            a[i][j] = 2;
          }
          else
          {
            a[i][j] = 1;
          }
        }
      }
    }
    else if (m % 2 == 0)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (i == j) a[i][j] = 0;
          else if (i / m == 0 && j / m == 0)
          {
            a[i][j] = 1;
          }
          else if (i / m == 0 && j / m == 1 || i / m == 1 && j / m == 0)
          {
            a[i][j] = (i % m == j % m) ? 1: 2;
          }
          else if (i / m == 1 && j / m == 1)
          {
            a[i][j] = ((i % m / 2) == (j % m / 2) && ((i % m % 2)^(j % m % 2))) ? 2: 1;
          }
        }
      }
    }
    else if (m % 2)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (i == j) a[i][j] = 0;
          else if (i / m == 0 && j / m == 0 )
          {
            a[i][j] = 1;
          }
          else if (i / m == 0 && j / m || i / m && j / m == 0)
          {
            if (i % m == j % m)
            {
              if (i % m == m - 1 || j % m == m - 1)
              {
                a[i][j] = 2;
              }
              else
              {
                a[i][j] = ((i % m) == (j % m))?1: 2;
              }
            }
          }
          else if (i / m && j / m)
          {
            a[i][j] = ((i % m / 2) == (j % m / 2) && ((i % m % 2)^(j % m % 2))) ? 2: 1;
            if (i / m == 2 || j / m == 2) a[i][j] = 1;
          }
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i>=j) continue;
        for (int k = j + 1; k < n; k++)
        {
          if (i < j  && j < k)
          if (a[i][k] == a[i][j]  && a[k][j] == a[i][j])
          {
            cnt++;
            // cout << i <<" "<< j << " "<<k<< endl;
          }
        }
      }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0;  j < n; j++)
      {
        printf("%d%c", a[i][j], j==(n-1)?'\n':' ');
      }
    }
  }
}
