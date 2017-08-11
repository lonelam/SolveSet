#include <bits/stdc++.h>
using namespace std;
const int maxm = 500 + 5;
const int inf = 0x3f3f3f3f;
struct edge
{
  int from, to, c, f, cost;
}es[maxm];
int tot;
int aabs(int a)
{
  return a >= 0? a : -a;
}
int main()
{
  int n, T, m;
  while(scanf("%d", &T) != EOF)
  {
    while(T--)
    {
      scanf("%d%d", &n, &m);
      int superS = (n + 1) << 1;
      int superT = (n + 1) << 1 | 1;
    }
  }
}
