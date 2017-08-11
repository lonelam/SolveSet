#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int T;
ll k;
int w;
ll dp[5][maxn];
bool inq[5][maxn];
int d[5];
typedef pair<int,int> pii;
void spfa()
{
  queue<pii> Q;
  memset(dp, 0x3f, sizeof(dp));
  memset(inq, 0, sizeof(inq));
  dp[1][0] = 0;
  Q.push({1, 0});
  inq[1][0] = true;
  while(!Q.empty())
  {
    pii cur = Q.front(); Q.pop();
    // cout << cur.first << " "<< cur.second << endl;
    // cout << dp[cur.first][cur.second] << endl;
    inq[cur.first][cur.second ] = false;
    int tp = (cur.first + 1) % 4, td = (dp[cur.first][cur.second] + d[cur.first]);
    if (dp[tp][td % w] > td)
    {
      dp[tp][td % w] = td;
      if (!inq[tp][td%w])
      {
        inq[tp][td % w] = true;
        Q.push({tp, td % w});
      }
    }
    tp = (cur.first + 3) % 4, td = (dp[cur.first][cur.second] + d[tp]);

    if (dp[tp][td % w] > td)
    {
      dp[tp][td % w] = td;
      if (!inq[tp][td % w])
      {
        inq[tp][td % w] = true;
        Q.push({tp, td % w});
      }
    }
  }
}
int main()
{
  scanf("%d", &T);
  while(T--)
  {
    scanf("%lld", &k);
    for (int i = 0; i < 4; i++)
    {
      scanf("%d", d + i);
    }
    w = 2 * min(d[0], d[1]);
    spfa();
    ll ans = k + w;
    for (int i = 0; i < w; i++)
    {
      if (k > dp[1][i]) dp[1][i] += (k - dp[1][i] + w - 1) / w * w;
      // cout << dp[2][i] << endl;
      ans = min(ans, dp[1][i]);
    }
    printf("%lld\n", ans);
  }

}
