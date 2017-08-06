#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
ll F[maxn][maxn];
int main()
{
    F[1][1] = F[1][2] = 1;
    int N = 3;
    for (int i = 3; i < 100; i++)
    {
      F[1][i] = F[1][i-1] + 2 * F[1][i-2];
    }
    for (int i = 2; i < 100; i++)
    {
      for (int j = 1; j < 100; j++)
      {
        for (int k = j; k < j + N; k++)
        {
          F[i][j] += F[i-1][k];
        }
      }
    }
    for (int i = 1; i <= 10; i++)
    {
      for (int j = 1; j <= 10; j++)
      {
        cout << F[i][j] << "\t";
      }
      cout  << endl;
    }
}
