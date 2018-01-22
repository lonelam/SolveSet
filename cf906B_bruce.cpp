#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
  int p[maxn];
  for (int i = 1; i < 5; i++)
  {
    for (int j = 1; j < 5; j++)
    {
      int up = i * j;
      for (int k = 0; k < up; k++)
      {
        p[k] = k;
      }
      bool yes = false;
      do {
        bool check = true;
        for (int ii = 0; ii < i; ii++)
        {
          for (int jj = 0; jj < j; jj++)
          {
            for (int d = 0; d < 4; d++)
            {
              if (p[])
            }
            ii * j + jj
          }
        }
      } while(next_permutation(p, p + up));
    }
  }
}
