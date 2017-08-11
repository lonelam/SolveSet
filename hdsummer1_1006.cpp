#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int calc[maxn];
bool visa[maxn], visb[maxn];
const int moder = 1e9 + 7;
int a[maxn], b[maxn];
ll p_m(ll base, ll index)
{
  ll ans = 1;
  while(index)
  {
    if (index & 1)
    {
      ans *= base;
      ans %= moder;
    }
    index >>= 1;
    base *= base;
    base %= moder;
  }
  return ans;
}
int main()
{
//  freopen("/home/lais/Downloads/多校联合训练第一场标程及数据/数据/1006.in", "r", stdin);
  int n, m;
  int kase = 1;
  while(scanf("%d%d", &n, &m) != EOF)
  {
    for (int i = 0; i < n;i ++)
    {
      scanf("%d", a + i);
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d", b + i);
    }
    memset(visa, 0, sizeof(visa));
    memset(visb, 0, sizeof(visb));
    memset(calc, 0, sizeof(calc));
    map<int, int> cycs;
    for (int i = 0; i < n; i++)
    {
      if (!visa[i])
      {
        int p = i;
        int cnt = 0;
        while(!visa[p])
        {
          visa[p] = true;
          cnt++;
          p = a[p];
        }
        cycs[cnt] ++;
      }
    }
    for (int i = 0; i < m; i++)
    {
      if (!visb[i])
      {
        int p = i;
        int cnt = 0;
        while(!visb[p])
        {
          visb[p] = true;
          cnt++;
          p = b[p];
        }
        calc[cnt]++;
      }
    }
    ll ans = 1;
    for (pair<int, int> p: cycs)
    {
      ll base = 0;
  //      if (kase == 35) cout << p.first<< " "<< p.second << endl;
      for (int i = 1; i * i <= p.first; i++)
      {
        if (p.first % i == 0)
        {
          if (i * i != p.first) base += i * calc[i] + p.first / i * calc[p.first / i];
          else base += i * calc[i];
          base %= moder;
        }
      }
      ans *= p_m(base, p.second);
      ans %= moder;
    }
    printf("Case #%d: %lld\n",kase++, ans);
  }
}
