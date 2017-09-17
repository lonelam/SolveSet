#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
set<int> B;
set<int> A;
int main()
{
  int T;
  int n;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    A.clear();
    B.clear();
    for (int i = 0; i < n; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      A.insert(tmp);
    }
    for (int x: A)
    {
      for (int y: A)
      {
        if (x + y <= 1e6)
        {
          B.insert(x + y);
        }
      }
    }
  }
}
