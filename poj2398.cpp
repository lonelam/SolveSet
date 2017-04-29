
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
int n, m, x_1, y_1, x_2, y_2;
const int maxn = 5000 + 100;
struct line
{
  int U, L;
  bool operator<(const line & rhs) const
  {
    return U < rhs.U;
  }
} ls[maxn];
int X[maxn], Y[maxn];

bool check(int point, int l)
{
  int dx0 = ls[l].U - ls[l].L, dy0 = y_1 - y_2;
  int dx1 = X[point] - ls[l].L, dy1 = Y[point] - y_2;
  int product = dx0 * dy1 - dy0 * dx1;
  if (product > 0) return true;
  return false;
}
int cnt[maxn];
int main()
{
  while(scanf("%d%d%d%d%d%d", &n, &m, &x_1, &y_1, &x_2, &y_2) != EOF && n)
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%d%d", &ls[i].U, &ls[i].L);
    }
    ls[0].U = x_1;
    ls[0].L = x_2;
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d", X + i, Y + i);
    }
    memset(cnt, 0, sizeof(cnt));
    sort(ls, ls + n + 1);
    for (int i = 0; i < m; i++)
    {
      int lb = 0, rb = n + 1;
      while(lb + 1 < rb)
      {
        const int mid = lb + (rb - lb)/ 2;
        if (check(i, mid))
        {
          rb = mid;
        }
        else
        {
          lb = mid;
        }
      }
      cnt[lb]++;
    }
    printf("Box\n");
    map<int, int> mp;
    for (int i = 0; i <= n; i++)
    {
      if (cnt[i]) mp[cnt[i]] += 1;
//      printf("%d: %d\n", i, cnt[i]);
    }
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
    {
      printf("%d: %d\n", i->first, i->second);
    }
    
  //  printf("\n");


  }
}
