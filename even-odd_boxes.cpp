#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int q;
int n;
int x[maxn];
int main()
{
  while(scanf("%d", &q) != EOF)
  {
    while(q--)
    {
      scanf("%d", &n);
      int ans = 0;
      set<int> oddone_to_add;
      set<int> to_remove;
      for (int i = 0; i < n; i++)
      {
        scanf("%d", x + i);
        if (x[i] == 1 && !(i & 1))
        {
          oddone_to_add.insert(i);
        }
        else if (!(x[i] & 1) && (i & 1) || !(i & 1) && (x[i] & 1))
        {
          to_remove.insert(i);
        }
      }
      while(oddone_to_add.size() && to_remove.size())
      {
        x[*oddone_to_add.begin()]++;
        x[*to_remove.begin()]--;
        oddone_to_add.erase(oddone_to_add.begin());
        to_remove.erase(to_remove.begin());
        ans++;
      }
      if (oddone_to_add.size())
      {
        for (int i = n - 1; oddone_to_add.size() > 1 && i >= 0; i--)
        {
          while(x[i] > 2 && oddone_to_add.size() > 1)
          {
            x[i]-=2;
            oddone_to_add.erase(oddone_to_add.begin());
            oddone_to_add.erase(oddone_to_add.begin());
            ans += 2;
          }
        }
        if (oddone_to_add.size())
        {
          printf("-1\n");
        }
        else
        {
          printf("%d\n", ans);
        }
      }
      else
      {
        if (to_remove.size() & 1)
        {
          printf("-1\n");
        }
        else
        {
          ans += to_remove.size() / 2;
          printf("%d\n", ans);
        }
      }
    }
  }
}
