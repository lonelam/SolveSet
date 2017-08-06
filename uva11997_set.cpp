#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int maxk = 800;
int k;
int A[maxk][maxk];
int main()
{
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  while(scanf("%d", &k) != EOF)
  {
    for (int i = 0; i < k; i++)
    {
      for (int j = 0; j < k; j++)
      {
        scanf("%d", A[i] + j);
      }
    }
    multiset<int,greater<int>> cur, nex;
    cur.insert(0);
    for (int i = 0; i < k; i++)
    {
      for (int x: cur)
      {
        nex.insert(x + A[i][0]);
      }
      for (int j = 0; j < k; j++)
      {
        for (int x: cur)
        {
          nex.insert(x + A[i][j]);
          if(nex.size() > k)
          {
            nex.erase(nex.begin());
          }
        }
      }
      cur.clear();
      swap(nex, cur);
    }
    int f = 0;
    for (multiset<int,greater<int> >::reverse_iterator i = cur.rbegin(); i != cur.rend(); i++)
    {
      if (f)
      {
        printf(" ");
      }
      else
      {
        f = 1;
      }
      printf("%d", *i);
    }
    printf("\n");
  }
}
