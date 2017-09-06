#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50;
ll n, k, M;
ll vis[maxn];
ll sub[maxn];
ll presum[maxn];
ll cnt;
ll rem;
map<int,int> Q;
bool elim()
{
    if (Q.empty()) return false;
    int tail = Q.rbegin()->first;
    for (int i = 0; i <= tail; i++)
    {
      if (Q.empty()) return false;
      Q[i]--;
      if (!Q[i])
      {
        Q.erase(i);
      }
    }
    ll tailsum = presum[k-1] - presum[tail];
    rem -= tailsum;
    ll tailcnt = k - tail;
    cnt += tailcnt;
    ll cutsum = 0;
    // for (int i = 1; i < tailcnt; i++)
    while(rem < 0)
    {
      if (Q.empty()) return false;
      int tar = Q.rbegin()->first;
      cnt--;
      rem += sub[tar];
      // cutsum += sub[tar];
      if (--Q[tar] == 0)
      {
        Q.erase(tar);
      }
    }
    // rem += cutsum;
    // rem -= tailsum;
    if (rem < 0) return false;
    // cnt++;
    return true;
}
ll ans;
void solve()
{
  cnt = 0;
  rem = M;
  ans = 0;
  sort(sub, sub + k);
  presum[0] = sub[0];
  for (int i = 1; i < k; i++)
  {
    presum[i] = presum[i-1] + sub[i];
  }
  for (int i = 0; i < k; i++)
  {
    ll d = min(n, rem / sub[i]);
    if (d) Q[i] = d;
    rem -= d * sub[i];
    cnt += d;
  }
  ans = cnt;
  while(elim())
  {
    ans = max(ans, cnt);
  }
}
int main()
{
  cin >> n >> k >> M;
  for (int i = 0; i < k; i++)
  {
    cin >> sub[i];
  }
  solve();
  cout << ans << endl;
}
