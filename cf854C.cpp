#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
// struct fly
// {
//   int c, t;
// };
typedef pair<int,int> pii;
pii fly[maxn];
int ans[maxn];
int main()
{
  int k, n;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &fly[i].first);
    fly[i].second = i;
  }
  priority_queue<pii> Q;
  for (int i = 1; i <= k; i++)
  {
    Q.push(fly[i]);
  }
  ll acc = 0;
  for (int i = k + 1; i <= k + n; i++)
  {
    if (i <= n)
    {
      Q.push(fly[i]);
    }
    pii cur = Q.top();
    Q.pop();
    acc += (ll)cur.first *(ll) (i-cur.second );
    ans[cur.second] = i;
  }
  printf("%lld\n", acc);
  for (int i = 1; i <= n; i++)
  {
    printf("%d%c", ans[i], i==n?'\n':' ');
  }
}
