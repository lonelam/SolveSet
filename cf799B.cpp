#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;

const int maxn = 200000 + 100;

struct tshirt
{
  int a, b, p;
  bool operator<(const tshirt & rhs) const
  {
    return p < rhs.p;
  }
}ts[maxn];

int main()
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
    set<tshirt> t1, t2, t3;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &ts[i].p);
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &ts[i].a);
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &ts[i].b);
    }
    for (int i = 0; i < n; i++)
    {
      if (ts[i].a == 1 || ts[i].b == 1)
      {
        t1.insert(ts[i]);
      }
      if (ts[i].a == 2 || ts[i].b == 2)
      {
        t2.insert(ts[i]);
      }
      if (ts[i].a == 3 || ts[i].b == 3)
      {
        t3.insert(ts[i]);
      }
    }
    int m, w;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
      scanf("%d", &w);
      if (w == 1 && !t1.empty())
      {
        printf("%d ", t1.begin()->p);
        if (t2.find(*t1.begin()) != t2.end()) t2.erase(*t1.begin());
        if (t3.find(*t1.begin()) != t3.end()) t3.erase(*t1.begin());
        t1.erase(t1.begin());
      }
      else if (w == 2 && !t2.empty())
      {
        if (t3.find(*t2.begin()) != t3.end()) t3.erase(*t2.begin());
        if (t1.find(*t2.begin()) != t1.end()) t1.erase(*t2.begin());
        printf("%d ", t2.begin()->p);
        t2.erase(t2.begin());
      }
      else if (w == 3 && !t3.empty())
      {
        printf("%d ", t3.begin()->p);
        if (t2.find(*t3.begin()) != t2.end()) t2.erase(*t3.begin());
        if (t1.find(*t3.begin()) != t1.end()) t1.erase(*t3.begin());
        t3.erase(t3.begin());
      }
      else
      {
        printf("-1 ");
      }
    }
    printf("\n");
  }
}
