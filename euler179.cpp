#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000000;
int ptot;
bool nprime[maxn];
int primes[maxn];
void init()
{
  nprime[1] = true;
  for (int i = 2;i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[ptot++] = i;
    }
    for (int j = 0; j < ptot && primes[j] * i < maxn; j++)
    {
      nprime[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}
const int maxk = 1e7 + 100;
int fcnt[maxk];
void dfs(int preduct, int j, int pre_choice)
{
  preduct *= primes[j];
  int cnt = 2;
  while(true)
  {
    fcnt[preduct] = cnt * pre_choice;
    for (int p = j + 1; p < ptot && (ll)preduct * (ll)primes[p] < (ll)maxk; p++)
    {
      dfs(preduct, p, pre_choice * cnt);
    }
    if ((ll)preduct * (ll)primes[j] >= (ll)maxk)
    {
      break;
    }
    preduct *= primes[j];
    cnt++;
  }
}
int ans[maxk];
int main()
{
  init();
  for (int i = 0; i < ptot; i++)
  {
    dfs(1, i, 1);
  }
  int pre = 2;
  ans[2] = 0;
  for (int i = 3; i < maxk; i++)
  {
    if (!fcnt[i]) fcnt[i] = 2;
    if (fcnt[i] == pre)
    {
      ans[i] = ans[i-1] + 1;
    }
    else
    {
      ans[i] = ans[i-1];
    }
    pre = fcnt[i];
  }
  int T;
  scanf("%d", &T);
  int k;
  while(T--)
  {
    scanf("%d", &k);
    printf("%d\n", ans[k]);
  }
}
