#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 105;
int n;
ll A[maxn][maxn];


int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  A[1][1] = 1;
  for (int i = 2; i <= 100; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      A[i][j] = A[i-1][j-1] + A[i-1][j];
    }
  }
  int kase = 1;
  while(cin >> n)
  {
    cout << "Case " << kase++ << ":\n";
    for (int i = 1; i <= n+1; i++)
    {
      for (int j = 1; j < i; j++)
      {
        cout << A[i][j] << " ";
      }
      cout << A[i][i] << endl;
    }
  }
}
