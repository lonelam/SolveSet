<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y;
    bool operator<(const point & rhs) const
    {
        if (x != rhs.x) return x > rhs.x;
        return y < rhs.y;
    }
} ps[500000 + 10], ans[500000 +10];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &ps[i].x, &ps[i].y);
    }
    sort(ps, ps + n);
    for (int i = 0; i < n; i++)
    {
    }
=======
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int n;
struct point
{
  int x, y;
  bool operator<(const point & rhs) const
  {
    if (x != rhs.x) return x > rhs.x;
    return y > rhs.y;
  }
} ps[maxn];



int main()
{
  while(~scanf("%d", &n))
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &ps[i].x, &ps[i].y);
    }
    sort(ps, ps + n);
    int ym = -1;
    vector<point> ans;
    for (int i = 0; i < n; i++)
    {
      if (ps[i].y > ym)
      {
        ans.push_back(ps[i]);
      }
      ym = max(ym, ps[i].y);
    }
    reverse(ans.begin(), ans.end());
    for (point cc: ans)
    {
      printf("%d %d\n", cc.x, cc.y);
    }
  }
>>>>>>> b84c6b080e8b2898f8308513201f7c77babdcb9a
}
