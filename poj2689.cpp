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
const int maxn = 1000000 + 10;
bool nprime[maxn];
ll L, U;
bool seg[maxn];
void init()
{
  nprime[1] = true;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
      for (int j = i + i; j < maxn; j+= i)
      {
        nprime[j] = true;
      }
  }
}
int ps[maxn];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  while(cin >> L >> U)
  {
    int cnt = 0;
    memset(seg, 0, sizeof(seg));
    if (L <= 1) seg[1 - L] = true;
    for (ll i = 2; i * i <= U; i++)
    {
      if (!nprime[i])
      {
        for (ll j = max((L + i - 1) / i * i, i + i); j <= U; j += i)
        {
          seg[j - L] = true;
        }
      }
    }
    for (int i = 0; i <= U - L; i++)
    {
      if (!seg[i]) ps[cnt++] = i + L;
    }
    if (cnt < 2)
    {
      cout << "There are no adjacent primes." << endl;
    }
    else
    {
      int dis[2] = {ps[1] - ps[0], ps[1] - ps[0]};
      int ans[4] = {ps[0], ps[1], ps[0], ps[1]};
      for (int i = 2; i < cnt; i++)
      {
        if (ps[i] - ps[i - 1] > dis[0])
        {
          dis[0] = ps[i] - ps[i - 1];
          ans[2] = ps[i - 1];
          ans[3] = ps[i];
        }
        if (ps[i] - ps[i - 1] < dis[1])
        {
          dis[1] = ps[i] - ps[i - 1];
          ans[1] = ps[i];
          ans[0] = ps[i - 1];
        }
      }
      cout << ans[0] <<","<< ans[1] << " are closest, " << ans[2]<<","<< ans[3]  <<" are most distant." <<endl;
    }
  }
}
/*
2146483647
2147483647
*/
