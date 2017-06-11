<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 5;
ll dp[maxn][maxn][maxn][maxn];
const ll moder = 1e9 + 7;
int d[maxn];
int n;
int main()
{
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        memset(dp, 0, sizeof(dp));
        //dp[0][0][0][0] = 1;
        if (d[0] == 2)
        {
            dp[1][0][1][0] = 1;
        }
        else if (d[0] == 3)
        {
            dp[1][0][0][1] = 1;
        }
        for (int i = 2; i <= n; i++)
        {
            if (d[i - 1] == 2)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        for (int s = 0; s < n; s++)
                        {
                            //use 2 degree
                            dp[i][j][k][s] = (dp[i - 1][j][k + 1][s] + dp[i - 1][j + 2][k][s]) % moder;
                            if (j) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k][s + 1]) % moder;
                            if (k) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j + 1][k - 1][s + 1]) % moder;
                            //use 1 degree
                            if (j && k) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k - 1][s + 1]) % moder;
                            dp[i][j][k][s] = (dp[i - 1][j - 1][k][s + 1] + dp[i - 1][j + 1][k - 1][s + 1]) % moder;
                            //if (j && k) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k - 1][s + 1] ) % moder;
                            //if (j) dp[i][j][k][s] = (dp[i][j][k][s] + dp[i - 1][j - 1][k][s + 1]) % moder;
                            if ()
                        }
                    }
                }
            }
            else if (d[i - 1] == 3)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        dp[i][j][k] = (dp[i - 1][j + 3][k] + dp[i - 1][j + 1][k + 1] + dp[i - 1][j - 1][k + 1] + dp[i - 1][j + 1][k - 1] + dp[i - 1][j + 1][k] +) % moder;
                    }
                }
            }
        }
        cout << dp[n][0][0] << endl;
    }
=======
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;
const int moder = 1e9 + 7;
int n, d[maxn];
ll f[2][maxn][maxn][maxn][maxn];
int main()
{
  while(scanf("%d", &n) != EOF)
  {
    for (int i = 0; i < n; i++) scanf("%d", d + i);
    memset(f, 0, sizeof(f));
    int cur = 0, nex = 1;
    f[1][d[0] == 2][d[0] == 3][d[1] == 2][d[1] == 3] = 1;
    for (int i = 2; i < n; i++)
    {
      memset(f[cur], 0, sizeof(f[cur]));
      for (int p1 = 0; p1 <= n; p1++)
      {
        for (int p2 = 0; p2 + p1 <= n; p2++)
        {
          for (int c1 = 0; c1 + p1 + p2 <= n; c1++)
          {
            for (int c2 = 0; c2 + p1 + p2 + c1 <= n; c2++)
            {
              if (d[i] == 2)
              {
                /*//up 2
                f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 + 2][p2][c1][c2] * (p1 + 2) * (p1 + 1) / 2 ) % moder;
                if (p1 >= 2) f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 - 2][p2 + 2][c1][c2] * (p2 + 1) * (p2 + 2) / 2) % moder;
                f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1][p2 + 1][c1][c2] * (p2 + 1) * p1) % moder;
                */
                // up 1 cur 1
                f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1 + 1][c2] * (p1 + 1) * (c1 + 1)) % moder;
                if (c1) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1 - 1][c2 + 1] * (p1 + 1) * (c2 + 1)) % moder;
                if (p1) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1 + 1][c2] * (p2 + 1) * (c1 + 1)) % moder;
                if (p1 && c1) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1 - 1][c2 + 1] * (p2 + 1) * (c2 + 1)) % moder;
                //up 1 left 1
                if (c1) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1 - 1][c2] * (p1 + 1)) % moder;
                if (c1 && p1) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1 - 1][c2] * (p2 + 1)) % moder;
              }
              else if (d[i] == 3)
              {
                /*//up 3
                f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 + 3][p2][c1][c2] * (p1 + 3) * (p1 + 2) * (p1 + 1) / 6) % moder;
                if (p1 >= 3) f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 - 3][p2 + 3][c1][c2] * (p2 + 3) * (p2 + 2) * (p2 + 1) / 6) % moder;
                f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 + 1][p2 + 1][c1][c2] * (p2 + 1) * p2 / 2 * (p1 + 1)) % moder;
                if (p1) f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 - 1][p2 + 2][c1][c2] * (p2 + 2) * (p2 + 1) / 2 * (p1 - 1)) % moder;
                */
                //up 1 cur 2
                f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1 + 2][c2] * (p1 + 1) * (c1 + 2) * (c1 + 1) / 2) % moder;
                if (c1 >= 2) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1 - 2][c2 + 2] * (p1 + 1) * (c2 + 2) * (c2 + 1) / 2) % moder;
                f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1][c2 + 1] * (p1 + 1) * (c2 + 1) * c1) % moder;
                if (p1)
                {
                  f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1 + 2][c2] * (p2 + 1) * (c1 + 2) * (c1 + 1) / 2) % moder;
                  if (c1 >= 2) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1 - 2][c2 + 2] * (p2 + 1) * (c2 + 2) * (c2 + 1) / 2) % moder;
                  f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1][c2 + 1] * (p2 + 1) * (c2 + 1) * c1) % moder;
                }
                /*//up 2 cur 1
                f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 + 2][p2][c1 + 1][c2] * (c1 + 1) * (p1 + 2) * (p1 + 1) / 2) % moder;
                if (p1 >= 2) f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 - 2][p2 + 2][c1 + 1][c2] * (c1 + 1) * (p2 + 2) * (p2 + 1) / 2) % moder;
                f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1][p2 + 1][c1 + 1][c2] * (c1 + 1) * (p2 + 1) * p1) % moder;
                if (c1)
                {
                  f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 + 2][p2][c1 - 1][c2 + 1] * (c2 + 1) * (p1 + 2) * (p1 + 1) / 2) % moder;
                  if (p1 >= 2) f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 - 2][p2 + 2][c1 - 1][c2 + 1] * (c2 + 1) * (p2 + 2) * (p2 + 1) / 2) % moder;
                  f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1][p2 + 1][c1 - 1][c2 + 1] * (c2 + 1) * (p2 + 1) * p1) % moder;
                }
                // up 2 left 1
                if (c1)
                {
                  f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 + 2][p2][c1 - 1][c2] * (p1 + 2) * (p1 + 1) / 2) % moder;
                  if (p1 >= 2) f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1 - 2][p2 + 2][c1 - 1][c2] * (p2 + 1) * (p2 + 2) / 2) % moder;
                  f[i][p1][p2][c1][c2] = (f[i][p1][p2][c1][c2] + f[i - 1][p1][p2 + 1][c1 - 1][c2] * (p2 + 1) * p1) % moder;
                }
                */
                // up 1 cur 1 left 1
                f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1][c2] * (p1 + 1) * (c1)) % moder;
                if (c1 >= 2) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1 - 2][c2 + 1] * (p1 + 1) * (c2 + 1)) % moder;
                if (p1) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1][c2] * (p2 + 1) * (c1)) % moder;
                if (p1 && c1 >= 2) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1 - 2][c2 + 1] * (p2 + 1) * (c2 + 1)) % moder;
                // up1 left 2
                if (c2) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 + 1][p2][c1][c2 - 1] * (p1 + 1)) % moder;
                if (c2 && p1) f[cur][p1][p2][c1][c2] = (f[cur][p1][p2][c1][c2] + f[nex][p1 - 1][p2 + 1][c1][c2 - 1] * (p2 + 1)) % moder;
              }
              if (p1 == 0 && p2 == 0 && (c1 + c2))
              {
                f[cur][c1][c2][0][0] = (f[cur][c1][c2][0][0] + f[cur][0][0][c1][c2]) % moder;
              }
            }
          }
        }
      }
      swap(cur, nex);
    }
    /*
    for (int i = 2; i < n; i++)
    {
      for (int p1 = 0; p1 <= n; p1++)
      {
        for (int p2 = 0; p2 + p1 <= n; p2++)
        {
          for (int c1 = 0; c1 + p1 + p2 <= n; c1++)
          {
            for (int c2 = 0; c2 + p1 + p2 + c1 <= n; c2++)
            {
              if (f[i][p1][p2][c1][c2])
              {
                cout << i <<" "<< p1 <<" "<< p2 <<" "<< c1 <<" "<< c2 << " "<< f[i][p1][p2][c1][c2] << endl;
              }
            }
          }
        }
      }
    }
    */
    printf("%Ld\n", f[nex][0][0][0][0]);
  }
>>>>>>> 7b5ea806e6e229becffc113acdb18e20cea51a2f
}
