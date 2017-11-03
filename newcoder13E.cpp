#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int C[maxn];
map<int,int> leap;
map<int,deque<int> >Q;
int n, k;
int ans;
int main()
{
  while(~scanf("%d%d", &n, &k))
  {
    ans = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", C + i);
      if (Q.find(C[i]) != Q.end() && !Q[C[i]].empty())
      {
        leap[C[i]] += max(i - Q[C[i]].back() - 1, 0);
      }
      Q[C[i]].push_back(i);
      while(leap[C[i]] > k)
      {
        int tmp = Q[C[i]].front();
        Q[C[i]].pop_front();
        leap[C[i]] -= max(Q[C[i]].front() - tmp - 1, 0);
      }
      ans = max(ans, (int)Q[C[i]].size());
    }
    printf("%d\n", ans);
  }
}
