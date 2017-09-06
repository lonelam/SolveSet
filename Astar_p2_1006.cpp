#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
struct seg
{
  int l, r;
  bool operator<(const seg & rhs) const
  {
    if (r != rhs.r) return r > rhs.r;
    return l > rhs.l;
  }
}ss[maxn];
bool cmp2(const seg & lhs, const seg & rhs)
{
    if (lhs.l != rhs.l) return lhs.l < rhs.l;
    return lhs.r < rhs.r;
}
int n, m;
int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &ss[i].l, &ss[i].r);
      ss[i].r++;
    }
    int L = 0, R = 0;
    priority_queue<seg> Q;
    multiset<int> ls, rs;
    sort(ss, ss + n, cmp2);
    int ans = 0;
    while(R < n)
    {
      if (rs.empty())
      {
        rs.insert(ss[R].r);
        ls.insert(ss[R].l);
        ans = max(ans, ss[R].r - ss[R].l + m);
        Q.push(ss[R]);
        R++;
      }
      else if (ss[R].l <= *rs.rbegin())
      {
        rs.insert(ss[R].r);
        ls.insert(ss[R].l);
        ans = max(*rs.rbegin() - *ls.begin() + m, ans);
        Q.push(ss[R]);
        R++;
      }
      else if (ss[R].l - *rs.rbegin() <= m)
      {
        m -= ss[R].l - *rs.rbegin();
        rs.insert(ss[R].r);
        ls.insert(ss[R].l);
        ans = max(*rs.rbegin() - *ls.begin() + m, ans);
        Q.push(ss[R]);
        R++;
      }
      else
      {
        seg sout = Q.top(); Q.pop();
        ls.erase(ls.find(sout.l));
        rs.erase(rs.find(sout.r));
        if (!ls.empty() && *ls.begin() > sout.r)
        {
          m += *ls.begin() - sout.r;
        }
      }
    }
    printf("%d\n", ans);
  }
}
