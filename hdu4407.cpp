#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxm = 1000 + 10;
const int maxn = 400000;
int cmd[maxm], x[maxm], y[maxm], p[maxm];
ll ans[maxm];
int n, m;
map<int, int> modified;
int primes[maxn], nprime[maxn];
int tot = 0;
void init()
{
  nprime[1] = 1;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[tot++] = i;
    }
    for (int j = 0; j < tot && primes[j] * i < maxn; j++)
    {
      nprime[primes[j] * i] = 1;
      if (i % primes[j] == 0)
      {
        break;
      }
    }
  }

}
void calc(int id)
{
  ans[id] = (ll)(y[id] - x[id] + 1) * (ll)(x[id] + y[id]) / 2LL;
  int tmp = p[id];
  vector<int> ps;
  for (int i = 0; i < tot && primes[i] * primes[i] <= tmp; i++)
  {
    if (tmp % primes[i] == 0)
    {
      while(tmp % primes[i] == 0)
      {
        tmp /= primes[i];
      }
      ps.push_back(primes[i]);
    }
  }
  if (tmp != 1)
  {
    ps.push_back(tmp);
  }
  for (int s = (1 << ps.size()) - 1; s >= 1; s--)
  {
    int cnt = 0;
    int pro = 1;
    for (int j = 0; j < ps.size(); j++)
    {
      if (s >> j & 1)
      {
        cnt++;
        pro *= ps[j];
      }
    }
    ll lone = (x[id] + pro - 1) / pro , rone = (y[id] / pro);
    ll tsum = 0;
    if (lone <= rone)
    {
      tsum = (ll) (lone + rone) * (ll)(rone - lone + 1) / 2LL * (ll)pro;
    }
    if (cnt & 1) ans[id] -= tsum;
    else ans[id] += tsum;
  }
}
int main()
{
  int T;
  init();
  while(scanf("%d", &T) != EOF)
  while(T--)
  {
    scanf("%d%d", &n, &m);
    modified.clear();
    for (int i = 0; i < m; i++)
    {
      scanf("%d", cmd + i);
      if (cmd[i] == 1)
      {
        scanf("%d%d%d", x + i, y + i, p + i);
        calc(i);
      }
      else if (cmd[i] == 2)
      {
        scanf("%d%d", x + i, y + i);
      }
    }
    for (int i = 0; i < m; i++)
    {
      if (cmd[i] == 1)
      {
        printf("%lld\n", ans[i]);
      }
      else if (cmd[i] == 2)
      {
        if (modified.find(x[i]) == modified.end())
        {
          modified[x[i]] = x[i];
        }
        for (int j = i + 1; j < m; j++)
        {
          if (cmd[j] == 1 && x[j] <= x[i] && x[i] <= y[j])
          {
            if (__gcd(modified[x[i]], p[j]) == 1)
            {
              ans[j] -= modified[x[i]];
            }
            if (__gcd(y[i], p[j]) == 1)
            {
              ans[j] += y[i];
            }
          }
        }
        modified[x[i]] = y[i];
      }
    }
  }
}

/*

1
130 5
1 1 130 26
2 13 58
1 1 130 39
1 39 130 130
1 41 141 1
*/
